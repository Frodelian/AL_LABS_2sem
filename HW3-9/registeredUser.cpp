#include "registeredUser.h"

#include <iomanip>

#include "topic.h"

RegisteredUser::RegisteredUser(std::string name) : User(name) {}

void RegisteredUser::printRole() const {
  std::cout << "you are registered on the forum." << std::endl;
}

void RegisteredUser::printActions() const {
  std::cout
      << "Since you are a registered user, you can view and write messages."
      << std::endl;
  std::cout << "1 = view" << std::endl;
  std::cout << "2 = write" << std::endl;
  std::cout << "Enter the number that corresponds to the function you need: ";
}

void RegisteredUser::executeAction(Topic& topic, int action) {
  switch (action) {
    case 1: {
      // View
      topic.view();
      break;
    }
    case 2: {
      // Write
      topic.view();
      std::cout << std::endl;
      std::cout << "To enter a comment, use double quotes at the beginning and "
                   "at the end of the message."
                << std::endl;
      std::string comment;
      std::string role = "RegisteredUser";
      std::cin >> std::quoted(comment);
      topic.write(name_, role, comment);
      break;
    }
    default: {
      std::cout << "Invalid action number" << std::endl;
    } break;
  }
}