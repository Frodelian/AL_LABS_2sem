#pragma once

template <class T>
class MyShared {
  T *p = nullptr;
  int *count = nullptr;

 public:
  explicit MyShared(T *p) : p(p), count(new int(1)) {}
  T *get() const noexcept { return p; }
  T &operator*() { return *p; }
  T *operator->() { return p; }
  ~MyShared() {
    if (count != nullptr) {
      --(*count);
      if (count == 0) {
        delete p;
        delete count;
      }
    }
  }
  MyShared(const MyShared &other) : p(other.p), count(other.count) {
    ++(*count);
  }
  MyShared(MyShared &&other) : p(other.p), count(other.count) {
    other.count = nullptr;
    other.p = nullptr;
  }
  MyShared &operator=(const MyShared &other) {
    if (count != nullptr) {
      --(*count);
      if (count == 0) {
        delete p;
        delete count;
      }
    }
    p = other.p;
    count = other.count;
    ++(*count);
  }
  MyShared &operator=(MyShared &&other) {
    if (count != nullptr) {
      --(*count);
      if (count == 0) {
        delete p;
        delete count;
      }
    }
    p = other.p;
    count = other.count;
    other.count = nullptr;
    other.p = nullptr;
  }
};
