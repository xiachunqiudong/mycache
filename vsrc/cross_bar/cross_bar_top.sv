module cross_bar_top #(
  parameter BUFFER_SIZE = 5,
  parameter AW          = 3
) (
  input  logic       clk_i,
  input  logic       rstn_i,
  input  logic       ch0_req_valid_i,
  output logic       ch0_req_allowIn_o,
  input  logic [1:0] ch0_req_addr_i,
  input  logic       ch1_req_valid_i,
  output logic       ch1_req_allowIn_o,
  input  logic [1:0] ch1_req_addr_i,
  input  logic       ch2_req_valid_i,
  output logic       ch2_req_allowIn_o,
  input  logic [1:0] ch2_req_addr_i,
);

  logic [1:0] ch0_bank_map;
  logic [1:0] ch1_bank_map;
  logic [1:0] ch2_bank_map;

//---------------Chnnel0 Signal---------------//
  logic          ch0_req_push;
  logic          ch0_req_pop;
  logic          ch0_buffer_has_valid_entry;
  logic          ch0_last_entry_already_pop;
  logic [AW-1:0] ch0_write_ptr_In;
  logic [AW-1:0] ch0_write_ptr_Q;
  logic [AW-1:0] ch0_read_ptr_In;
  logic [AW-1:0] ch0_read_ptr_Q;
  loigc [AW:0]   ch0_buffer_cnt_In;
  loigc [AW:0]   ch0_buffer_cnt_Q;
  logic          ch0_bank_req_array_valid_In   [3:0][4:0];
  logic          ch0_bank_req_array_valid_Q    [3:0][4:0];
  logic          ch0_bank_req_array_invalidate [3:0][4:0];

  logic          ch0_want_send_to_bank0;
  logic          ch0_want_send_to_bank1;
  logic          ch0_want_send_to_bank2;
  logic          ch0_want_send_to_bank3;
  logic [2:0]    ch0_entryId_want_send_to_bank0;
  logic [2:0]    ch0_entryId_want_send_to_bank1;
  logic [2:0]    ch0_entryId_want_send_to_bank2;
  logic [2:0]    ch0_entryId_want_send_to_bank3;

//---------------Chnnel1 Signal---------------//
  logic          ch1_req_push;
  logic          ch1_req_pop;
  logic          ch1_buffer_has_valid_entry;
  logic          ch1_last_entry_already_pop;
  logic [AW-1:0] ch1_write_ptr_In;
  logic [AW-1:0] ch1_write_ptr_Q;
  logic [AW-1:0] ch1_read_ptr_In;
  logic [AW-1:0] ch1_read_ptr_Q;
  loigc [AW:0]   ch1_buffer_cnt_In;
  loigc [AW:0]   ch1_buffer_cnt_Q;
  logic          ch1_bank_req_array_valid_In   [3:0][4:0];
  logic          ch1_bank_req_array_valid_Q    [3:0][4:0];
  logic          ch1_bank_req_array_invalidate [3:0][4:0];

  logic          ch1_want_send_to_bank0;
  logic          ch1_want_send_to_bank1;
  logic          ch1_want_send_to_bank2;
  logic          ch1_want_send_to_bank3;
  logic [2:0]    ch1_entryId_want_send_to_bank0;
  logic [2:0]    ch1_entryId_want_send_to_bank1;
  logic [2:0]    ch1_entryId_want_send_to_bank2;
  logic [2:0]    ch1_entryId_want_send_to_bank3;

//---------------Chnnel2 Signal---------------//
  logic          ch2_req_push;
  logic          ch2_req_pop;
  logic          ch2_buffer_has_valid_entry;
  logic          ch2_last_entry_already_pop;
  logic [AW-1:0] ch2_write_ptr_In;
  logic [AW-1:0] ch2_write_ptr_Q;
  logic [AW-1:0] ch2_read_ptr_In;
  logic [AW-1:0] ch2_read_ptr_Q;
  loigc [AW:0]   ch2_buffer_cnt_In;
  loigc [AW:0]   ch2_buffer_cnt_Q;
  logic          ch2_bank_req_array_valid_In   [3:0][4:0];
  logic          ch2_bank_req_array_valid_Q    [3:0][4:0];
  logic          ch2_bank_req_array_invalidate [3:0][4:0];

  logic          ch2_want_send_to_bank0;
  logic          ch2_want_send_to_bank1;
  logic          ch2_want_send_to_bank2;
  logic          ch2_want_send_to_bank3;
  logic [2:0]    ch2_entryId_want_send_to_bank0;
  logic [2:0]    ch2_entryId_want_send_to_bank1;
  logic [2:0]    ch2_entryId_want_send_to_bank2;
  logic [2:0]    ch2_entryId_want_send_to_bank3;

//---------------Bank Signal---------------//
  logic [2:0] bank0_channel_req_array;
  logic [2:0] bank1_channel_req_array;
  logic [2:0] bank2_channel_req_array;
  logic [2:0] bank3_channel_req_array;

  logic [1:0] bank0_channel_req_id;
  logic [1:0] bank1_channel_req_id;
  logic [1:0] bank2_channel_req_id;
  logic [1:0] bank3_channel_req_id;

// Channel Bank Mapping
  assign ch0_bank_map[1:0] = ch0_req_addr_i[1:0];
  assign ch1_bank_map[1:0] = ch1_req_addr_i[1:0];
  assign ch2_bank_map[1:0] = ch2_req_addr_i[1:0];

//=============================================================
//            Channel Bank Entry Mark Array
// number of channle : 3
// number of bank    : 4
// number of entry   : 5
//=============================================================

//-------------------------------------------------------------
//                         Channel 0
//-------------------------------------------------------------
  assign ch0_buffer_has_valid_entry = ch0_buffer_cnt_Q != 'd0;

  assign ch0_req_allowIn_o = ch0_buffer_cnt_Q != BUFFER_SIZE;

  assign ch0_req_push = ch0_req_valid_i & ch0_req_allowIn_o;

  // Channel0 读指针指向的 entry 无有效请求 (4 个 bank 都无有效请求)
  assign ch0_last_entry_already_pop = ~(  ch0_bank_req_array_valid_Q[0][ch0_read_ptr_Q] // bank0 has valid req
                                        | ch0_bank_req_array_valid_Q[1][ch0_read_ptr_Q] // bank1 has valid req
                                        | ch0_bank_req_array_valid_Q[2][ch0_read_ptr_Q] // bank2 has valid req 
                                        | ch0_bank_req_array_valid_Q[3][ch0_read_ptr_Q] // bank3 has valid req
                                       );

  assign ch0_req_pop = ch0_buffer_has_valid_entry & ch0_last_entry_already_pop;

  assign ch0_write_ptr_In = ch0_write_ptr_Q == BUFFER_SIZE - 1
                          ? 'd0
                          : ch0_write_ptr_Q + 'd1;

  assign ch0_read_ptr_In = ch0_read_ptr_Q == BUFFER_SIZE - 1
                         ? 'd0
                         : ch0_read_ptr_Q + 'd1;

  assign ch0_buffer_cnt_In =  ch0_req_push & ~ch0_req_pop ? ch0_buffer_cnt_Q + 'd1
                           : ~ch0_req_push &  ch0_req_pop ? ch0_buffer_cnt_Q - 'd1
                           :                                ch0_buffer_cnt_Q;

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

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch0_buffer_cnt_Q <= 'd0;
    end
    else begin
      ch0_buffer_cnt_Q <= ch0_buffer_cnt_In;
    end
  end

  assign ch0_bank_req_array_invalidate[0][ch0_entryId_want_send_to_bank0] = (bank0_channel_req_id[1:0] == 2'd0) 
                                                                          & ch0_want_send_to_bank0;

  assign ch0_bank_req_array_invalidate[1][ch0_entryId_want_send_to_bank1] = (bank1_channel_req_id[1:0] == 2'd0) 
                                                                          & ch0_want_send_to_bank1;

  assign ch0_bank_req_array_invalidate[2][ch0_entryId_want_send_to_bank2] = (bank2_channel_req_id[1:0] == 2'd0) 
                                                                          & ch0_want_send_to_bank2;

  assign ch0_bank_req_array_invalidate[3][ch0_entryId_want_send_to_bank3] = (bank3_channel_req_id[1:0] == 2'd0) 
                                                                          & ch0_want_send_to_bank3;

  always_comb begin
    ch0_bank_req_array_valid_In[0][4:0] = ch0_bank_req_array_valid_Q[0][4:0] & ~ch0_bank_req_array_invalidate[0][4:0]; // bank 0
    ch0_bank_req_array_valid_In[1][4:0] = ch0_bank_req_array_valid_Q[1][4:0] & ~ch0_bank_req_array_invalidate[0][4:0]; // bank 1
    ch0_bank_req_array_valid_In[2][4:0] = ch0_bank_req_array_valid_Q[2][4:0] & ~ch0_bank_req_array_invalidate[0][4:0]; // bank 2
    ch0_bank_req_array_valid_In[3][4:0] = ch0_bank_req_array_valid_Q[3][4:0] & ~ch0_bank_req_array_invalidate[0][4:0]; // bank 3

    if (ch0_req_push) begin
      ch0_bank_req_array_valid_In[ch0_bank_map][ch0_write_ptr_Q] = 1'b1;
    end

  end

//-------------------------------------------------------------
//                         Channel 1
//-------------------------------------------------------------
  assign ch1_buffer_has_valid_entry = ch1_buffer_cnt_Q != 'd0;

  assign ch1_req_allowIn_o = ch1_buffer_cnt_Q != BUFFER_SIZE;

  assign ch1_req_push = ch1_req_valid_i & ch1_req_allowIn_o;

  // Channel0 读指针指向的 entry 无有效请求 (4 个 bank 都无有效请求)
  assign ch1_last_entry_already_pop = ~(  ch1_bank_req_array_valid_Q[0][ch1_read_ptr_Q] // bank0 has valid req
                                        | ch1_bank_req_array_valid_Q[1][ch1_read_ptr_Q] // bank1 has valid req
                                        | ch1_bank_req_array_valid_Q[2][ch1_read_ptr_Q] // bank2 has valid req 
                                        | ch1_bank_req_array_valid_Q[3][ch1_read_ptr_Q] // bank3 has valid req
                                       );

  assign ch1_req_pop = ch1_buffer_has_valid_entry & ch1_last_entry_already_pop;

  assign ch1_write_ptr_In = ch1_write_ptr_Q == BUFFER_SIZE - 1
                          ? 'd0
                          : ch1_write_ptr_Q + 'd1;

  assign ch1_read_ptr_In = ch1_read_ptr_Q == BUFFER_SIZE - 1
                         ? 'd0
                         : ch1_read_ptr_Q + 'd1;

  assign ch1_buffer_cnt_In =  ch1_req_push & ~ch1_req_pop ? ch1_buffer_cnt_Q + 'd1
                           : ~ch1_req_push &  ch1_req_pop ? ch1_buffer_cnt_Q - 'd1
                           :                                ch1_buffer_cnt_Q;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch1_write_ptr_Q <= 'd0;
    end
    else if(ch1_req_push) begin
      ch1_write_ptr_Q <= ch1_write_ptr_In;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch1_read_ptr_Q <= 'd0;
    end
    else if (ch1_req_pop) begin
      ch1_read_ptr_Q <= ch1_read_ptr_In;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch1_buffer_cnt_Q <= 'd0;
    end
    else begin
      ch1_buffer_cnt_Q <= ch1_buffer_cnt_In;
    end
  end

  assign ch1_bank_map[1:0] = ch1_req_addr_i[1:0];

  assign ch1_bank_req_array_invalidate[0][ch1_entryId_want_send_to_bank0] = (bank0_channel_req_id[1:0] == 2'd1) 
                                                                          & ch1_want_send_to_bank0;

  assign ch1_bank_req_array_invalidate[1][ch1_entryId_want_send_to_bank1] = (bank1_channel_req_id[1:0] == 2'd1) 
                                                                          & ch1_want_send_to_bank1;

  assign ch1_bank_req_array_invalidate[2][ch1_entryId_want_send_to_bank2] = (bank2_channel_req_id[1:0] == 2'd1) 
                                                                          & ch1_want_send_to_bank2;

  assign ch1_bank_req_array_invalidate[3][ch1_entryId_want_send_to_bank3] = (bank3_channel_req_id[1:0] == 2'd1) 
                                                                          & ch1_want_send_to_bank3;

  always_comb begin
    ch1_bank_req_array_valid_In[0][4:0] = ch1_bank_req_array_valid_Q[0][4:0] & ~ch1_bank_req_array_invalidate[0][4:0]; // bank 0
    ch1_bank_req_array_valid_In[1][4:0] = ch1_bank_req_array_valid_Q[1][4:0] & ~ch1_bank_req_array_invalidate[0][4:0]; // bank 1
    ch1_bank_req_array_valid_In[2][4:0] = ch1_bank_req_array_valid_Q[2][4:0] & ~ch1_bank_req_array_invalidate[0][4:0]; // bank 2
    ch1_bank_req_array_valid_In[3][4:0] = ch1_bank_req_array_valid_Q[3][4:0] & ~ch1_bank_req_array_invalidate[0][4:0]; // bank 3

    if (ch1_req_push) begin
      ch1_bank_req_array_valid_In[ch1_bank_map][ch1_write_ptr_Q] = 1'b1;
    end

  end

//-------------------------------------------------------------
//                         Channel 2
//-------------------------------------------------------------
  assign ch2_buffer_has_valid_entry = ch2_buffer_cnt_Q != 'd0;

  assign ch2_req_allowIn_o = ch2_buffer_cnt_Q != BUFFER_SIZE;

  assign ch2_req_push = ch2_req_valid_i & ch2_req_allowIn_o;

  // Channel0 读指针指向的 entry 无有效请求 (4 个 bank 都无有效请求)
  assign ch2_last_entry_already_pop = ~(  ch2_bank_req_array_valid_Q[0][ch2_read_ptr_Q] // bank0 has valid req
                                        | ch2_bank_req_array_valid_Q[1][ch2_read_ptr_Q] // bank1 has valid req
                                        | ch2_bank_req_array_valid_Q[2][ch2_read_ptr_Q] // bank2 has valid req 
                                        | ch2_bank_req_array_valid_Q[3][ch2_read_ptr_Q] // bank3 has valid req
                                       );

  assign ch2_req_pop = ch2_buffer_has_valid_entry & ch2_last_entry_already_pop;

  assign ch2_write_ptr_In = ch2_write_ptr_Q == BUFFER_SIZE - 1
                          ? 'd0
                          : ch2_write_ptr_Q + 'd1;

  assign ch2_read_ptr_In = ch2_read_ptr_Q == BUFFER_SIZE - 1
                         ? 'd0
                         : ch2_read_ptr_Q + 'd1;

  assign ch2_buffer_cnt_In =  ch2_req_push & ~ch2_req_pop ? ch2_buffer_cnt_Q + 'd1
                           : ~ch2_req_push &  ch2_req_pop ? ch2_buffer_cnt_Q - 'd1
                           :                                ch2_buffer_cnt_Q;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch2_write_ptr_Q <= 'd0;
    end
    else if(ch2_req_push) begin
      ch2_write_ptr_Q <= ch2_write_ptr_In;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch2_read_ptr_Q <= 'd0;
    end
    else if (ch2_req_pop) begin
      ch2_read_ptr_Q <= ch2_read_ptr_In;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      ch2_buffer_cnt_Q <= 'd0;
    end
    else begin
      ch2_buffer_cnt_Q <= ch2_buffer_cnt_In;
    end
  end

  assign ch2_bank_map[1:0] = ch2_req_addr_i[1:0];

  assign ch2_bank_req_array_invalidate[0][ch2_entryId_want_send_to_bank0] = (bank0_channel_req_id[1:0] == 2'd2) 
                                                                          & ch2_want_send_to_bank0;

  assign ch2_bank_req_array_invalidate[1][ch2_entryId_want_send_to_bank1] = (bank1_channel_req_id[1:0] == 2'd2) 
                                                                          & ch2_want_send_to_bank1;

  assign ch2_bank_req_array_invalidate[2][ch2_entryId_want_send_to_bank2] = (bank2_channel_req_id[1:0] == 2'd2) 
                                                                          & ch2_want_send_to_bank2;

  assign ch2_bank_req_array_invalidate[3][ch2_entryId_want_send_to_bank3] = (bank3_channel_req_id[1:0] == 2'd2) 
                                                                          & ch2_want_send_to_bank3;

  always_comb begin
    ch2_bank_req_array_valid_In[0][4:0] = ch2_bank_req_array_valid_Q[0][4:0] & ~ch2_bank_req_array_invalidate[0][4:0]; // bank 0
    ch2_bank_req_array_valid_In[1][4:0] = ch2_bank_req_array_valid_Q[1][4:0] & ~ch2_bank_req_array_invalidate[0][4:0]; // bank 1
    ch2_bank_req_array_valid_In[2][4:0] = ch2_bank_req_array_valid_Q[2][4:0] & ~ch2_bank_req_array_invalidate[0][4:0]; // bank 2
    ch2_bank_req_array_valid_In[3][4:0] = ch2_bank_req_array_valid_Q[3][4:0] & ~ch2_bank_req_array_invalidate[0][4:0]; // bank 3

    if (ch2_req_push) begin
      ch2_bank_req_array_valid_In[ch2_bank_map][ch2_write_ptr_Q] = 1'b1;
    end

  end

//=============================================================
//            Channel want send request to Bank
// 此处目的为仲裁出每个 Channel 的 Entry ID
//=============================================================

//-------------------------------------------------------------
//                         Channel 0
//-------------------------------------------------------------
  assign ch0_want_send_to_bank0 = |ch0_bank_req_array_valid_Q[0][4:0];
  assign ch0_want_send_to_bank1 = |ch0_bank_req_array_valid_Q[1][4:0];
  assign ch0_want_send_to_bank2 = |ch0_bank_req_array_valid_Q[2][4:0];
  assign ch0_want_send_to_bank3 = |ch0_bank_req_array_valid_Q[3][4:0];

  ch_rr
  ch0_bank0_rr(
    .entry_valid_i (ch0_bank_req_array_valid_Q[0][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q                    ),
    .first_ptr_o   (ch0_entryId_want_send_to_bank0    )
  );

  ch_rr
  ch0_bank1_rr(
    .entry_valid_i (ch0_bank_req_array_valid_Q[1][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q                    ),
    .first_ptr_o   (ch0_entryId_want_send_to_bank1    )
  );

  ch_rr
  ch0_bank2_rr(
    .entry_valid_i (ch0_bank_req_array_valid_Q[2][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q                    ),
    .first_ptr_o   (ch0_entryId_want_send_to_bank2    )
  );

  ch_rr
  ch0_bank3_rr(
    .entry_valid_i (ch0_bank_req_array_valid_Q[3][4:0]),
    .read_ptr_i    (ch0_read_ptr_Q                    ),
    .first_ptr_o   (ch0_entryId_want_send_to_bank3    )
  );

//-------------------------------------------------------------
//                         Channel 1
//-------------------------------------------------------------
  assign ch1_want_send_to_bank0 = |ch1_bank_req_array_valid_Q[0][4:0];
  assign ch1_want_send_to_bank1 = |ch1_bank_req_array_valid_Q[1][4:0];
  assign ch1_want_send_to_bank2 = |ch1_bank_req_array_valid_Q[2][4:0];
  assign ch1_want_send_to_bank3 = |ch1_bank_req_array_valid_Q[3][4:0];

  ch_rr
  ch1_bank0_rr(
    .entry_valid_i (ch1_bank_req_array_valid_Q[0][4:0]),
    .read_ptr_i    (ch1_read_ptr_Q                    ),
    .first_ptr_o   (ch1_entryId_want_send_to_bank0    )
  );

  ch_rr
  ch1_bank1_rr(
    .entry_valid_i (ch1_bank_req_array_valid_Q[1][4:0]),
    .read_ptr_i    (ch1_read_ptr_Q                    ),
    .first_ptr_o   (ch1_entryId_want_send_to_bank1    )
  );

  ch_rr
  ch1_bank2_rr(
    .entry_valid_i (ch1_bank_req_array_valid_Q[2][4:0]),
    .read_ptr_i    (ch1_read_ptr_Q                    ),
    .first_ptr_o   (ch1_entryId_want_send_to_bank2    )
  );

  ch_rr
  ch1_bank3_rr(
    .entry_valid_i (ch1_bank_req_array_valid_Q[3][4:0]),
    .read_ptr_i    (ch1_read_ptr_Q                    ),
    .first_ptr_o   (ch1_entryId_want_send_to_bank3    )
  );

//-------------------------------------------------------------
//                         Channel 2
//-------------------------------------------------------------
  assign ch2_want_send_to_bank0 = |ch2_bank_req_array_valid_Q[0][4:0];
  assign ch2_want_send_to_bank1 = |ch2_bank_req_array_valid_Q[1][4:0];
  assign ch2_want_send_to_bank2 = |ch2_bank_req_array_valid_Q[2][4:0];
  assign ch2_want_send_to_bank3 = |ch2_bank_req_array_valid_Q[3][4:0];

  ch_rr
  ch2_bank0_rr(
    .entry_valid_i (ch2_bank_req_array_valid_Q[0][4:0]),
    .read_ptr_i    (ch2_read_ptr_Q                    ),
    .first_ptr_o   (ch2_entryId_want_send_to_bank0    )
  );

  ch_rr
  ch2_bank1_rr(
    .entry_valid_i (ch2_bank_req_array_valid_Q[1][4:0]),
    .read_ptr_i    (ch2_read_ptr_Q                    ),
    .first_ptr_o   (ch2_entryId_want_send_to_bank1    )
  );

  ch_rr
  ch2_bank2_rr(
    .entry_valid_i (ch2_bank_req_array_valid_Q[2][4:0]),
    .read_ptr_i    (ch2_read_ptr_Q                    ),
    .first_ptr_o   (ch2_entryId_want_send_to_bank2    )
  );

  ch_rr
  ch2_bank3_rr(
    .entry_valid_i (ch2_bank_req_array_valid_Q[3][4:0]),
    .read_ptr_i    (ch2_read_ptr_Q                    ),
    .first_ptr_o   (ch2_entryId_want_send_to_bank3    )
  );

//=============================================================
//               Bank handle channel request
//=============================================================

  assign bank0_channel_req_array[2:0] = {ch2_want_send_to_bank0, 
                                         ch1_want_send_to_bank0,
                                         ch0_want_send_to_bank0};

  assign bank1_channel_req_array[2:0] = {ch2_want_send_to_bank1, 
                                         ch1_want_send_to_bank1,
                                         ch0_want_send_to_bank1};

  assign bank2_channel_req_array[2:0] = {ch2_want_send_to_bank2, 
                                         ch1_want_send_to_bank2,
                                         ch0_want_send_to_bank2};

  assign bank3_channel_req_array[2:0] = {ch2_want_send_to_bank3, 
                                         ch1_want_send_to_bank3,
                                         ch0_want_send_to_bank3};

//---------------------------------------------------------------
// 每个 Bank 使用轮训仲裁的方法，选择一个 Channel 的请求进行发送
// 此处目的为仲裁出 Channel ID
//
// channel0 ---|
// channel1 ---|---> Bank0 (channel ID)
// channel2 ---|
//
// channel0 ---|
// channel1 ---|---> Bank1 (channel ID)
// channel2 ---|
//
// channel0 ---|
// channel1 ---|---> Bank2 (channel ID)
// channel2 ---|
//
// channel0 ---|
// channel1 ---|---> Bank3 (channel ID)
// channel2 ---|
//
//---------------------------------------------------------------
  bank_ch_rr
  bank0_ch_rr(
    .clk_i          (clk_i                  ),
    .rstn_i         (rstn_i                 ),
    .ch_req_valid_i (bank0_channel_req_array),
    .ch_req_id_o    (bank0_channel_req_id   )
  );

  bank_ch_rr
  bank1_ch_rr(
    .clk_i          (clk_i                  ),
    .rstn_i         (rstn_i                 ),
    .ch_req_valid_i (bank1_channel_req_array),
    .ch_req_id_o    (bank1_channel_req_id   )
  );

  bank_ch_rr
  bank2_ch_rr(
    .clk_i          (clk_i                  ),
    .rstn_i         (rstn_i                 ),
    .ch_req_valid_i (bank2_channel_req_array),
    .ch_req_id_o    (bank2_channel_req_id   )
  );

  bank_ch_rr
  bank3_ch_rr(
    .clk_i          (clk_i                  ),
    .rstn_i         (rstn_i                 ),
    .ch_req_valid_i (bank3_channel_req_array),
    .ch_req_id_o    (bank3_channel_req_id   )
  );


endmodule