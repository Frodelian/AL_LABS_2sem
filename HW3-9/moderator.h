#pragma once

#include "registeredUser.h"
#include "user.h"

class Moderator : public RegisteredUser {
 public:
  Moderator(std::string name);

  void printRole() const;
  void printActions() const;
  void executeAction(Topic& topic, int action);
};
