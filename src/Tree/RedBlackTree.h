#ifndef TREE_REDBLACKTREE_H
#define TREE_REDBLACKTREE_H
#include <initializer_list>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

namespace s21 {
template <class Key, class Value = Key, class Compare = std::less<Key>>
class RedBlackTree {
  enum Color { BLACK, RED };

public:
  struct Node;
  struct ConstIterator;
  struct Iterator;
  using key_type = Key;
  using value_type = Value;
  using referance = value_type &;
  using const_referance = const value_type &;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  struct Node {
  public:
    Node() = default;
    explicit Node(value_type value)
        : key_(value), value_(value), color_(RED), left_(nil_.get()),
          right_(nil_.get()), parent_(nil_.get()){};
    explicit Node(key_type key, value_type value, Color color, Node *parent)
        : key_(key), value_(value), color_(color), left_(nil_.get()),
          right_(nil_.get()), parent_(parent){};

  private:
    Node(key_type key, value_type value)
        : key_(key), value_(value), color_(RED), left_(nil_.get()),
          right_(nil_.get()), parent_(nil_.get()){}; // D
    key_type key_;
    value_type value_;
    Color color_ = BLACK;
    Node *left_ = nullptr;
    Node *right_ = nullptr;
    Node *parent_ = nullptr;
    friend class RedBlackTree<Key, Value, Compare>;
  };

  struct ConstIterator {
  public:
    ConstIterator() = default;
    explicit ConstIterator(Node *node)
        : node_(node), past_node_(node->parent_){};
    bool operator!=(const const_iterator &other);
    bool operator==(const const_iterator &other);
    const_iterator &operator++();
    const_iterator operator++(int);
    const_iterator &operator--();
    const_iterator operator--(int);
    const Key &operator*();
    Node *get_node() const;

  private:
    Node *nextValue();
    Node *prevValue();

  protected:
    Node *node_ = nil_.get();
    Node *past_node_ = nil_.get();
  };

  struct Iterator : ConstIterator {
  public:
    Iterator() : ConstIterator(){};
    explicit Iterator(Node *node) : ConstIterator(node){};
  };

  RedBlackTree();
  RedBlackTree(std::initializer_list<value_type> const &items);
  RedBlackTree(const RedBlackTree &other);
  RedBlackTree &operator=(const RedBlackTree &other);
  RedBlackTree(RedBlackTree &&other);
  RedBlackTree &operator=(RedBlackTree &&other);
  ~RedBlackTree();

  iterator begin() const;
  iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  std::pair<iterator, bool> insert(const_referance value);
  void erase(iterator pos);
  void swap(RedBlackTree &other);
  void merge(RedBlackTree &other);

  iterator find(const Key &key) const;
  bool contains(const Key &key) const;

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  void printImageTree(Node *node, int depth = 0, char branch = ' ');
  void printSortTree(Node *node);
  Node *get_root() const;

private:
  Node *copyTree(Node *node, Node *new_parent = nil_.get());
  void balanceAfterInsert(Node *node);
  void balanceAfterErase(Node *node);
  void balanceAfterEraseLeft(Node *&node);
  void balanceAfterEraseRight(Node *&node);
  void rightRotate(Node *node);
  void leftRotate(Node *node);
  static Node *minValue(Node *node);
  static Node *maxValue(Node *node);
  void makeClearTree(Node *node);

protected:
  static std::unique_ptr<Node> nil_;
  Node *root_;
  Compare compare_ = Compare();
  std::pair<iterator, bool> insert(const Key &key,
                                   const Value &value); // D
};
} // namespace s21

#include "RedBlackTree.cpp"
#endif // TREE_REDBLACKTREE_H
