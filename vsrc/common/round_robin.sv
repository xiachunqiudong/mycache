module round_robin (
  input  logic [4:0] entry_valid_i,
  input  logic [2:0] read_ptr_i,
  output logic [2:0] first_ptr_o
);

  logic [4:0] read_ptr_one_hot;
  logic [2:0] ptr_incr;
  logic [4:0] shift_entry_valid;

  assign read_ptr_one_hot[0] = read_ptr_i[2:0] == 3'd0;
  assign read_ptr_one_hot[1] = read_ptr_i[2:0] == 3'd1;
  assign read_ptr_one_hot[2] = read_ptr_i[2:0] == 3'd2;
  assign read_ptr_one_hot[3] = read_ptr_i[2:0] == 3'd3;
  assign read_ptr_one_hot[4] = read_ptr_i[2:0] == 3'd4;

  assign shift_entry_valid[4:0] = {5{read_ptr_one_hot[0]}} & entry_valid_i[4:0]
                                | {5{read_ptr_one_hot[1]}} & {entry_valid_i[0],   entry_valid_i[4:1]}
                                | {5{read_ptr_one_hot[2]}} & {entry_valid_i[0:1], entry_valid_i[4:2]}
                                | {5{read_ptr_one_hot[3]}} & {entry_valid_i[0:2], entry_valid_i[4:3]}
                                | {5{read_ptr_one_hot[4]}} & {entry_valid_i[0:3], entry_valid_i[4]  };

  assign ptr_incr[2:0] = shift_entry_valid[0] ? 3'd0
                       : shift_entry_valid[1] ? 3'd1
                       : shift_entry_valid[2] ? 3'd2
                       : shift_entry_valid[3] ? 3'd2
                       : shift_entry_valid[4] ? 3'd2
                       :                        3'd0;

  assign first_ptr_o[2:0] = read_ptr_i[2:0] + ptr_incr[2:0];

endmodule