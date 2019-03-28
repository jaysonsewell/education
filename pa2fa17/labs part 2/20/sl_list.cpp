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
void SLList::Insert(int value) {
  SLNode *temp = new SLNode(value);
  if (head_ == NULL || value <= head_->contents()) {
    InsertHead_(value);
  } else if (value >= tail_->contents()) {
    InsertTail_(value);
  } else {
    SLNode* z = head_;
    SLNode* i;
    for (i = head_; i->contents() <= value; i = i->next_node()) {
      z = i;
    }
    temp->set_next_node(i);
    z->set_next_node(temp);
    size_++;
  }
}
bool SLList::RemoveFirstOccurence(int value) {
  bool truth = false;
  if (head_ != NULL) {
    if (head_->contents() == value) {
      RemoveHead_();
      truth = true;
    } else if (tail_->contents() == value) {
      RemoveTail_();
      truth = true;
    } else {
      for (SLNode* i = head_; i != NULL; i = i->next_node()) {
        // SLNode* z = i;
        if (i->contents() == value) {
          SLNode *temp = i;
          SLNode* z = head_;
          for (; z->next_node() != temp; z = z->next_node());
          i = i->next_node();
          z->set_next_node(i);
          delete temp;
          size_--;
          truth = true;
          break;
        } else {
          truth = false;
        }
      }
    }
  }
  return truth;
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
  RemoveHead_();
  }
}
unsigned int SLList::size() const {
  return size_;
}
string SLList::ToString() const {
  stringstream ss;
  string s;
  for (SLNode* i = head_; i != NULL; i = i->next_node()) {
    if (i != head_) {
      ss << ", ";
    }
    ss << i->contents();
  }
  s = ss.str();
  return s;
}
void SLList::InsertHead_(int head) {
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
void SLList::InsertTail_(int tail) {
  if (head_ != NULL) {
      SLNode *temp = new SLNode(tail);
      tail_->set_next_node(temp);
      tail_ = temp;
      size_++;
  } else {
    InsertHead_(tail);
  }
}
void SLList::RemoveHead_() {
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
}
void SLList::RemoveTail_() {
  if (head_ != NULL) {
    if (head_->next_node() == NULL) {
      RemoveHead_();
      tail_ = head_;
    } else {
      for (SLNode* i = head_; i != NULL; i = i->next_node()) {
        if (i->next_node() == tail_) {
          SLNode *temp = tail_;
          tail_ = i;
          tail_->set_next_node(NULL);
          delete temp;
          size_--;
        }
      }
    }
  }
}
