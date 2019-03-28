/*
 * Name        : sl_node.cpp
 * Author      : Jayson Sewell
 * Description : function definitions
 */
#include "sl_node.h"
SLNode::SLNode() {
  next_node_ = NULL;
  contents_ = 0;
}
SLNode::SLNode(int contents) {
  next_node_ = NULL;
  contents_ = contents;
}
SLNode::~SLNode() {
}
void SLNode::set_contents(int contents) {
  contents_ = contents;
}
int SLNode::contents() const {
  return contents_;
}
void SLNode::set_next_node(SLNode* nextNode) {
  next_node_ = nextNode;
}
SLNode* SLNode::next_node() const {
  return next_node_;
}
