module cross_bar_top(
  input  logic clk_i,
  input  logic rstn_i,
  input  logic ch0_req_valid_i,
  output logic ch0_req_allowIn_o,
  input  logic ch0_req_i
);

// Channel Bank Mapping
  logic [1:0] ch0_bank_map;
  logic [1:0] ch1_bank_map;
  logic [1:0] ch2_bank_map;

  assign ch0_bank_map[1:0] = addr[1:0];
  assign ch1_bank_map[1:0] = addr[1:0];
  assign ch2_bank_map[1:0] = addr[1:0];


  logic [AW-1:0] ch0_write_ptr_In;
  logic [AW-1:0] ch0_write_ptr_Q;
  logic [AW-1:0] ch1_write_ptr_In;
  logic [AW-1:0] ch1_write_ptr_Q;
  logic [AW-1:0] ch2_write_ptr_In;
  logic [AW-1:0] ch2_write_ptr_Q;

  logic [AW-1:0] ch0_read_ptr_In;
  logic [AW-1:0] ch0_read_ptr_Q;
  logic [AW-1:0] ch1_read_ptr_In;
  logic [AW-1:0] ch1_read_ptr_Q;
  logic [AW-1:0] ch2_read_ptr_In;
  logic [AW-1:0] ch2_read_ptr_Q;

  // Req Mark Array
  // Array[channel][bank][entry]
  logic cbe_array_valid_In [2:0][3:0][4:0];
  logic cbe_array_valid_Q  [2:0][3:0][4:0];


//=============================================================
//                         Channel 0
//=============================================================
  assign ch0_buffer_has_valid_entry = ch0_buffer_cnt_Q != 'd0;

  assign ch0_req_push = ch0_req_valid_i & ch0_req_allowIn_o;

  assign ch0_req_pop = ch0_buffer_has_valid_entry & ch0_last_entry_already_pop;

  assign ch0_write_ptr_In = ch0_write_ptr_Q == QUEUE_DEPTH - 1
                          ? 'd0
                          : ch0_write_ptr_Q + 'd1;

  assign ch0_read_ptr_In = ch0_read_ptr_Q == QUEUE_DEPTH - 1
                         ? 'd0
                         : ch0_read_ptr_Q + 'd1;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch0_write_ptr_Q <= 'd0;
    end
    else if(ch0_req_push) begin
      ch0_write_ptr_Q <= ch0_write_ptr_In;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch0_read_ptr_Q <= 'd0;
    end
    else if (ch0_req_pop) begin
      ch0_read_ptr_Q <= ch0_read_ptr_In;
    end
  end

  always_comb begin
    cbe_array_valid_In[0][0][4:0] = cbe_array_valid_In[0][0][4:0]; // bank 0
    cbe_array_valid_In[0][1][4:0] = cbe_array_valid_In[0][1][4:0]; // bank 1
    cbe_array_valid_In[0][2][4:0] = cbe_array_valid_In[0][2][4:0]; // bank 2
    cbe_array_valid_In[0][3][4:0] = cbe_array_valid_In[0][3][4:0]; // bank 3

    if (ch0_req_push) begin
      cbe_array_valid_In[0][ch0_bank_map][ch0_write_ptr_Q] = 1'b1;
    end

  end

  // Channel0 读指针指向的 entry 无有效请求
  assign ch0_last_entry_already_pop = ~(  cbe_array_valid_Q[0][0][ch0_read_ptr_Q] // bank0 has valid req
                                        | cbe_array_valid_Q[0][1][ch0_read_ptr_Q] // bank1 has valid req
                                        | cbe_array_valid_Q[0][2][ch0_read_ptr_Q] // bank2 has valid req 
                                        | cbe_array_valid_Q[0][3][ch0_read_ptr_Q] // bank3 has valid req
                                       );

  logic ch0_want_send_to_bank0;
  logic ch0_want_send_to_bank1;
  logic ch0_want_send_to_bank2;
  logic ch0_want_send_to_bank3;

  logic ch1_want_send_to_bank0;
  logic ch1_want_send_to_bank1;
  logic ch1_want_send_to_bank2;
  logic ch1_want_send_to_bank3;

  logic ch2_want_send_to_bank0;
  logic ch2_want_send_to_bank1;
  logic ch2_want_send_to_bank2;
  logic ch2_want_send_to_bank3;

  logic [2:0] ch0_entryId_want_send_to_bank0;
  logic [2:0] ch0_entryId_want_send_to_bank1;
  logic [2:0] ch0_entryId_want_send_to_bank2;
  logic [2:0] ch0_entryId_want_send_to_bank3;

  assign ch0_want_send_to_bank0 = |cbe_array_valid_Q[0][0][4:0];
  assign ch0_want_send_to_bank1 = |cbe_array_valid_Q[0][1][4:0];
  assign ch0_want_send_to_bank2 = |cbe_array_valid_Q[0][2][4:0];
  assign ch0_want_send_to_bank3 = |cbe_array_valid_Q[0][3][4:0];

  round_robin
  ch0_bank0_rr(
    .entry_valid_i (cbe_array_valid_Q[0][0][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q              ),
    .first_ptr_o   (ch0_entryId_send_to_bank0   )
  );

  round_robin
  ch0_bank1_rr(
    .entry_valid_i (cbe_array_valid_Q[0][1][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q              ),
    .first_ptr_o   (ch0_entryId_send_to_bank1   )
  );

  round_robin
  ch0_bank2_rr(
    .entry_valid_i (cbe_array_valid_Q[0][2][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q              ),
    .first_ptr_o   (ch0_entryId_send_to_bank2   )
  );

  round_robin
  ch0_bank3_rr(
    .entry_valid_i (cbe_array_valid_Q[0][3][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q              ),
    .first_ptr_o   (ch0_entryId_send_to_bank3   )
  );



endmodule