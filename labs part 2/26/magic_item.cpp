/*
 * Name        : magic_item.cpp
 * Author      : jayson sewell
 * Description : Working on Inheritance
 */

#include "magic_item.h"
#include "item.h"

MagicItem::~MagicItem() {
}
string MagicItem::description() {
  return description_;
}
unsigned int MagicItem::mana_required() {
  return mana_required_;
}
void MagicItem::set_description(string description) {
  description_ = description;
}
void MagicItem::set_mana_required(unsigned int mana_required) {
  mana_required_ = mana_required;
}
string MagicItem::ToString() {
  stringstream ss;
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(3);
  // Add our base ToString to the stream
  ss << Item::ToString();
  ss << ", " << description() << ", requires " << mana_required()
     << " mana";
  return ss.str();
}
