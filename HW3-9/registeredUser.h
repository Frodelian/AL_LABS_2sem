#pragma once

#include "user.h"

class RegisteredUser : public User {
 public:
  RegisteredUser(std::string name);

  void printRole() const;
  void printActions() const;
  void executeAction(Topic& topic, int action);
};