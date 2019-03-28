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
bool BSTree::Remove(int value) {
  if (root_ == NULL) {
    return false;
  }
  return Remove_(value, root_);
}
int BSTree::FindMin() {
  if (root_ == NULL) {
    return 0;
  }
  return FindMin_(root_);
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
    return true;
  } else if (value < subroot->GetContents()) {
    return Insert_(value, subroot->GetLeftChild());
  } else if (value > subroot->GetContents()) {
    return Insert_(value, subroot->GetRightChild());
  }
  return false;
}
bool BSTree::Remove_(int value, BSTNode*& sr) {
  if (sr == NULL) {
    return false;
  } else if (sr->GetContents() == value) {
    if (sr->GetLeftChild() == NULL && sr->GetRightChild() == NULL) {
      delete sr;
      sr = NULL;
    } else if (sr->GetLeftChild() != NULL && sr->GetRightChild() == NULL) {
      BSTNode* temp = sr;
      sr = sr->GetLeftChild();
      delete temp;
    } else if (sr->GetRightChild() != NULL && sr->GetLeftChild() == NULL) {
      BSTNode* temp = sr;
      sr = sr->GetRightChild();
      delete temp;
    } else {
      value = FindMin_(sr->GetRightChild());
      sr->GetContents() = value;
      return Remove_(value, sr->GetRightChild());
      // sr->GetContents() = value;
      // BSTNode* temp = FindMin_(sr->GetRightChild());
      // delete temp;
      // temp = NULL;
    }
    size_--;
  } else if (sr->GetContents() > value) {
    return Remove_(value, sr->GetLeftChild());
  } else {
    return Remove_(value, sr->GetRightChild());
  }
  return true;
}
int BSTree::FindMin_(BSTNode* min) const {
  if (min->GetLeftChild() != NULL) {
    // if (min->GetLeftChild() == NULL) {
    return FindMin_(min->GetLeftChild());
  }
  return min->GetContents();
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
  if (subroot != NULL) {
    ss << InOrder_(subroot->GetLeftChild());
    ss << subroot->GetContents() << " ";
    ss << InOrder_(subroot->GetRightChild());
  }
  s = ss.str();
  return s;
}
