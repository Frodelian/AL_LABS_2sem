#include <iostream>

#include "cube.h"
#include "square.h"

int main() {
  double side;
  std::cout << "Enter the size of the side of the square to find its area: ";
  std::cin >> side;
  std::cout << std::endl;
  Square squ(side);
  double cube_side;
  std::cout << "Enter the size of the side of the cube to find its volume: ";
  std::cin >> cube_side;
  std::cout << std::endl;
  Cube cu(cube_side);
  Square *pr;
  pr = &squ;
  pr->print();
  pr = &cu;
  pr->print();
  return 0;
}
