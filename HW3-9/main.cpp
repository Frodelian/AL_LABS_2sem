#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "anonymousUser.h"
#include "moderator.h"
#include "registeredUser.h"
#include "topic.h"

int main() {
  std::string user_name;

  std::cout << "Please enter your nickname: ";

  if (std::cin >> user_name) {
    std::cout << std::endl;
    std::cout << "Hello, welcome to the forum, " << user_name << ", ";
  } else {
    std::cout << std::endl;
    std::cerr << "Invalid user name" << std::endl;
    std::cout << std::endl;
    return 1;
  }

  User* user;

  std::vector<std::string> roles{"Registered_user:", "Moderator:"};

  std::ifstream fin("users.txt");
  if (fin.fail()) {
    std::cerr << "File not found" << std::endl;
    return 1;
  }

  std::string role;

  if (fin >> role) {
    std::string line;
    if (role == roles[0] || role == roles[1]) {
      while (fin >> line) {
        if (line == roles[0] || line == roles[1]) {
          role = line;
        } else {
          if (user_name == line) {
            break;
          }
        }
      }
    } else {
      std::cerr << "Incorrect role" << std::endl;
      return 1;
    }

    if (user_name == line) {
      if (role == roles[0]) {
        user = new RegisteredUser(user_name);
      } else {
        user = new Moderator(user_name);
      }
    } else {
      user = new AnonymousUser();
    }
  } else {
    std::cerr << "File format is invalid" << std::endl;
    return 1;
  }

  user->printRole();

  std::vector<std::string> topic_files = {
      "Healthy eating.txt", "Physical exercises.txt", "Latest news.txt"};
  std::vector<Topic> topics;
  for (const std::string& topic_file : topic_files) {
    topics.emplace_back(topic_file);
  }

  Topic::printTopics();

  int topic_number;
  if (std::cin >> topic_number) {
    if (topic_number == 1 || topic_number == 2 || topic_number == 3) {
      std::cout << std::endl;
    } else {
      std::cout << std::endl;
      std::cerr << "Unknown topic" << std::endl;
      delete user;
      return 1;
    }
  } else {
    std::cerr << "Invalid topic" << std::endl;
    delete user;
    return 1;
  }

  user->printActions();

  int action;
  if (std::cin >> action) {
    std::cout << std::endl;
  } else {
    std::cout << std::endl;
    std::cerr << "Invalid action" << std::endl;
    return 1;
  }

  if (role == roles[0] || role == roles[1]) {
    user->executeAction(topics[topic_number - 1], action);
  } else {
    std::cout << "You can start viewing messages on the forum." << std::endl;
  }
  delete user;

  return 0;
}