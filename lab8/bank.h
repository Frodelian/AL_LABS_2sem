#pragma once

#include <string>

class Bank {
  std::string fio_;
  double summa_;
  double percent_;

 public:
  Bank(std::string fio, double summa, double percent);
  Bank();
  ~Bank();
  double getsumma(int year) const;
  void print() const;
};
