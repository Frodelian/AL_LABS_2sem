#include <iostream>

#include "cube.h"
#include "cube_except.h"

int main() {
  std::cout << "First example:" << std::endl;
  try {
    Cube Arr = Cube(1, 0, 0);
    std::cout << "All correct" << std::endl;
    Arr.print();
  } catch (Cube_except ex) {
    ex.print();
  }
  std::cout << "Second example:" << std::endl;
  try {
    Cube Arr = Cube(3, 0, 6);
    std::cout << "All correct" << std::endl;
    Arr.print();
  } catch (Cube_except ex) {
    ex.print();
  }
  return 0;
}
