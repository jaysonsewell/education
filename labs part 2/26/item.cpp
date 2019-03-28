/*
 * Name        : item.cpp
 * Author      : jayson sewell
 * Description : Working on Inheritance
 */

#include "item.h"
#include "food_item.h"
#include "magic_item.h"

Item::~Item() {
}
string Item::name() {
  return name_;
}
unsigned int Item::value() {
  return value_;
}
void Item::set_name(string name) {
  name_ = name;
}
void Item::set_value(unsigned int value) {
  value_ = value;
}
string Item::ToString() {
  stringstream ss;
  // Add our base ToString to the stream
  ss << name() << ", $" << value();
  return ss.str();
}
