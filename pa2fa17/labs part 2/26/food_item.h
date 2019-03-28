/*
 * Name        : food_item.h
 * Author      : jayson sewell
 * Description : Working on Inheritance
 */

#ifndef FOOD_ITEM_
#define FOOD_ITEM_
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

class FoodItem : public Item {
 public:
  FoodItem(string name = "fooditem", unsigned int value = 0,
            unsigned int calories = 0, string unit_of_measure = "nounits",
            double units = 0)
          : Item(name, value),
            calories_(calories),
            unit_of_measure_(unit_of_measure),
            units_(units) {
  }
  ~FoodItem();
  unsigned int calories();
  string unit_of_measure();
  double units();
  void set_calories(unsigned int calorie);
  void set_unit_of_measure(string unit_of_measure);
  void set_units(double units);
  string ToString();

 private:
  unsigned int calories_;
  string unit_of_measure_;
  double units_;
};
#endif
