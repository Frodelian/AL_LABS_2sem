#include "vector.h"

Vector::Vector() : ptr_(nullptr), size_(0) {}
Vector::Vector(int size) : ptr_(new double[size]), size_(size) {
  for (int i = 0; i < size_; ++i) {
    ptr_[i] = 0.0;  // заполним вектор нулями
  }
}
Vector::Vector(double *ptr, int size) : ptr_(new double[size]), size_(size) {
  for (int i = 0; i < size_; ++i) {
    ptr_[i] = ptr[i];
  }
}

// double arr[] = {1, 2, 3};
// Vector vec(arr, 3);
// vec[0] = 5;
// std::cout << arr[0]; //5
// вектор адрес в памяти и число
Vector::Vector(const Vector &other)
    : Vector(other.ptr_, other.size_) {
}  // other внутри указатель на память и размер
Vector::Vector(Vector &&other) : ptr_(other.ptr_), size_(other.size_) {
  other.ptr_ = nullptr;
  other.size_ = 0;
}
Vector::~Vector() {
  if (ptr_ != nullptr) {
    delete[] ptr_;
  }
}

double &Vector::operator[](int index) { return ptr_[index]; }
const double &Vector::operator[](int index) const { return ptr_[index]; }
Vector &Vector::operator=(const Vector &other) {
  if (ptr_ != nullptr) {
    delete[] ptr_;
  }
  if (other.size_ == 0) {
    ptr_ = nullptr;
    size_ = 0;
  } else {
    size_ = other.size_;
    ptr_ = new double[size_];
    for (int i = 0; i < size_; ++i) {
      ptr_[i] = other.ptr_[i];
    }
  }
  return *this;
}
Vector &Vector::operator=(Vector &&other) {
  if (ptr_ != nullptr) {
    delete[] ptr_;
  }
  if (other.size_ == 0) {
    ptr_ = nullptr;
    size_ = 0;
  } else {
    size_ = other.size_;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Vector &vec) {
  for (int i = 0; i < vec.size_; ++i) {
    out << vec.ptr_[i] << " ";
  }
  return out;
}

std::istream &operator>>(std::istream &in, Vector &vec) {
  int n;
  in >> n;
  vec = Vector(n);
  for (int i = 0; i < vec.size_; ++i) {
    in >> vec.ptr_[i];
  }
  return in;
}

Vector operator+(const double *lhs, const Vector &rhs) {
  int n = rhs.size_;  // достаём размер
  Vector res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = lhs[i] + rhs[i];
  }
  return res;
}