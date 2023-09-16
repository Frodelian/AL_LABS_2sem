#pragma once

class Cube {
  int x_;
  int y_;
  int z_;
  int a;
  int b;

 public:
  Cube() = default;
  Cube(int x, int y, int z);
  void print() const;
};