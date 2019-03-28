/*
 * Name        : sl_list.cpp
 * Author      : Jayson Sewell
 * Description : function definitions
 */
#include "sl_node.h"
#include "sl_list.h"

SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}
SLList::~SLList() {
  Clear();
}
void SLList::InsertHead(int head) {
  if (head_ == NULL) {
    SLNode *temp = new SLNode(head);
    temp->set_next_node(head_);
    head_ = temp;
    tail_ = temp;
    size_++;
  } else {
    SLNode *temp = new SLNode(head);
    temp->set_next_node(head_);
    head_ = temp;
    size_++;
  }
}
void SLList::InsertTail(int tail) {
  if (head_ != NULL) {
    // for (SLNode* i = head_; i != NULL; i = i->next_node()) {
    // while (temp->next_node() != NULL) {
      // if (i->next_node() == tail_) {
      SLNode *temp = new SLNode(tail);
      // temp->set_next_node(NULL);
      // i->set_next_node(temp);
      tail_->set_next_node(temp);
      tail_ = temp;
      // assert(tail_ = NULL);
      // tail_->set_next_node(NULL);
      size_++;
      // i = NULL;
      // }
    // }
    // size_++;
  } else {
    InsertHead(tail);
    // SLNode *temp = new SLNode(tail);
    // temp->set_next_node(tail_);
    // tail_ = temp;
    // head_ = temp;
    // size_++;
    // i = NULL;
}
// while (temp->next_node() != NULL) {
// }
// SLNode *temp = new SLNode(tail);
// temp->set_next_node(tail_);
// tail_ = temp;
// size_++;
}
void SLList::RemoveHead() {
  if (head_ != NULL) {
    if (tail_ == head_) {
      SLNode *temp = head_;
      head_ = head_->next_node();
      tail_ = tail_->next_node();
      delete temp;
      size_--;
    } else {
      SLNode *temp = head_;
      head_ = head_->next_node();
      delete temp;
      size_--;
    }
  }
  // else {
    // throw "NULL ARRAY REFERENCE";
    // break;
  // }
}
void SLList::RemoveTail() {
  if (head_ != NULL) {
    if (head_->next_node() == NULL) {
      RemoveHead();
      tail_ = head_;
    } else {
      for (SLNode* i = head_; i != NULL; i = i->next_node()) {
        if (i->next_node() == tail_) {
          SLNode *temp = tail_;
          tail_ = i;
          tail_->set_next_node(NULL);
          delete temp;
          // i = NULL;
          // i = i->next_node();
          // tail_ = i->next_node();
          size_--;
        }
      // if (i) {}
      }
    }
  // else {
    // throw "NULL ARRAY REFERENCE";
    // break;
  // }
  }
}
int SLList::GetHead() const {
  if (head_ == NULL) {
  return 0;
  }
  return head_->contents();
}
int SLList::GetTail() const {
  if (head_ == NULL) {
  return 0;
  }
  return tail_->contents();
}
void SLList::Clear() {
  while (head_ != NULL) {
  RemoveHead();
  }
}
unsigned int SLList::size() const {
  return size_;
}
string SLList::ToString() const {
  stringstream ss;
  string s;
  // if (head_ != NULL) {
  for (SLNode* i = head_; i != NULL; i = i->next_node()) {
// unsigned int num = 0;
// num++;
// cout << num;
    if (i != head_) {
      ss << ", ";
    }
    ss << i->contents();
  }
  // }
  s = ss.str();
  return s;
}
