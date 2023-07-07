#ifndef TREE_MULTISET_H
#define TREE_MULTISET_H
#include "RedBlackTree.h"

namespace s21 {
    template<class Key>
    class multiset : public RedBlackTree<Key, Key, std::less_equal<Key> > {
        using key_type = Key;
        using value_type = Key;
        using referance = value_type &;
        using const_referance = const value_type &;
        using iterator = typename RedBlackTree<Key, Key, std::less_equal<Key> >::Iterator;
        using const_iterator = typename RedBlackTree<Key, Key, std::less_equal<Key> >::ConstIterator;
        using size_type = std::size_t;

    public:
        multiset() : RedBlackTree<Key, Key, std::less_equal<Key> >() {};
        multiset(std::initializer_list<value_type> const &items) : RedBlackTree<Key, Key, std::less_equal<Key> >(
                items) {};
        multiset(const multiset &other) : RedBlackTree<Key, Key, std::less_equal<Key> >(other) {};
        multiset &operator=(const multiset &other);
        multiset(multiset &&other) : RedBlackTree<Key, Key, std::less_equal<Key> >(std::move(other)) {};
        multiset &operator=(multiset &&other);

        size_type count(const Key &key) const;
        std::pair<iterator, iterator> equal_range(const Key &key) const;
        iterator lower_bound(const Key &key) const;
        iterator upper_bound(const Key &key) const;
    };
} // s21
#include "Multiset.cpp"
#endif //TREE_MULTISET_H
