#pragma once

#include <iostream>
#include <string>
#include <unordered_set>

class Student {
 public:
  Student() = default;
  Student(std::string FIO, std::string group, int number, int a[4]);
  friend std::ostream &operator<<(std::ostream &out, const Student &obj);
  friend std::hash<Student>;
  bool operator<(const Student &obg) const;
  bool operator==(const Student &other) const;

 private:
  std::string FIO;
  std::string group;
  int number;
  int a[4];
};

// Object -> size_t
// a == b => hash(a) == hash(b)
// a != b => с большой вероятностью hash(a) != hash(b)
// a_1, a_2, a_3, a_4
// (a_1 + a_2 * P + a_3 * P ** 2 + a_4 * P ** 3) % M

template <>
struct std::hash<Student> {
  size_t operator()(const Student &student) const noexcept {
    size_t hash = std::hash<std::string>()(student.FIO) *
                  std::hash<std::string>()(student.group) *
                  static_cast<size_t>(student.number);
    return hash;
  }
};

std::ostream &operator<<(std::ostream &out, const Student &obj);