#include "anonymousUser.h"

#include "topic.h"

AnonymousUser::AnonymousUser() : User("Anonymous") {}

void AnonymousUser::printRole() const {
  std::cout << "you are not registered on the forum." << std::endl;
}

void AnonymousUser::printActions() const {
  std::cout << "Since you are anonymous, you can only watch the messages."
            << std::endl;
  std::cout << "1 = view" << std::endl;
  std::cout << "Enter the number that corresponds to the function you need: ";
}

void AnonymousUser::executeAction(Topic& topic, int action) {
  if (action == 1) {
    topic.view();
  } else {
    std::cerr << "Invalid action" << std::endl;
  }
}