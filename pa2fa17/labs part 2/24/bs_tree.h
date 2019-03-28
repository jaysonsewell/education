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
  bool Insert(int index);
  void Clear();
  unsigned int GetSize() const;
  string InOrder();

 private:
  bool Insert_(int index, BSTNode*& spot);
  void Clear_(BSTNode*& spot);
  string InOrder_(BSTNode* spot);
  BSTNode* root_;
  unsigned int size_;
};
#endif
