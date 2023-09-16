#include "student.h"

Student::Student(std::string FIO, std::string group, int number, int a[4])
    : FIO(std::move(FIO)), group(std::move(group)), number(number) {
  for (int i = 0; i < 4; ++i) {
    this->a[i] = a[i];
  }
}

std::ostream &operator<<(std::ostream &out, const Student &obj) {
  out << "Name: " << obj.FIO << " group: " << obj.group
      << " number: " << obj.number << " grades: ";
  for (int i = 0; i < 4; ++i) {
    out << obj.a[i] << " ";
  }
  return out;
}

bool Student::operator<(const Student &obj) const { return FIO < obj.FIO; }

bool Student::operator==(const Student &obj) const {
  return FIO == obj.FIO && group == obj.group && number == obj.number;
}