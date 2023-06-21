#include "Vector.h"

namespace s21 {

template <class T> vector<T>::vector() { zero_vector(); }

template <class T> vector<T>::vector(size_t n) {
  size_ = n;
  capacity_ = n;
  vector_ = new T[size_]{};
}

template <class T> vector<T>::vector(std::initializer_list<T> const &items) {
  size_ = items.size();
  capacity_ = size_;
  vector_ = new value_type[size_]{};
  std::copy(items.begin(), items.begin() + items.size(), vector_);
}

template <class T> vector<T>::vector(const vector &v) {
  size_ = v.size_;
  capacity_ = size_;
  vector_ = new T[size_]{};
  std::copy(v.vector_, v.vector_ + v.size_, vector_);
}

template <class T> vector<T>::vector(vector &&v) noexcept {
  size_ = v.size_;
  capacity_ = v.capacity_;
  vector_ = v.vector_;
  v.zero_vector();
}

template <class T> vector<T>::~vector() {
  delete[] vector_;
  zero_vector();
}

template <class T> vector<T> &vector<T>::operator=(vector &&v) noexcept {
  if (this != &v) {
    delete[] vector_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    vector_ = v.vector_;
    v.zero_vector();
  }
  return *this;
}

template <class T> vector<T> &vector<T>::operator=(const vector &v) {
  if (this != &v) {
    delete[] vector_;
    vector_ = new T[v.capacity_];
    std::copy(v.vector_, v.vector_ + v.size_, vector_);
    size_ = v.size_;
    capacity_ = v.capacity_;
  }
  return *this;
}

template <class T> typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("range check pos >= size_");
  }
  return vector_[pos];
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return vector_[pos];
}

template <class T> typename vector<T>::const_reference vector<T>::front() {
  return vector_[0];
}

template <class T> typename vector<T>::const_reference vector<T>::back() {
  return vector_[size_ - 1];
}

template <class T> typename vector<T>::iterator vector<T>::data() {
  return vector_;
}

template <class T> typename vector<T>::iterator vector<T>::begin() {
  return vector_;
}
template <class T> typename vector<T>::iterator vector<T>::end() {
  return vector_ + size_;
}

template <class T> bool vector<T>::empty() { return size_ == 0; }
template <class T> size_t vector<T>::size() { return size_; }
template <class T> size_t vector<T>::max_size() {
  return std::allocator<T>().max_size();
}
template <class T> void vector<T>::reserve(size_type size) {
  if (size > capacity_) {
    T *tmp_vector = new T[size];
    for (size_t i = 0; i < size_; i++) {
      tmp_vector[i] = vector_[i];
    }
    delete[] vector_;
    vector_ = tmp_vector;
    capacity_ = size;
  }
}
template <class T> size_t vector<T>::capacity() { return capacity_; }

template <class T> void vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    T *tmp_vector = new T[size_];
    for (size_t i = 0; i < size_; i++) {
      tmp_vector[i] = vector_[i];
    }
    delete[] vector_;
    vector_ = tmp_vector;
    capacity_ = size_;
  }
}

template <class T> void vector<T>::clear() {
  size_ = 0;
  delete[] vector_;
  vector_ = nullptr;
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  if (pos < begin() || pos > end()) {
    throw std::out_of_range("range check pos >= size_");
  }
  size_t position = pos - begin();
  if (size_ + 1 > capacity_) {
    reserve(size_ * 2);
  }
  size_t k = 0;
  size_ += 1;
  T *tmp_vector = new T[size_];
  for (size_t i = 0; i < size_; i++) {
    if (i == position) {
      tmp_vector[i] = value;
      k--;
    } else {
      tmp_vector[i] = vector_[k];
    }
    k++;
  }
  delete[] vector_;
  vector_ = tmp_vector;
  return vector_ + position;
}

template <class T> void vector<T>::erase(iterator pos) {
  if (pos < begin() || pos > end()) {
    throw std::out_of_range("range check pos >= size_");
  }
  size_t position = pos - begin();
  size_t k = 0;
  T *tmp_vector = new T[size_ - 1];
  for (size_t i = 0; i < size_; i++) {
    if (i != position) {
      tmp_vector[k] = vector_[i];
      k++;
    }
  }
  delete[] vector_;
  vector_ = tmp_vector;
  size_ -= 1;
}

template <class T> void vector<T>::push_back(const_reference value) {
  if (size_ + 1 <= capacity_) {
    vector_[size_] = value;
    size_ += 1;
  } else {
    reserve(size_ * 2);
    vector_[size_] = value;
    size_ += 1;
  }
}

template <class T> void vector<T>::pop_back() {
  size_ = size_ > 0 ? size_ - 1 : 0;
}

template <class T> void vector<T>::swap(vector &other) {
  if (this != &other) {
    std::swap(vector_, other.vector_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }
}

template <class T> void vector<T>::zero_vector() {
  vector_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

} // namespace s21