#include <exception>
#include <iostream>

#include "MyShared.h"
#include "MyUnique.h"
#include "bank.h"

int main() {
  std::cout << std::boolalpha;  // Флаг для вывода true и false
  // Bank b1("Oleg", 100, 10);
  // b1.print();
  Bank* b1 = new Bank("Oleg", 100, 10);  // Сырой указатель
  // b1->print();
  MyUnique a1(b1);  // Реализация явного конструктора(стр.6)
  // a1->print(); //Оператор доступа к членам класса
  Bank* b2 = a1.get();
  // std::cout << (b1 == b2) << std::endl; // true
  // a1.get()->print();
  Bank& b3 = *a1;
  // b3.print();
  // a1->print();
  ////MyUnique<Bank> a2(a1); // call to deleted constructor
  // Bank* b4 = new Bank("Sarah", 100, 10);
  // MyUnique a3(b4);
  ////a3 = a1; // overload resolution selected deleted operator '='
  // MyUnique a4(std::move(a1));
  // Bank* b5 = a1.get();
  // std::cout << (b5 == nullptr) << std::endl; // true
  // std::cout << (a4.get() == nullptr) << std::endl; // false
  // std::cout << (a4.get() == b1) << std::endl; // true
  // Bank* b6 = new Bank("John", 200, 5);
  // MyUnique a5(b6);

  // a5 = std::move(a1);
  // std::cout << (a1.get() == nullptr) << std::endl; // true
  // std::cout << (a5.get() == b1) << std::endl; // true

  // MyUnique a6 = MakeUnique///
  //  print

  return 0;
}
