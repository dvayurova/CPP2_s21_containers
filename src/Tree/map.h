#ifndef TREE_MAP_H_
#define TREE_MAP_H_
#include "RedBlackTree.h"

namespace s21 {
template <class Key, class T> class map : public RedBlackTree<Key, T> {
public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RedBlackTree<Key, T>::Iterator;
  using const_iterator = typename RedBlackTree<Key, T>::ConstIterator;
  using size_type = std::size_t;

  map() {}
  map(std::initializer_list<value_type> const &items);
  map(const map &m) : RedBlackTree<Key, T>(m){};
  map(map &&m) : RedBlackTree<Key, T>(std::move(m)){};
  ~map() {}

  map &operator=(const map &other);
  map &operator=(map &&other);

  std::pair<iterator, bool> insert(const value_type &value) {
    return RedBlackTree<Key, T>::insert(value.first, value.second);
  }
  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    return RedBlackTree<Key, T>::insert(key, obj);
  }
};

} // namespace s21

#include "map.tpp"
#endif // TREE_MAP_H_