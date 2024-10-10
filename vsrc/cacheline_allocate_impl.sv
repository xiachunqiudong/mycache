module cacheline_allocate_impl(
  input logic [6:0]  plru_node_state_i,
  input logic [7:0]  cacheline_valid_flags_i,
  output logic [2:0] allocate_index_o
);

  logic [6:0] plru_remap_node;

  logic cacheline_valid_flags_01;
  logic cacheline_valid_flags_23;
  logic cacheline_valid_flags_45;
  logic cacheline_valid_flags_67;
  logic cacheline_valid_flags_0123;
  logic cacheline_valid_flags_4567;

  assign cacheline_valid_flags_01 = &cacheline_valid_flags_i[1:0];
  assign cacheline_valid_flags_23 = &cacheline_valid_flags_i[3:2];
  assign cacheline_valid_flags_45 = &cacheline_valid_flags_i[5:4];
  assign cacheline_valid_flags_67 = &cacheline_valid_flags_i[7:6];

  assign cacheline_valid_flags_0123 = cacheline_valid_flags_01 & cacheline_valid_flags_23;
  assign cacheline_valid_flags_4567 = cacheline_valid_flags_45 & cacheline_valid_flags_67;

  // 如果左边和右边的 valid 状态一致，根据 plru 的状态进行选择
  // 如果左边存在 in-valid 的 cacheline，则选择左边的节点进行替换
  // 如果右边存在 in-valid 的 cacheline，则选择右边的节点进行替换

  assign plru_remap_node[6] = cacheline_valid_flags_0123 == cacheline_valid_flags_4567 ? plru_node_state_i[6]
                              cacheline_valid_flags_0123                               ? 1'b1
                                                                                       : 1'b0;

  assign plru_remap_node[5] = cacheline_valid_flags_45 == cacheline_valid_flags_67 ? plru_node_state_i[5]
                              cacheline_valid_flags_45                             ? 1'b1
                                                                                   : 1'b0;

  assign plru_remap_node[4] = cacheline_valid_flags_01 == cacheline_valid_flags_23 ? plru_node_state_i[4]
                              cacheline_valid_flags_01                             ? 1'b1
                                                                                   : 1'b0;

  assign plru_remap_node[3] = cacheline_valid_flags_i[6] == cacheline_valid_flags_i[7] ? plru_node_state_i[3]
                              cacheline_valid_flags_i[6]                               ? 1'b1
                                                                                       : 1'b0;

  assign plru_remap_node[2] = cacheline_valid_flags_i[4] == cacheline_valid_flags_i[5] ? plru_node_state_i[2]
                              cacheline_valid_flags_i[4]                               ? 1'b1
                                                                                       : 1'b0;

  assign plru_remap_node[1] = cacheline_valid_flags_i[2] == cacheline_valid_flags_i[3] ? plru_node_state_i[1]
                              cacheline_valid_flags_i[2]                               ? 1'b1
                                                                                       : 1'b0;

  assign plru_remap_node[0] = cacheline_valid_flags_i[0] == cacheline_valid_flags_i[1] ? plru_node_state_i[0]
                              cacheline_valid_flags_i[0]                               ? 1'b1
                                                                                       : 1'b0;

  assign allocate_index_o[2] = plru_remap_node[6];

  assign allocate_index_o[1] = plru_remap_node[6] ? plru_remap_node[5] : plru_remap_node[4];

  assign allocate_index_o[0] = plru_remap_node[6] ? (plru_remap_node[5] ? plru_remap_node[3] 
                                                                        : plru_remap_node[2])
                                                  : (plru_remap_node[4] ? plru_remap_node[1] 
                                                                        : plru_remap_node[0]);


endmodule