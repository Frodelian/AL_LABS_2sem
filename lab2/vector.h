#pragma once

#include <iostream>
#include <utility>

class Vector {
 public:
  Vector();          // конструктор без параметров
  Vector(int size);  // конструктор одномерного массива размерности n
  Vector(double *ptr, int size);  // конструктор
  Vector(const Vector &other);  // конструктор копирования
  Vector(Vector &&other);       // конструктор перемещения
  ~Vector();                    // деструктор

  double &operator[](int index);  // обращение к вектору по индексу
  const double &operator[](int index) const;  // для operator+
  Vector &operator=(
      const Vector &other);  // оператор присваивания с копированием
  Vector &operator=(Vector &&other);  // оператор присваивания перемещения

  friend Vector operator+(const double *lhs, const Vector &rhs);
  friend std::ostream &operator<<(std::ostream &out,
                                  const Vector &vec);  // вывод из потока
  friend std::istream &operator>>(std::istream &in,
                                  Vector &vec);  // ввод из потока

 private:
  double *ptr_ = nullptr;
  int size_ = 0;
};

Vector operator+(const double *lhs, const Vector &rhs);
std::ostream &operator<<(std::ostream &out, const Vector &vec);
std::istream &operator>>(std::istream &in, Vector &vec);
