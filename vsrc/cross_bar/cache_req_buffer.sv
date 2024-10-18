module cache_req_buffer
#(
  parameter QUEUE_DEPTH = 5;
)(
    input  logic cache_req_valid_i,
    output logic cache_req_allowIn_o,
    input  logic last_entry_already_pop
);

  logic queue_push;
  logic queue_pop;
  logic queue_has_valid_entry;

  logic [AW-1:0] write_ptr_In;
  logic [AW-1:0] write_ptr_Q;

  logic [AW-1:0] read_ptr_In;
  logic [AW-1:0] read_ptr_Q;

  logic [DW-1:0] req_queue_In;
  logic [DW-1:0] req_queue_Q;

  assign queue_push = cache_req_valid_i & cache_req_allowIn_o;

  assign queue_has_valid_entry = queue_cnt_Q != 'd0;

  assign queue_pop = queue_has_valid_entry & last_entry_already_pop;

  assign write_ptr_In = write_ptr_Q == QUEUE_DEPTH - 1
                      ? 'd0
                      : write_ptr_Q + 'd1;

  assign read_ptr_In = read_ptr_Q == QUEUE_DEPTH - 1
                     ? 'd0
                     : read_ptr_Q + 'd1;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      write_ptr_Q <= 'd0;
    end
    else if(queue_push) begin
      write_ptr_Q <= write_ptr_In;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      read_ptr_Q <= 'd0;
    end
    else if (queue_pop) begin
      read_ptr_Q <= read_ptr_In;
    end
  end

  assign queue_cnt_In =  queue_push & ~queue_pop ? queue_cnt_Q + 'd1
                      : ~queue_push &  queue_pop ? queue_cnt_Q - 'd1
                      : queue_cnt_Q;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      queue_cnt_Q <= 'd0;
    end
    else begin
      queue_cnt_Q <= queue_cnt_In;
    end
  end

  always_comb begin
    req_queue_In = req_queue_Q;
    if (queue_push) begin
      queue_cnt_In[write_ptr_Q] = cache_req_i;
    end
  end


endmodule