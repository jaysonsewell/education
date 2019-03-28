/*
 * Name        : sl_node.h
 * Author      : Jayson Sewell
 * Description : function calls
 */
#ifndef SL_NODE_H_
#define SL_NODE_H_
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class SLNode {
 public:
  SLNode();
  SLNode(int contents);
  ~SLNode();
  void set_contents(int contents);
  int contents() const;
  void set_next_node(SLNode* nextNode);
  SLNode* next_node() const;

 private:
  SLNode* next_node_;
  int contents_;
};
#endif /* SL_NODE_H_ */
