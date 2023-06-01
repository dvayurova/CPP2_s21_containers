#include <iostream> // УДАЛИТЬ
#include <memory>
#include <string> // УДАЛИТЬ

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
  vector(size_type n);
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
  // iterator insert(iterator pos, const_reference value);
  void push_back(const_reference value);

private:
  T *vector_;
  size_type size_;
  size_type capacity_;
};

template <class T> vector<T>::vector() {
  vector_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <class T> vector<T>::vector(size_t n) {
  size_ = n;
  capacity_ = n;
  vector_ = new T[size_]{};
}

template <class T> vector<T>::vector(std::initializer_list<T> const &items) {
  size_ = items.size();
  capacity_ = size_;
  vector_ = new T[size_]{};
  std::copy(items.begin(), items.end(), vector_);
  // std::cout << "init constructor" << std::endl; // DELETE THIS
  // for (long unsigned int i = 0; i < size_; i++) {
  //   std::cout << vector_[i] << std::endl;
  // }
}

template <class T> vector<T>::vector(const vector &v) {
  size_ = v.size_;
  capacity_ = size_;
  vector_ = new T[size_]{};
  std::copy(v.vector_, v.vector_ + v.size_, vector_);
  // std::cout << "copy constructor" << std::endl;   // DELETE THIS
  // for (long unsigned int i = 0; i < size_; i++) { // DELETE THIS
  //   std::cout << vector_[i] << std::endl;
  // }
}

template <class T> vector<T>::vector(vector &&v) noexcept {
  size_ = v.size_;
  capacity_ = size_;
  vector_ = v.vector_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.vector_ = nullptr;
  // std::cout << "move constructor" << std::endl;   // DELETE THIS
  // for (long unsigned int i = 0; i < size_; i++) { // DELETE THIS
  //   std::cout << vector_[i] << std::endl;
  // }
}

template <class T> vector<T>::~vector() {
  delete[] vector_;
  size_ = 0;
  capacity_ = 0;
}

template <class T> vector<T> &vector<T>::operator=(vector &&v) noexcept {
  if (this != &v) {
    delete[] vector_;
    size_ = v.size_;
    capacity_ = size_;
    vector_ = v.vector_;
    v.size_ = 0;
    v.capacity_ = 0;
    v.vector_ = nullptr;
  }
  // std::cout << "move operator =" << std::endl; // DELETE THIS
  return *this;
}

template <class T> vector<T> &vector<T>::operator=(const vector &v) {
  if (this != &v) {
    delete[] vector_;
    vector_ = new T[v.capacity_];
    for (size_t i = 0; i < size_; i++) {
      vector_[i] = v.vector_[i];
    }
    size_ = v.size_;
    capacity_ = v.capacity_;
  }
  // std::cout << "copy operator =" << std::endl; // DELETE THIS
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

// template <class T>
// typename vector<T>::iterator vector<T>::insert(iterator pos,
//                                                const_reference value) {
//   if (pos >= begin() && pos <= end()) {

//   }

//   return pos;
// }

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

} // namespace s21

int main() {
  // s21::vector<int> my_vector(6);
  // std::cout << my_vector.size() << std::endl;
  // if (my_vector.empty() == false) {
  //   std::cout << "not empty" << std::endl;
  // }

  // s21::vector<int> my_vector = {6, 5, 3, 1};
  // std::cout << "size: " << my_vector.size() << std::endl;
  // std::cout << "max size: " << my_vector.max_size() << std::endl;
  // if (my_vector.empty() == false) {
  //   std::cout << "not empty" << std::endl;
  // }
  // std::cout << "copy" << std::endl;
  // s21::vector<int> cpy_vectr = my_vector;

  // s21::vector<int> my_vector(6);
  // std::cout << "Int vector \n Size: " << my_vector.size() << std::endl;
  // std::cout << "Max size: " << my_vector.max_size() << std::endl;
  // std::cout << "Capacity: " << my_vector.capacity() << std::endl;

  // s21::vector<char> char_vector(7);
  // std::cout << "Char vector \n Size: " << char_vector.size() << std::endl;
  // std::cout << "Max size: " << char_vector.max_size() << std::endl;
  // std::cout << "Capacity: " << char_vector.capacity() << std::endl;

  s21::vector<std::string> string_vector(7);
  std::cout << "String vector \n Size: " << string_vector.size() << std::endl;
  std::cout << "Capacity: " << string_vector.capacity() << std::endl;
  string_vector.push_back("last");
  std::cout << "push_back \n Size: " << string_vector.size() << std::endl;
  std::cout << "Capacity: " << string_vector.capacity() << std::endl;
  std::cout << string_vector.at(7) << std::endl;

  // s21::vector<int> numbers(6);
  // std::cout << "Current size: " << numbers.size() << std::endl;
  // std::cout << "Current capacity: " << numbers.capacity() << std::endl;

  // numbers.reserve(15);
  // std::cout << "reserve. New size: " << numbers.size() << std::endl;
  // std::cout << "New capacity: " << numbers.capacity() << std::endl;

  // numbers[2] = 7;
  // std::cout << "at " << numbers[2] << std::endl;
  // std::cout << "data: " << numbers.data() << std::endl;

  // numbers[3] = 8;
  // std::cout << "[] " << numbers[3] << std::endl;

  // numbers.shrink_to_fit();
  // std::cout << "shrink_to_fit. New size: " << numbers.size() << std::endl;
  // std::cout << "New capacity: " << numbers.capacity() << std::endl;

  // numbers = my_vector;
  // std::cout << "copy. New size: " << numbers.size() << std::endl;
  // std::cout << "New capacity: " << numbers.capacity() << std::endl;

  // s21::vector<char> letters = {'a', 'b', 'c'};
  // std::cout << "front: " << letters.front() << std::endl;
  // std::cout << "back: " << letters.back() << std::endl;

  // s21::vector<std::string> string_vector_two = string_vector;
  // std::cout << "data: " << letters.data() << std::endl;

  return 0;
}