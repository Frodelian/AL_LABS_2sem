#include "square.h"

#include <cmath>
#include <iostream>

Square::Square() { a = 0; }
Square::Square(double n) { a = n; }
double Square::S() { return pow(a, 2); }
void Square::print() {
  std::cout << "side: " << a << " area: " << S() << std::endl;
}
