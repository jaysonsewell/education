/*
 * Name        : bst_node.cpp
 * Author      : Jayson Sewell
 * Description : Creating a Node for a Binary Search Tree
 */
#ifndef BST_NODE_
#define BST_NODE_
#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class BSTNode {
 public:
  BSTNode();
  BSTNode(int contents);
  ~BSTNode();
  void SetContents(int contents);
  int GetContents() const;
  int& GetContents();
  void SetLeftChild(BSTNode* lc);
  void SetRightChild(BSTNode* rc);
  BSTNode* GetLeftChild() const;
  BSTNode*& GetLeftChild();
  BSTNode* GetRightChild() const;
  BSTNode*& GetRightChild();

 private:
  BSTNode* rc_;
  BSTNode* lc_;
  int contents_;
};

#endif /* BST_NODE_ */
