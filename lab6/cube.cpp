#include "cube.h"

#include <iostream>

#include "cube_except.h"

Cube::Cube(int x, int y, int z) : x_(x), y_(y), z_(z) {
  a = 0;
  b = 1;
  if (x_ < a || x_ > b || y_ < a || y_ > b || z_ < a || z_ > b) {
    throw Cube_except("Out of range", x, y, z);
  }
}
void Cube::print() const {
  std::cout << "x = " << x_ << std::endl;
  std::cout << "y = " << y_ << std::endl;
  std::cout << "z = " << z_ << std::endl;
  std::cout << "Coordinates of dot: {" << x_ << "," << y_ << "," << z_ << "}"
            << std::endl;
}
