#include "cube.h"

#include <cmath>
#include <iostream>

Cube::Cube(double n) { a = n; }
double Cube::S() { return Square::S() * a; }
void Cube::print() {
  std::cout << std::endl << "side: " << a << " volume: " << S();
}