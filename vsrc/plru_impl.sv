module plru_impl(
  input logic       clk_i,
  input logic       rstn_i,
  input logic [7:0] cacheLine_access_map_i
);

  // node: 0 -> left is new, rigth is old
  // node: 1 -> left is old, rigth is new
  logic [6:0] plru_node_state_In;
  logic [6:0] plru_node_state_Q;

  logic plru_node0_old_cacheLine_access;
  logic plru_node1_old_cacheLine_access;
  logic plru_node2_old_cacheLine_access;
  logic plru_node3_old_cacheLine_access;
  logic plru_node4_old_cacheLine_access;
  logic plru_node5_old_cacheLine_access;
  logic plru_node6_old_cacheLine_access;
  logic plru_node7_old_cacheLine_access;

//=========================================================
//                 update plru node state
//=========================================================

//---------------------------------------------------------
// update plru node (bottom): 3, 2, 1, 0
//---------------------------------------------------------
// update node3
  assign plru_node3_old_cacheLine_access = plru_node_state_Q[3]
                                         ? cacheLine_access_map_i[7]
                                         : cacheLine_access_map_i[6];

  assign plru_node_state_In[3] = plru_node3_old_cacheLine_access
                               ? ~plru_node_state_Q[3]
                               :  plru_node_state_Q[3];

// update node2
  assign plru_node2_old_cacheLine_access = plru_node_state_Q[2]
                                         ? cacheLine_access_map_i[5]
                                         : cacheLine_access_map_i[4];

  assign plru_node_state_In[2] = plru_node2_old_cacheLine_access
                               ? ~plru_node_state_Q[2]
                               :  plru_node_state_Q[2];

// update node1
  assign plru_node1_old_cacheLine_access = plru_node_state_Q[1]
                                         ? cacheLine_access_map_i[3]
                                         : cacheLine_access_map_i[2];

  assign plru_node_state_In[1] = plru_node1_old_cacheLine_access
                               ? ~plru_node_state_Q[1]
                               :  plru_node_state_Q[1];

// update node0
  assign plru_node0_old_cacheLine_access = plru_node_state_Q[0]
                                         ? cacheLine_access_map_i[1]
                                         : cacheLine_access_map_i[0];

  assign plru_node_state_In[0] = plru_node0_old_cacheLine_access
                               ? ~plru_node_state_Q[0]
                               :  plru_node_state_Q[0];

//---------------------------------------------------------
// update plru node (middle): 5, 4
//---------------------------------------------------------
// update node5
  assign plru_node5_old_cacheLine_access = plru_node_state_Q[5]
                                         ? |cacheLine_access_map_i[7:6]
                                         : |cacheLine_access_map_i[5:4];

  assign plru_node_state_In[5] = plru_node5_old_cacheLine_access
                               ? ~plru_node_state_Q[5]
                               :  plru_node_state_Q[5];

// update node4
  assign plru_node4_old_cacheLine_access = plru_node_state_Q[4]
                                         ? |cacheLine_access_map_i[3:2]
                                         : |cacheLine_access_map_i[1:0];

  assign plru_node_state_In[4] = plru_node4_old_cacheLine_access
                               ? ~plru_node_state_Q[4]
                               :  plru_node_state_Q[4];

//---------------------------------------------------------
// update plru node (top): 6
//---------------------------------------------------------
  assign plru_node6_old_cacheLine_access = plru_node_state_Q[6]
                                         ? |cacheLine_access_map_i[7:4]
                                         : |cacheLine_access_map_i[3:0];

  assign plru_node_state_In[6] = plru_node6_old_cacheLine_access
                               ? ~plru_node_state_Q[6]
                               :  plru_node_state_Q[6];

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      plru_node_state_Q[6:0] <= 7'b0;
    end
    else begin
      plru_node_state_Q[6:0] <= plru_node_state_In[6:0];
    end
  end


//=========================================================
//                          Debug
//=========================================================
  always_comb begin
    if (|cacheLine_access_map_i[7:0]) begin
      $display("==========================================");
      $display("access_map: %b\n", cacheLine_access_map_i);
      $display("node6: %d\n", plru_node_state_In[6]);
      $display("node5: %d node4: %d\n", plru_node_state_In[5], plru_node_state_In[4]);
      $display("node3: %d node2: %d node1: %d node0: %d\n",
               plru_node_state_In[3], plru_node_state_In[2], plru_node_state_In[1], plru_node_state_In[0]);
    end
  end

endmodule