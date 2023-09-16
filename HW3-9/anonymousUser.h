#pragma once

#include "user.h"

class AnonymousUser : public User {
 public:
  AnonymousUser();

  void printRole() const;
  void printActions() const;
  void executeAction(Topic& topic, int action);
};
