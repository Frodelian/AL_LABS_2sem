#pragma once

#include <exception>
#include <stdexcept>

class Cube_except : public std::out_of_range {
  int x_;
  int y_;
  int z_;

 public:
  Cube_except(const char* name_of_except, int x, int y, int z);
  void print() const;
};