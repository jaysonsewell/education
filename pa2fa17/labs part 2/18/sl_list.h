/*
 * Name        : sl_list.h
 * Author      : Jayson Sewell
 * Description : function calls
 */
#ifndef SL_LIST_H_
#define SL_LIST_H_
#include <iostream>
#include <sstream>
#include "sl_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class SLList {

 public:
  SLList();
  ~SLList();
  void InsertHead(int head);
  void RemoveHead();
  void Clear();
  unsigned int size() const;
  string ToString() const;

 private:
  SLNode* head_;
  unsigned int size_;
};
#endif /* SL_LIST_H_ */
