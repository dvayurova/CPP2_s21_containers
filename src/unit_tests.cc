#include <gtest/gtest.h>

#include "List/List.h"
#include "Queue/Queue.h"
#include "Stack/Stack.h"
#include "Vector/Vector.h"
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

// Vector
class VectorTest : public ::testing::Test {
public:
  s21::vector<int> int_vector = {1, 2, 3, 4, 5, 6};
  s21::vector<float> float_vector = {1.342, 2.123, 3.978, 4.43, 5.3, 0};
  s21::vector<double> double_vector = {4.34, 42.1123, 23.123, 6.43, 5.31, 0.02};
  s21::vector<char> char_vector = {'a', 'b', 'c', 'd'};
  s21::vector<std::string> string_vector = {"one", "two", "three"};
  s21::vector<int> empty_vector;

  std::vector<int> int_vector_std = {1, 2, 3, 4, 5, 6};
  std::vector<float> float_vector_std = {1.342, 2.123, 3.978, 4.43, 5.3, 0};
  std::vector<double> double_vector_std = {4.34, 42.1123, 23.123,
                                           6.43, 5.31,    0.02};
  std::vector<char> char_vector_std = {'a', 'b', 'c', 'd'};
  std::vector<std::string> string_vector_std = {"one", "two", "three"};
  std::vector<int> empty_vector_std;
};

TEST_F(VectorTest, TestAt) {
  ASSERT_EQ(int_vector.at(4), int_vector_std.at(4));
}

TEST_F(VectorTest, TestReferenceOperator) {
  ASSERT_EQ(float_vector[3], float_vector_std[3]);
}

TEST_F(VectorTest, TestFront) {
  ASSERT_EQ(float_vector.front(), float_vector_std.front());
}

TEST_F(VectorTest, TestBack) {
  ASSERT_EQ(float_vector.back(), float_vector_std.back());
}

TEST_F(VectorTest, TestData) {
  s21::vector<int>::iterator it;
  it = int_vector.begin();
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.begin();
  ASSERT_EQ(it[3], it_std[3]);
}

TEST_F(VectorTest, TestBegin) {
  s21::vector<int>::iterator it;
  it = int_vector.begin();
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.begin();
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEnd) {
  s21::vector<int>::iterator it;
  it = int_vector.end() - 1;
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.end() - 1;
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEmpty) { ASSERT_TRUE(empty_vector.empty()); }
TEST_F(VectorTest, TestEmpty2) { ASSERT_FALSE(string_vector.empty()); }
TEST_F(VectorTest, TestSize) {
  ASSERT_EQ(string_vector_std.size(), string_vector.size());
}
TEST_F(VectorTest, TestMaxSize) {
  ASSERT_EQ(string_vector_std.max_size(), string_vector.max_size());
}
TEST_F(VectorTest, TestReserve) {
  double_vector.reserve(14);
  double_vector_std.reserve(14);
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
}
TEST_F(VectorTest, TestCapacity) {
  ASSERT_EQ(string_vector_std.capacity(), string_vector.capacity());
}
TEST_F(VectorTest, TestShrinkToFit) {
  double_vector.reserve(20);
  double_vector_std.reserve(20);
  double_vector.shrink_to_fit();
  double_vector_std.shrink_to_fit();
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
}

TEST_F(VectorTest, TestClear) {
  double_vector.clear();
  double_vector_std.clear();
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
}

TEST_F(VectorTest, TestInsert) {
  char_vector.insert(char_vector.end(), 't');
  char_vector_std.insert(char_vector_std.end(), 't');
  ASSERT_EQ(char_vector_std.back(), char_vector_std.back());
}

TEST_F(VectorTest, TestErase) {
  char_vector.erase(char_vector.end() - 1);
  char_vector_std.erase(char_vector_std.end() - 1);
  ASSERT_EQ(char_vector_std.back(), char_vector_std.back());
}

TEST_F(VectorTest, TestPushBack) {
  int_vector.push_back(481223);
  int_vector_std.push_back(481223);
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
}

TEST_F(VectorTest, TestPushBack2) {
  int_vector.reserve(20);
  int_vector_std.reserve(20);
  int_vector.push_back(20);
  int_vector_std.push_back(20);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
}

TEST_F(VectorTest, TestPopBack) {
  int_vector.pop_back();
  int_vector_std.pop_back();
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
}

TEST_F(VectorTest, TestSwap) {
  int_vector.swap(empty_vector);
  int_vector_std.swap(empty_vector_std);
  while (!empty_vector.empty() && !empty_vector_std.empty()) {
    ASSERT_EQ(empty_vector.back(), empty_vector_std.back());
    empty_vector.pop_back();
    empty_vector_std.pop_back();
  }
  ASSERT_EQ(int_vector.empty(), int_vector_std.empty());
  ASSERT_TRUE(int_vector.empty());
}

// Stack

TEST(StackTest, TestDefaultConstructor) {
  s21::stack<int> int_stack;
  std::stack<int> int_stack_original;
  ASSERT_EQ(int_stack.size(), int_stack_original.size());
}

TEST(StackTest, TestCopyConstructor) {
  s21::stack<int> my_stack;
  std::stack<int> original_stack;
  for (int i = 0; i <= 5; i++) {
    my_stack.push(i);
    original_stack.push(i);
  }
  s21::stack<int> my_stack_copy(my_stack);
  std::stack<int> original_stack_copy(original_stack);
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST(StackTest, TestMoveConstructor) {
  s21::stack<int> my_stack;
  std::stack<int> original_stack;
  for (int i = 0; i <= 5; i++) {
    my_stack.push(i);
    original_stack.push(i);
  }
  s21::stack<int> my_stack_copy(std::move(my_stack));
  std::stack<int> original_stack_copy(std::move(original_stack));
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST(StackTest, TestCopyOperator) {
  s21::stack<int> my_stack;
  std::stack<int> original_stack;
  for (int i = 0; i <= 5; i++) {
    my_stack.push(i);
    original_stack.push(i);
  }
  s21::stack<int> my_stack_copy = my_stack;
  std::stack<int> original_stack_copy = original_stack;
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST(StackTest, TestMoveOperator) {
  s21::stack<int> my_stack;
  std::stack<int> original_stack;
  for (int i = 0; i <= 5; i++) {
    my_stack.push(i);
    original_stack.push(i);
  }
  s21::stack<int> my_stack_copy = std::move(my_stack);
  std::stack<int> original_stack_copy = std::move(original_stack);
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST(StackTest, TestTop) {
  s21::stack<int> my_stack;
  std::stack<int> original_stack;
  for (int i = 0; i <= 42; i += 4) {
    my_stack.push(i);
    original_stack.push(i);
  }
  ASSERT_EQ(my_stack.top(), original_stack.top());
}

TEST(StackTest, TestEmpty) {
  s21::stack<int> int_stack;
  std::stack<int> int_stack_original;
  ASSERT_EQ(int_stack.empty(), int_stack_original.empty());
  ASSERT_TRUE(int_stack.empty());
  ASSERT_TRUE(int_stack_original.empty());
}

TEST(StackTest, TestSize) {
  s21::stack<std::string> my_stack;
  std::stack<std::string> original_stack;
  for (int i = 0; i <= 5; i += 4) {
    my_stack.push("string");
    original_stack.push("string");
  }
  ASSERT_EQ(my_stack.size(), original_stack.size());
}

TEST(StackTest, TestSwap) {
  s21::stack<int> int_stack;
  std::stack<int> int_stack_original;
  s21::stack<int> empty_stack;
  std::stack<int> empty_stack_original;
  int_stack.push(324);
  int_stack.push(768678);
  int_stack.push(54342);
  int_stack.push(6563);
  int_stack_original.push(324);
  int_stack_original.push(768678);
  int_stack_original.push(54342);
  int_stack_original.push(6563);
  int_stack.swap(empty_stack);
  int_stack_original.swap(empty_stack_original);
  while (!int_stack.empty() && !int_stack_original.empty()) {
    ASSERT_EQ(int_stack.top(), int_stack_original.top());
    int_stack.pop();
    int_stack_original.pop();
  }
  ASSERT_EQ(int_stack.empty(), int_stack_original.empty());
}

// Queue

TEST(QueueTest, TestDefaultConstructor) {
  s21::queue<int> int_queue;
  std::queue<int> int_queue_original;
  ASSERT_EQ(int_queue.size(), int_queue_original.size());
}

TEST(QueueTest, TestCopyConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> original_queue;
  for (int i = 0; i <= 5; i++) {
    my_queue.push(i);
    original_queue.push(i);
  }
  s21::queue<int> my_queue_copy(my_queue);
  std::queue<int> original_queue_copy(original_queue);
  while (!my_queue_copy.empty() && !original_queue_copy.empty()) {
    ASSERT_EQ(my_queue_copy.front(), original_queue_copy.front());
    ASSERT_EQ(my_queue_copy.back(), original_queue_copy.back());
    my_queue_copy.pop();
    original_queue_copy.pop();
  }
  ASSERT_EQ(my_queue_copy.empty(), original_queue_copy.empty());
}

TEST(QueueTest, TestMoveConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> original_queue;
  for (int i = 0; i <= 5; i++) {
    my_queue.push(i);
    original_queue.push(i);
  }
  s21::queue<int> my_queue_copy(std::move(my_queue));
  std::queue<int> original_queue_copy(std::move(original_queue));
  while (!my_queue_copy.empty() && !original_queue_copy.empty()) {
    ASSERT_EQ(my_queue_copy.front(), original_queue_copy.front());
    ASSERT_EQ(my_queue_copy.back(), original_queue_copy.back());
    my_queue_copy.pop();
    original_queue_copy.pop();
  }
  ASSERT_EQ(my_queue_copy.empty(), original_queue_copy.empty());
}

TEST(QueueTest, TestCopyOperator) {
  s21::queue<int> my_queue;
  std::queue<int> original_queue;
  for (int i = 0; i <= 5; i++) {
    my_queue.push(i);
    original_queue.push(i);
  }
  s21::queue<int> my_queue_copy = my_queue;
  std::queue<int> original_queue_copy = original_queue;
  while (!my_queue_copy.empty() && !original_queue_copy.empty()) {
    ASSERT_EQ(my_queue_copy.front(), original_queue_copy.front());
    ASSERT_EQ(my_queue_copy.back(), original_queue_copy.back());
    my_queue_copy.pop();
    original_queue_copy.pop();
  }
  ASSERT_EQ(my_queue_copy.empty(), original_queue_copy.empty());
}

TEST(QueueTest, TestMoveOperator) {
  s21::queue<int> my_queue;
  std::queue<int> original_queue;
  for (int i = 0; i <= 5; i++) {
    my_queue.push(i);
    original_queue.push(i);
  }
  s21::queue<int> my_queue_copy = std::move(my_queue);
  std::queue<int> original_queue_copy = std::move(original_queue);
  while (!my_queue_copy.empty() && !original_queue_copy.empty()) {
    ASSERT_EQ(my_queue_copy.front(), original_queue_copy.front());
    ASSERT_EQ(my_queue_copy.back(), original_queue_copy.back());
    my_queue_copy.pop();
    original_queue_copy.pop();
  }
  ASSERT_EQ(my_queue_copy.empty(), original_queue_copy.empty());
}

TEST(QueueTest, TestEmpty) {
  s21::queue<int> int_queue;
  std::queue<int> int_queue_original;
  ASSERT_EQ(int_queue.empty(), int_queue_original.empty());
  ASSERT_TRUE(int_queue.empty());
  ASSERT_TRUE(int_queue_original.empty());
}

TEST(QueueTest, TestSize) {
  s21::queue<std::string> my_queue;
  std::queue<std::string> original_queue;
  for (int i = 0; i <= 5; i += 4) {
    my_queue.push("string");
    original_queue.push("string");
  }
  ASSERT_EQ(my_queue.size(), original_queue.size());
}

TEST(QueueTest, TestSwap) {
  s21::queue<int> int_queue;
  std::queue<int> int_queue_original;
  s21::queue<int> empty_queue;
  std::queue<int> empty_queue_original;
  int_queue.push(324);
  int_queue.push(768678);
  int_queue.push(54342);
  int_queue.push(6563);
  int_queue_original.push(324);
  int_queue_original.push(768678);
  int_queue_original.push(54342);
  int_queue_original.push(6563);
  int_queue.swap(empty_queue);
  int_queue_original.swap(empty_queue_original);
  while (!int_queue.empty() && !int_queue_original.empty()) {
    ASSERT_EQ(int_queue.front(), int_queue_original.front());
    ASSERT_EQ(int_queue.back(), int_queue_original.back());
    int_queue.pop();
    int_queue_original.pop();
  }
  ASSERT_EQ(int_queue.empty(), int_queue_original.empty());
}

// List

TEST(TestList, Constructor_Default) {
  std::list<int> list_1;
  s21::list<int> list_2;
  EXPECT_EQ(list_1.empty(), list_2.empty());
  EXPECT_EQ(list_1.size(), list_2.size());
}

TEST(TestList, Constructor_Size) {
  size_t count = 4;
  std::list<int> list_1(count);
  s21::list<int> list_2(count);
  EXPECT_EQ(list_1.size(), list_2.size());
}

TEST(TestList, Constructor_Init) {
  std::list<int> list_1{1, 2, 3};
  s21::list<int> list_2{1, 2, 3};
  auto iter_2 = list_2.begin();
  for (auto i = list_1.begin(); i != list_1.end(); ++i, ++iter_2) {
    EXPECT_EQ(*i, *iter_2);
  }
}

TEST(TestList, Constructor_Copy) {
  std::list<int> listCopy_1{1, 2, 3};
  std::list<int> list_1(listCopy_1);
  std::list<int> list_11{5, 6, 7};
  list_11 = list_1;

  s21::list<int> listCopy_2{1, 2, 3};
  s21::list<int> list_2(listCopy_2);
  s21::list<int> list_22{5, 6, 7};
  list_22 = list_2;

  EXPECT_EQ(list_1.size(), list_2.size());
  EXPECT_EQ(list_11.size(), list_22.size());
  EXPECT_EQ(listCopy_1.size(), listCopy_2.size());
  auto it = list_2.begin();
  auto it2 = list_11.begin();
  for (auto i = list_1.begin(); i != list_1.begin(); ++i, ++it) {
    EXPECT_EQ(*i, *it);
  }
  for (auto i = list_11.begin(); i != list_11.begin(); ++i, ++it2) {
    EXPECT_EQ(*i, *it2);
  }
}

TEST(TestList, Constructor_Move) {
  std::list<int> listCopy_1{1, 2, 3};
  std::list<int> list_1(std::move(listCopy_1));
  s21::list<int> listCopy_2{1, 2, 3};
  s21::list<int> list_2(std::move(listCopy_2));
  EXPECT_EQ(list_1.size(), list_2.size());
  EXPECT_EQ(listCopy_1.size(), listCopy_2.size());
  auto it = list_2.begin();
  for (auto i = list_1.begin(); i != list_1.begin(); ++i, ++it) {
    EXPECT_EQ(*i, *it);
  }
  std::list<int> list11{5, 6, 7};
  list11 = std::move(list_1);
  s21::list<int> list22{5, 6, 7};
  list22 = std::move(list_2);
  EXPECT_EQ(list_1.size(), list_2.size());
  EXPECT_EQ(list11.size(), list22.size());
  auto it2 = list22.begin();
  for (auto i = list11.begin(); i != list11.begin(); ++i, ++it) {
    EXPECT_EQ(*i, *it2);
  }
}

TEST(TestList, Test_PushFront) {
  std::list<int> list1;
  s21::list<int> list2;
  auto it = list1.begin();
  auto it2 = list2.begin();
  for (int i = 0; i < 5; ++i, ++it, ++it2) {
    list1.push_front(i);
    list2.push_front(i);
    EXPECT_EQ(list1.size(), list2.size());
    EXPECT_EQ(*it, *it2);
  }
}

TEST(TestList, Test_PushBack) {
  std::list<std::string> list1 = {"I Love School"};
  s21::list<std::string> list2 = {"I Love School"};
  list1.push_back(" S21");
  list2.push_back(" S21");
  EXPECT_EQ(list1.size(), list2.size());
  auto it = list1.begin();
  for (auto i = list1.begin(); i != list1.end(); ++i, ++it) {
    EXPECT_EQ(*it, *i);
  }
}

TEST(TestList, Test_PopFront) {
  std::list<int> list1 = {1, 2, 3, 4, 5};
  s21::list<int> list2 = {1, 2, 3, 4, 5};
  auto it = list1.begin();
  auto it2 = list2.begin();
  EXPECT_EQ(list1.size(), list2.size());
  EXPECT_EQ(*it, *it2);
  list1.pop_front();
  list2.pop_front();
  it = list1.begin();
  it2 = list2.begin();
  EXPECT_EQ(list1.size(), list2.size());
  EXPECT_EQ(*it, *it2);
}

TEST(TestList, Test_PopBack) {
  std::list<int> list1 = {1, 2, 3, 4, 5};
  s21::list<int> list2 = {1, 2, 3, 4, 5};
  auto it = list1.end();
  auto it2 = list2.end();
  EXPECT_EQ(list1.size(), list2.size());
  EXPECT_EQ(*(++it), *(++it2));
  list1.pop_back();
  list2.pop_back();
  EXPECT_EQ(list1.size(), list2.size());
  EXPECT_EQ(*(++it), *(++it2));
}

TEST(TestList, Test_FrontBack) {
  std::list<char> list1 = {'D', 'A', 'G'};
  s21::list<char> list2 = {'D', 'A', 'G'};
  EXPECT_EQ(list1.front(), list2.front());
  EXPECT_EQ(list1.back(), list2.back());
}

TEST(TestList, Test_Insert) {
  std::list<std::string> list1 = {"I love ", " s21"};
  s21::list<std::string> list2 = {"I love ", " s21"};
  auto it = --list1.end();
  auto it2 = --list2.end();
  list1.insert(it, "School");
  list2.insert(it2, "School");
  it = list1.begin();
  for (auto i = list1.begin(); i != list1.end(); ++i, ++it) {
    EXPECT_EQ(*it, *i);
  }
  EXPECT_EQ(list1.size(), list2.size());
}

TEST(TestList, Test_Clear) {
  std::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {1, 2, 3};
  list1.clear();
  list2.clear();
  auto it = list1.end();
  auto it2 = list2.end();
  EXPECT_EQ(*it, *it2);
  EXPECT_EQ(list1.size(), list2.size());
}

TEST(TestList, Test_Erase) {
  std::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {1, 2, 3};
  auto it = ++list1.begin();
  auto it2 = ++list2.begin();
  list1.erase(it);
  list2.erase(it2);
  EXPECT_EQ(list1.size(), list2.size());
  it2 = list2.begin();
  for (auto i = list1.begin(); i != list1.end(); ++i, ++it2) {
    EXPECT_EQ(*it2, *i);
  }
}

TEST(TestList, Test_Swap) {
  std::list<char> list1;
  std::list<char> list11 = {'x', 'y'};
  s21::list<char> list2;
  s21::list<char> list22 = {'x', 'y'};
  list1.swap(list11);
  list2.swap(list22);
  auto it1 = list1.begin();
  auto it2 = list2.begin();
  auto it22 = list22.begin();
  EXPECT_EQ(list1.size(), list2.size());
  EXPECT_EQ(list11.size(), list22.size());
  for (auto it11 = list11.begin(); it11 != list11.end();
       ++it11, ++it1, ++it2, ++it22) {
    EXPECT_EQ(*it1, *it2);
    EXPECT_EQ(*it11, *it22);
  }
}

TEST(TestList, Test_Merge) {
  std::list<int> list1 = {4, 5, 6};
  std::list<int> list11 = {5, 0, 2};

  s21::list<int> list2 = {4, 5, 6};
  s21::list<int> list22 = {5, 0, 2};

  list1.merge(list11);
  list2.merge(list22);

  EXPECT_EQ(list11.size(), list22.size());

  auto it = list1.begin();
  for (auto i = list1.begin(); i != list1.end(); ++i, ++it) {
    EXPECT_EQ(*i, *it);
  }
}

TEST(TestList, Test_Splice) {
  std::list<std::string> list1 = {"I study ", " in Kazan"};
  std::list<std::string> list11 = {" at school ", "s21"};

  s21::list<std::string> list2 = {"I study ", " in Kazan"};
  s21::list<std::string> list22 = {" at school ", "s21"};

  auto it1 = list1.begin();
  ++it1;
  list1.splice(it1, list11);

  auto it2 = list2.begin();
  ++it2;
  list2.splice(it2, list22);
  it1 = list1.begin();
  it2 = list2.begin();
  EXPECT_EQ(list11.size(), list22.size());
  for (; it1 != list1.end(); it1++, it2++) {
    EXPECT_EQ(*it1, *it2);
  }
}

TEST(TestList, Test_Reverse) {
  std::list<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::list<int> list2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  list1.reverse();
  list2.reverse();
  auto it2 = list2.begin();
  for (auto it1 = list1.begin(); it1 != list1.end(); ++it2, ++it1) {
    EXPECT_EQ(*it1, *it2);
  }
}

TEST(TestList, Test_Unique) {
  std::list<char> list1 = {'a', 'b', 'b', 'a', 'c', 'x',
                           'y', 'y', 'y', 'z', 'z'};
  s21::list<char> list2 = {'a', 'b', 'b', 'a', 'c', 'x',
                           'y', 'y', 'y', 'z', 'z'};
  list1.unique();
  list2.unique();
  auto it1 = list1.begin();
  EXPECT_EQ(list1.size(), list2.size());
  for (auto it2 = list2.begin(); it2 != list2.end(); ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
  }
}

TEST(TestList, Test_Sort) {
  std::list<char> list1 = {'y', 'c', 'z', 'a', 'a', 'x',
                           'w', 'v', 't', 'e', 'q'};
  s21::list<char> list2 = {'y', 'c', 'z', 'a', 'a', 'x',
                           'w', 'v', 't', 'e', 'q'};
  list1.sort();
  list2.sort();
  auto it1 = list1.begin();
  EXPECT_EQ(list1.size(), list2.size());
  for (auto it2 = list2.begin(); it2 != list2.end(); ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
