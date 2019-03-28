/*
 * Name        : item.h
 * Author      : jayson sewell
 * Description : Working on Inheritance
 */

#ifndef ITEM_CPP_
#define ITEM_CPP_
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Item {
 public:
  Item(string name = "item", unsigned int value = 0)
      : name_(name),
        value_(value) {
  }
  ~Item();
  string name();
  unsigned int value();
  void set_name(string name);
  void set_value(unsigned int value);
  string ToString();
 private:
  string name_;
  unsigned int value_;
};
#endif
