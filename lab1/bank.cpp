#include "bank.h"

#include <iostream>
#include <system_error>

Bank::Bank(std::string fio, double summa, double percent)
    : fio_(std::move(fio)), summa_(summa), percent_(percent) {}

Bank::Bank() : summa_(0), percent_(0), fio_(" ") {}

void Bank::set(std::string fio, double summa, double percent) {
  fio_ = fio;
  summa_ = summa;
  percent_ = percent;
}

double Bank::getsumma(int year) const {
  double summa_years = summa_;
  for (int i = 1; i <= year; i++) {
    summa_years = summa_years * (1 + percent_ / 100);
  }
  return summa_years;
}

void Bank::print() const {
  std::cout << "FIO: " << fio_ << " Percent: " << percent_
            << " Summa: " << summa_ << "\n";
}
