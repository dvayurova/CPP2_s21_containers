#include "map.h"
namespace s21 {

template <class Key, class T>
map<Key, T>::map(std::initializer_list<value_type> const &items) {
  for (auto &it : items) {
    RedBlackTree<Key, T>::insert(it.first, it.second);
  }
}
template <class Key, class T> map<Key, T> &map<Key, T>::operator=(map &&other) {
  if (this != other) {
    this->root_ = this->nil_.get();
    swap(other);
    other.clear();
  }
  return *this;
}

template <class Key, class T>
map<Key, T> &map<Key, T>::operator=(const map &other) {
  if (this != other) {
    this->clear();
    this->root_ = copyTree(other.root_);
  }
  return *this;
}
} // namespace s21