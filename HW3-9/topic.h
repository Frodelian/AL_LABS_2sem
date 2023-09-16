#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Topic {
 protected:
  std::string file_name_;
  std::fstream fin_;

 public:
  Topic(std::string file_name_);

  static void printTopics();

  void view();
  void write(std::string name, std::string role, std::string comment);
  void modify(int number, const std::string& new_comment);
  void erase(int number);
};