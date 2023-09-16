#pragma once

class Square {
 protected:
  double a = 0;

 public:
  Square();
  Square(double a);
  virtual double S();
  virtual void print();
};
