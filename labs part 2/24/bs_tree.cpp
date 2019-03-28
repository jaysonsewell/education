/*
 * Name        : bs_tree.cpp
 * Author      : jayson sewell
 * Description : Creating your first Binary Search Tree
*/

#include "bs_tree.h"

BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}
BSTree::~BSTree() {
  Clear();
}
bool BSTree::Insert(int value) {
  return Insert_(value, root_);
}
void BSTree::Clear() {
  Clear_(root_);
}
unsigned int BSTree::GetSize() const {
  return size_;
}
string BSTree::InOrder() {
  if (root_ == NULL) {
    return string();
  }
  return InOrder_(root_);
}
bool BSTree::Insert_(int value, BSTNode*& subroot) {
  if (subroot == NULL) {
    subroot = new BSTNode(value);
    size_++;
  } else if (value < subroot->GetContents()) {
    return Insert_(value, subroot->GetLeftChild());
  } else if (value > subroot->GetContents()) {
    return Insert_(value, subroot->GetRightChild());
  } else {
    return false;
  }
  return true;
}
void BSTree::Clear_(BSTNode*& subroot) {
  if (subroot != NULL) {
    Clear_(subroot->GetLeftChild());
    Clear_(subroot->GetRightChild());
    delete subroot;
    subroot = NULL;
  }
  size_ = 0;
}
string BSTree::InOrder_(BSTNode* subroot) {
  stringstream ss;
  string s;
  /*
  if (subroot->GetContents() == NULL) {
    ss << subroot->contents_ << " ";
  } else if (lc_->GetContents() < subroot) {
    InOrder_(subroot->GetLeftChild());
  } else if (rc_->GetContents() > subroot) {
    InOrder_(subroot->GetRightChild());
  }
  */
  if (subroot != NULL) {
    ss << InOrder_(subroot->GetLeftChild());
    ss << subroot->GetContents() << " ";
    // return ss.str();
    ss << InOrder_(subroot->GetRightChild());
  }
  s = ss.str();
  return s;
}
