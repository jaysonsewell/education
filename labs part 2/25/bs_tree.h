/*
 * Name        : bs_tree.h
 * Author      : jayson sewell
 * Description : Creating your first Binary Search Tree
 */

#ifndef BS_TREE_
#define BS_TREE_
#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int value);
  bool Remove(int value);
  int FindMin();
  void Clear();
  unsigned int GetSize() const;
  string InOrder();

 private:
  bool Insert_(int value, BSTNode*& subroot);
  bool Remove_(int value, BSTNode*& sr);
  int FindMin_(BSTNode* min) const;
  void Clear_(BSTNode*& subroot);
  string InOrder_(BSTNode* subroot);
  BSTNode* root_;
  unsigned int size_;
};
#endif
