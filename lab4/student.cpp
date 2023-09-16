#include "student.h"

Student::Student(std::string FIO, std::string group, int number,
                 int a[4])  // конструктор
    : FIO(std::move(FIO)), group(std::move(group)), number(number) {
  for (int i = 0; i < 4; ++i) {
    this->a[i] = a[i];  // через указатель достаём член класса
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

bool Student::operator<(const Student &obj) const {
  return FIO < obj.FIO;
}  // для работы функции sort

// int main() {
//   int grades[] = {0, 1, 2, 3};
//   Student student(std::string("Ol"), "191", 21, grades);
// }

// конструктор копирования вызывается когда объект лежит в какой-то переменной и
// мы создаём один объект из объекта который лежит в другой переменной такого же
// типа а конструктор перемещения когда у нас это результат возврата функции или
// результат std::move или какой-то временный объект, как в случае выше

// просто копирование в данном случае будет срабатывать один раз, так как
// временный объект через ссылку один раз через std::move два перемещения, без
// копирования