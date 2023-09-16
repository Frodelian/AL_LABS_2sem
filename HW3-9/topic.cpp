#include "topic.h"

#include <iomanip>
#include <ios>
#include <stdexcept>
#include <vector>

Topic::Topic(std::string file_name) : file_name_(file_name), fin_(file_name_) {
  if (fin_.fail()) {
    throw std::runtime_error("Topic file .txt not found");
  }
};

void Topic::printTopics() {
  std::cout << "1 - Healthy eating" << std::endl;
  std::cout << "2 - Physical exercises" << std::endl;
  std::cout << "3 - Latest news" << std::endl;
  std::cout << "Enter the number of the topic that interests you: ";
}

void Topic::view() {
  if (fin_.peek() == EOF) {
    std::cout << "No one has spoken out on this topic yet." << std::endl;
  } else {
    std::cout << "-------------------------------------------------------------"
                 "-------------------------------------------------------------"
                 "---------------------"
              << std::endl;
  }
  int i = 1;
  while (fin_.peek() != EOF) {
    std::string header;
    fin_ >> header;
    if (header == "") {
      break;
    }
    std::string comment;
    fin_ >> std::quoted(comment);
    std::cout << i << ". " << header << std::endl
              << "    " << comment << std::endl;
    ++i;
  }
  if (i > 1) {
    std::cout << "-------------------------------------------------------------"
                 "-------------------------------------------------------------"
                 "---------------------"
              << std::endl;
  }
}

void Topic::write(std::string name, std::string role, std::string comment) {
  std::ofstream fin_(file_name_, std::ios::app);
  fin_ << name << "(" << role << ")" << std::endl
       << "    " << std::quoted(comment) << std::endl;
}

void Topic::modify(int number, const std::string& new_comment) {
  std::vector<std::string> headers;
  std::vector<std::string> comments;
  fin_.clear();
  fin_.seekg(0);
  while (fin_.peek() != EOF) {
    std::string header;
    fin_ >> header;
    if (header == "") {
      break;
    }
    std::string comment;
    fin_ >> std::quoted(comment);
    headers.push_back(header);
    comments.push_back(comment);
  }
  fin_.close();
  comments[number - 1] = new_comment;
  fin_.open(file_name_, std::ios::in | std::ios::out | std::ios::trunc);
  for (int i = 0; i < headers.size(); ++i) {
    if (i + 1 == number) {
      fin_ << headers[i] << std::endl
           << "   " << std::quoted(comments[i] + " (modified)") << std::endl;
    } else {
      fin_ << headers[i] << std::endl
           << "   " << std::quoted(comments[i]) << std::endl;
    }
  }
}

void Topic::erase(int number) {
  std::vector<std::string> headers;
  std::vector<std::string> comments;
  int i = 1;
  fin_.clear();
  fin_.seekg(0);
  while (fin_.peek() != EOF) {
    std::string header;
    fin_ >> header;
    if (header == "") {
      break;
    }
    std::string comment;
    fin_ >> std::quoted(comment);
    if (i != number) {
      headers.push_back(header);
      comments.push_back(comment);
    }
    ++i;
  }
  fin_.close();
  fin_.open(file_name_, std::ios::in | std::ios::out | std::ios::trunc);
  for (int i = 0; i < headers.size(); ++i) {
    fin_ << headers[i] << std::endl
         << "    " << std::quoted(comments[i]) << std::endl;
  }
}