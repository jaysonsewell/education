/*
 * Name        : magic_item.h
 * Author      : jayson sewell
 * Description : Working on Inheritance
 */

#ifndef MAGIC_ITEM_
#define MAGIC_ITEM_
#include <iostream>
#include <string>
#include <sstream>
#include "item.h"
#include "food_item.h"
#include "magic_item.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class MagicItem : public Item {
 public:
  MagicItem(string name = "magicitem", unsigned int value = 0,
            string description = "no description",
            unsigned int mana_required = 0)
            : Item(name, value),
              description_(description),
              mana_required_(mana_required) {
  }
  ~MagicItem();
  string description();
  unsigned int mana_required();
  void set_description(string description);
  void set_mana_required(unsigned int mana_required);
  string ToString();

 private:
  string description_;
  unsigned int mana_required_;
};
#endif
