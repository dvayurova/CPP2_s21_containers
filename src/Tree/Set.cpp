#include "set.h"

namespace s21 {
template <class Key> set<Key> &set<Key>::operator=(set &&other) {
  if (this != other) {
    this->root_ = this->nil_.get();
    swap(other);
    other.clear();
  }
  return *this;
}

template <class Key> set<Key> &set<Key>::operator=(const set &other) {
  if (this != other) {
    this->clear();
    this->root_ = copyTree(other.root_);
  }
  return *this;
}
} // namespace s21