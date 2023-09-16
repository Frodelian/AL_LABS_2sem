#include "cube_except.h"

#include <iostream>

Cube_except::Cube_except(const char* name_of_except, int x, int y, int z)
    : out_of_range(std::move(name_of_except)), x_(x), y_(y), z_(z) {}
void Cube_except::print() const {
  std::cout << "Exception: " << what() << std::endl;
  std::cout << "x = " << x_ << std::endl;
  std::cout << "y = " << y_ << std::endl;
  std::cout << "z = " << z_ << std::endl;
  std::cout << "The coordinates of the point are out of range: {" << x_ << ","
            << y_ << "," << z_ << "}";
}