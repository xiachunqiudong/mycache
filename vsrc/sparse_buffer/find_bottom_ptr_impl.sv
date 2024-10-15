module fid_bottom_ptr_impl(
  input  logic [7:0] entry_valid_i,
  input  logic [2:0] bottom_ptr_current,
  output logic [2:0] bottom_ptr_next
);

  logic [7:0] entry_valid_shift;

  assign entry_valid_shift = entry_valid_i >> bottom_ptr_current
                           | entry_valid_i << ('d8 - bottom_ptr_current);

  assign bottom_ptr_next[2:0] = entry_valid_shift[0] ? bottom_ptr_current[2:0]
                              : entry_valid_shift[1] ? bottom_ptr_current[2:0] + 3'd1
                              : entry_valid_shift[2] ? bottom_ptr_current[2:0] + 3'd2
                              : entry_valid_shift[3] ? bottom_ptr_current[2:0] + 3'd3
                              : entry_valid_shift[4] ? bottom_ptr_current[2:0] + 3'd4
                              : entry_valid_shift[5] ? bottom_ptr_current[2:0] + 3'd5
                              : entry_valid_shift[6] ? bottom_ptr_current[2:0] + 3'd6
                              : entry_valid_shift[7] ? bottom_ptr_current[2:0] + 3'd7
                              :                        3'd7; // if has no valid entry set bottom ptr to 7

endmodule