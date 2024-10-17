module sparse_buffer #(
  parameter DW   = 8,
  parameter AW   = 3,
  parameter SIZE = 8
)(
  input  logic            clk_i,
  input  logic            rstn_i,
  // Write ports
  input  logic            write_valid_i,
  output logic            write_allowIn_o,
  input  logic [DW-1:0]   write_data_i,
  // Read ports
  input  logic            read_valid_i,
  output logic            read_allowIn_o,
  input  logic [AW-1:0]   read_ptr_i,
  // Read data return ports
  output logic            read_rtn_valid_o,
  input  logic            read_rtn_allowIn_i,
  output logic [DW-1:0]   read_rtn_data_o,
  // Buffer state ports
  output logic [SIZE-1:0] sparse_buffer_valid_o,
  output logic [AW-1:0]   sparse_buffer_bottom_ptr_o
);

  logic [DW-1:0]   sparse_array_In [SIZE-1:0];
  logic [DW-1:0]   sparse_array_Q  [SIZE-1:0];

  logic [SIZE-1:0] sparse_array_valid_In;
  logic [SIZE-1:0] sparse_array_valid_Q;

  logic            write_kickoff;
  logic [AW-1:0]   write_ptr_In;
  logic [AW-1:0]   write_ptr_Q;

  logic            read_kickoff;

  logic [AW-1:0]   bottom_ptr_In;
  logic [AW-1:0]   bottom_ptr_Q;

//---------------------------------------------------------
//                    update write ptr
//---------------------------------------------------------
  assign write_allowIn_o = write_ptr_Q != bottom_ptr_Q;
  assign write_ptr_In = write_ptr_Q + 'd1;
  assign write_kickoff = write_valid_i & write_allowIn_o;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      write_ptr_Q <= '0;
    end
    else if (write_kickoff) begin
      write_ptr_Q <= write_ptr_In;
    end
  end

//---------------------------------------------------------
//                update sparse array
//---------------------------------------------------------
  always_comb begin
    sparse_array_In = sparse_array_Q;
    if (write_kickoff) begin
      sparse_array_In[write_ptr_Q] = write_data_i; 
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      sparse_array_Q <= '{default: 'd0};
    end
    else begin
      sparse_array_Q <= sparse_array_In;
    end
  end

//---------------------------------------------------------
//                update sparse array valid
//---------------------------------------------------------
  always_comb begin
    sparse_array_valid_In = sparse_array_valid_Q;
    if (write_kickoff) begin
      sparse_array_valid_In[write_ptr_Q] = 1'b1;
    end
    if (read_kickoff) begin
      sparse_array_valid_In[read_ptr_i] = 1'b0;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      sparse_array_valid_Q <= '0;
    end
    else begin
      sparse_array_valid_Q <= sparse_array_valid_In;
    end
  end

  assign sparse_buffer_valid_o = sparse_array_valid_Q;

  assign sparse_buffer_bottom_ptr_o = bottom_ptr_Q;

//---------------------------------------------------------
//                         read
//---------------------------------------------------------
  assign read_kickoff = read_valid_i & read_allowIn_o;
  assign read_allowIn_o = read_rtn_allowIn_i;

  assign read_rtn_valid_o = read_valid_i
                          ? sparse_array_valid_Q[read_ptr_i]
                          : 1'b0;

  assign read_rtn_data_o = read_valid_i
                         ? sparse_array_Q[read_ptr_i]
                         : 'd0;

//---------------------------------------------------------
//                update bottom ptr
//---------------------------------------------------------

  // Note: this implement is only for 8 Entry.
  fid_bottom_ptr_impl u_fid_bottom_ptr_impl(  
    .entry_valid_i      ( sparse_array_valid_Q[7:0] ),
    .bottom_ptr_current ( bottom_ptr_Q[2:0]         ),
    .bottom_ptr_next    ( bottom_ptr_In[2:0]        )
  );

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      bottom_ptr_Q <= 'd7;
    end
    else begin
      bottom_ptr_Q <= bottom_ptr_In;
    end
  end

endmodule