/*
 * Name        : sl_list.cpp
 * Author      : Jayson Sewell
 * Description : function definitions
 */
#include "sl_node.h"
#include "sl_list.h"

SLList::SLList() {
	head_ = NULL;
	size_ = 0;
}
SLList::~SLList() {
	Clear();
}
void SLList::InsertHead(int head) {
	SLNode *temp = new SLNode(head);
	temp->set_next_node(head_);
	head_ = temp;
	size_++;
}
void SLList::RemoveHead() {
	if (head_ != NULL) {
		SLNode *temp = head_;
		head_ = head_->next_node();
		delete temp;
		size_--;
	}
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
	for (SLNode* i = head_; i != NULL; i = i->next_node()) {
		// unsigned int num = 0;
		// num++;
		// cout << num;
		if (i != head_) {
			ss << ", ";
		}
		ss << i->contents();
	}
	s = ss.str();
	return s;
}
