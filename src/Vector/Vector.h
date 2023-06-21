#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_

#include <memory>
#include <stdexcept>

namespace s21 {

template <class T> class vector {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<T> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector();

  vector<T> &operator=(vector &&v) noexcept;
  vector<T> &operator=(const vector &v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

private:
  T *vector_;
  size_type size_;
  size_type capacity_;
  void zero_vector();
};

} // namespace s21

#include "Vector.tpp"
#endif // SRC_VECTOR_H_
