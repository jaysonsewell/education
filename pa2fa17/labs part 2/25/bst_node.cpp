/*
 * Name        : bst_node.cpp
 * Author      : Jayson Sewell
 * Description : Creating a Node for a Binary Search Tree
 */

#include "bst_node.h"

BSTNode::BSTNode() {
  lc_ = NULL;
  rc_ = NULL;
  contents_ = 0;
}
BSTNode::BSTNode(int contents) {
  lc_ = NULL;
  rc_ = NULL;
  contents_ = contents;
}
BSTNode::~BSTNode() {
}
void BSTNode::SetContents(int contents) {
  contents_ = contents;
}
int BSTNode::GetContents() const {
  return contents_;
}
int& BSTNode::GetContents() {
  return contents_;
}
void BSTNode::SetLeftChild(BSTNode* lc) {
  lc_ = lc;
}
void BSTNode::SetRightChild(BSTNode* rc) {
  rc_ = rc;
}
BSTNode* BSTNode::GetLeftChild() const {
  return lc_;
}
BSTNode*& BSTNode::GetLeftChild() {
  return lc_;
}
BSTNode* BSTNode::GetRightChild() const {
  return rc_;
}
BSTNode*& BSTNode::GetRightChild() {
  return rc_;
}
