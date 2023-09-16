#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "topic.h"

class User {
 protected:
  std::string name_;

 public:
  User(const std::string &name) : name_(name) {}
  User(const User &other);
  User(User &&other);

  virtual ~User() {}
  virtual void printRole() const = 0;
  virtual void printActions() const = 0;
  virtual void executeAction(Topic &topic, int action) = 0;
};