#include <iostream>

namespace s21 {

template <class T> class Vector {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Vector();
  Vector(size_type n);
  ~Vector();

  bool empty();
  size_type size();
  size_type capacity();

private:
  T *vector_;
  size_type size_;
  size_type capacity_;
};

template <class T> Vector<T>::Vector() {
  vector_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <class T> Vector<T>::Vector(size_t n) {
  size_ = n;
  capacity_ = n;
  vector_ = new T[capacity_]{};
}

template <class T> Vector<T>::~Vector() {
  delete[] vector_;
  size_ = 0;
  capacity_ = 0;
}

template <class T> bool Vector<T>::empty() { return size_ == 0; }
template <class T> size_t Vector<T>::size() { return size_; }
template <class T> size_t Vector<T>::capacity() { return capacity_; }

} // namespace s21

int main() {
  s21::Vector<int> my_vector(6);
  std::cout << my_vector.size() << std::endl;
  if (my_vector.empty() == false) {
    std::cout << "not empty" << std::endl;
  }
  return 0;
}