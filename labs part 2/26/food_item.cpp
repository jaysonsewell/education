/*
 * Name        : food_item.cpp
 * Author      : jayson sewell
 * Description : Working on Inheritance
 */

#include "food_item.h"
#include "item.h"

FoodItem::~FoodItem() {
}
unsigned int FoodItem::calories() {
  return calories_;
}
string FoodItem::unit_of_measure() {
  return unit_of_measure_;
}
double FoodItem::units() {
  return units_;
}
void FoodItem::set_calories(unsigned int calories) {
  calories_ = calories;
}
void FoodItem::set_unit_of_measure(string unit_of_measure) {
  unit_of_measure_ = unit_of_measure;
}
void FoodItem::set_units(double units) {
  units_ = units;
}
string FoodItem::ToString() {
  stringstream ss;
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(2);
  // Add our base ToString to the stream
  ss << Item::ToString();
  ss << ", " << units() << " "
     << unit_of_measure() << ", " << calories() << " calories";
  return ss.str();
}
