#include "moderator.h"

#include <iomanip>

#include "topic.h"

Moderator::Moderator(std::string name) : RegisteredUser(name) {}

void Moderator::printRole() const {
  std::cout << "your access rights on the forum moderator." << std::endl;
}

void Moderator::printActions() const {
  std::cout << "Since you are a moderator, you have a number of possibilities: "
               "to view, write, modify and delete messages."
            << std::endl;
  std::cout << "1 = view" << std::endl;
  std::cout << "2 = write" << std::endl;
  std::cout << "3 = modify" << std::endl;
  std::cout << "4 = delete" << std::endl;
  std::cout << "Enter the number that corresponds to the function you need: ";
}

void Moderator::executeAction(Topic& topic, int action) {
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
      std::string role = "Moderator";
      std::cin >> std::quoted(comment);
      topic.write(name_, role, comment);
      break;
    }
    case 3: {
      // Modify
      topic.view();
      std::cout << "Enter the number of the message you want to change: ";
      int number;
      std::cin >> number;
      std::cout << std::endl;
      std::cout << "Enter the text you want to see in this comment, put "
                   "quotation marks at the end and at the beginning:";
      std::string new_comment;
      std::cin >> std::quoted(new_comment);
      std::cout << std::endl;
      topic.modify(number, new_comment);
      break;
    }
    case 4: {
      // Delete
      topic.view();
      std::cout << "Enter the message number to delete it:";
      int number;
      std::cout << std::endl;
      std::cin >> number;
      topic.erase(number);
      break;
    }
    default: {
      std::cout << "Invalid number" << std::endl;
    } break;
  }
}