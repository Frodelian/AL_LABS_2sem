#pragma once

#include "square.h"

class Cube : public Square {
 public:
  Cube(double a);
  double S();
  void print();
};