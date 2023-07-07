#ifndef TREE_SET_H
#define TREE_SET_H
#include "RedBlackTree.h"

namespace s21 {
    template<class Key>
    class set: public RedBlackTree<Key> {
        using key_type = Key;
        using value_type = Key;
        using referance = value_type &;
        using const_referance = const value_type &;
        using iterator = typename RedBlackTree<Key>::Iterator;
        using const_iterator = typename RedBlackTree<Key>::ConstIterator;
        using size_type = std::size_t;

    public:
        set(): RedBlackTree<key_type>(){};
        set(std::initializer_list<value_type> const &items): RedBlackTree<key_type>(items){};
        set(const set &other): RedBlackTree<key_type>(other){};
        set &operator=(const set &other);
        set(set &&other): RedBlackTree<key_type>(std::move(other)){};
        set &operator=(set &&other);
    };
} // s21

#include "Set.cpp"
#endif //TREE_SET_H
