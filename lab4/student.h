#pragma once

#include <iostream>
#include <string>

class Student {
 public:
  // конструктор по умолчанию вызывается когда создаём элемент без параметров
  Student() = default;  // скопирует все члены в private, при этом для string
                        // есть конструкторы, для int конструкторов нету, они
                        // будут скопированы тривиальным способом, по байтам

  // конструктор копирования вызывается когда пытаемся создать элемент на основе
  // другого элемента
  Student(std::string FIO, std::string group, int number,
          int a[4]);  // если есть нетривиальный конструктор, то конструктор по
                      // умолчанию не генерируется
  friend std::ostream &operator<<(std::ostream &out, const Student &obj);
  bool operator<(const Student &obg) const;

 private:
  std::string FIO;
  std::string group;
  int number;
  int a[4];
};

std::ostream &operator<<(std::ostream &out, const Student &obj);

// строки пустые, int заполнены мусором

// если бы был динамический массив a(new int[4]), конструктор бы
// создался(деструктор есть тогда утечки не будет)
// ~Student() {
//  delete[] a;
// }
// private:
// int *a; копируется их адрес 4-х интов, в результате 4 класса указывают на
// один и тот же адрес, из-за чего деструктор несколько раз освободит одну и
// туже память