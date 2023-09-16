#include <fstream>
#include <iostream>
#include <vector>

#include "bank.h"

int main() {
  std::ifstream in("in.txt");
  int n;
  in >> n;
  std::vector<Bank> accounts;
  std::cout << "Number of subjects: " << n;
  Bank* pBank;
  pBank = new Bank[n];
  int years;
  std::cout << std::endl << "Enter the number of years: ";
  std::cin >> years;
  std::cout << std::endl;
  for (int i = 0; i < n; ++i) {
    std::string name;
    double sum;
    double percent;
    in >> name >> sum >> percent;
    accounts.emplace_back(std::move(name), sum, percent);
    pBank[i].set(name, sum, percent);
  }

  std::cout << "Array" << std::endl;

  in.close();
  for (int i = 0; i < n; ++i) {
    pBank[i].print();
    std::cout << pBank[i].getsumma(years) << std::endl;
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Vector" << std::endl;

  for (Bank& account : accounts) {
    account.print();
    std::cout << account.getsumma(years) << std::endl;
  }
}
