/*
 * Name        : sl_list.h
 * Author      : Jayson Sewell
 * Description : function calls
 */
#ifndef SL_LIST_H_
#define SL_LIST_H_
#include <iostream>
#include <sstream>
#include <cassert>
#include "sl_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class SLList {
 public:
  SLList();
  ~SLList();
  void Insert(int value);
  bool RemoveFirstOccurence(int value);
  int GetHead() const;
  int GetTail() const;
  void Clear();
  unsigned int size() const;
  string ToString() const;

 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;
  void InsertHead_(int head);
  void InsertTail_(int tail);
  void RemoveHead_();
  void RemoveTail_();
};
#endif /* SL_LIST_H_ */
