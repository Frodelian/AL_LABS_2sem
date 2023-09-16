#pragma once

template <class T>
class MyUnique {
  T* p = nullptr;

 public:
  explicit MyUnique(T* p) : p(p) {}
  ~MyUnique() {
    delete p;
  }  // Деструктор, который удаляет объект на который ссылается наш указатель
  T* get() const noexcept { return p; }  // Метод get() возвращает указатель p
  T& operator*() { return *p; }  // Оператор разыменования
  T* operator->() { return p; }  // Оператор доступа к членам класса

  MyUnique(const MyUnique&) = delete;  // Удаляем конструктор копирования
  MyUnique& operator=(const MyUnique&) =
      delete;  // Удаляем оператор присваивания копирования

  // Реализация перемещения
  MyUnique(MyUnique&& other) : p(other.p) { other.p = nullptr; }

  MyUnique& operator=(MyUnique&& other) {
    if (this != &other) {
      delete p;
      p = other.p;
      other.p = nullptr;
    }
    return *this;
  }
};

template <typename T, typename... Args>
MyUnique<T> MakeUnique(const Args&... args) {
  return MyUnique(new T(std::forward(args...)));
}
