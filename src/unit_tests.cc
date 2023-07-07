#include <gtest/gtest.h>

#include "List/List.h"
#include "Queue/Queue.h"
#include "Stack/stack.h"
#include "Tree/map.h"
#include "Tree/multiset.h"
#include "Tree/set.h"
#include "Vector/vector.h"
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

// Vector
class VectorTest : public ::testing::Test {
public:
  s21::vector<int> int_vector = {1, 2, 3, 4, 5, 6};
  s21::vector<int> const const_vector = {1, 2, 3, 4, 5, 6};
  s21::vector<float> float_vector = {1.342, 2.123, 3.978, 4.43, 5.3, 0};
  s21::vector<double> double_vector = {4.34, 42.1123, 23.123, 6.43, 5.31, 0.02};
  s21::vector<char> char_vector = {'a', 'b', 'c', 'd'};
  s21::vector<std::string> string_vector = {"one", "two", "three"};
  s21::vector<int> empty_vector;

  std::vector<int> int_vector_std = {1, 2, 3, 4, 5, 6};
  std::vector<int> const const_vector_std = {1, 2, 3, 4, 5, 6};
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

TEST_F(VectorTest, TestAtConst) {
  ASSERT_EQ(const_vector.at(4), const_vector_std.at(4));
}

TEST_F(VectorTest, TestReferenceOperator) {
  ASSERT_EQ(float_vector[3], float_vector_std[3]);
}

TEST_F(VectorTest, TestReferenceOperatorConst) {
  ASSERT_EQ(const_vector[3], const_vector_std[3]);
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

TEST_F(VectorTest, TestBeginConst) {
  s21::vector<int>::const_iterator it;
  it = const_vector.begin();
  std::vector<int>::const_iterator it_std;
  it_std = const_vector_std.begin();
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEnd) {
  s21::vector<int>::iterator it;
  it = int_vector.end() - 1;
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.end() - 1;
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEndConst) {
  s21::vector<int>::const_iterator it;
  it = const_vector.end() - 1;
  std::vector<int>::const_iterator it_std;
  it_std = const_vector_std.end() - 1;
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEmpty) { ASSERT_TRUE(empty_vector.empty()); }
TEST_F(VectorTest, TestEmpty2) { ASSERT_FALSE(string_vector.empty()); }
TEST_F(VectorTest, TestEmptyConst) { ASSERT_FALSE(const_vector.empty()); }
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
  ASSERT_EQ(double_vector.capacity(), double_vector_std.capacity());
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
  ASSERT_EQ(double_vector.capacity(), double_vector_std.capacity());
}

TEST_F(VectorTest, TestClear) {
  double_vector.clear();
  double_vector_std.clear();
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
  ASSERT_EQ(double_vector.capacity(), double_vector_std.capacity());
}

TEST_F(VectorTest, TestInsert) {
  char_vector.insert(char_vector.end(), 't');
  char_vector_std.insert(char_vector_std.end(), 't');
  ASSERT_EQ(char_vector_std.back(), char_vector_std.back());
  ASSERT_EQ(char_vector_std.size(), char_vector_std.size());
  ASSERT_EQ(char_vector_std.capacity(), char_vector_std.capacity());
}

TEST_F(VectorTest, TestErase) {
  char_vector.erase(char_vector.end() - 1);
  char_vector_std.erase(char_vector_std.end() - 1);
  ASSERT_EQ(char_vector_std.back(), char_vector_std.back());
  ASSERT_EQ(char_vector_std.size(), char_vector_std.size());
  ASSERT_EQ(char_vector_std.capacity(), char_vector_std.capacity());
}

TEST_F(VectorTest, TestPushBack) {
  int_vector.push_back(481223);
  int_vector_std.push_back(481223);
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
}

TEST_F(VectorTest, TestPushBack2) {
  int_vector.reserve(20);
  int_vector_std.reserve(20);
  int_vector.push_back(20);
  int_vector_std.push_back(20);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
}

TEST_F(VectorTest, TestPopBack) {
  int_vector.pop_back();
  int_vector_std.pop_back();
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
}

TEST_F(VectorTest, TestSwap) {
  int_vector.swap(empty_vector);
  int_vector_std.swap(empty_vector_std);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  ASSERT_EQ(empty_vector.size(), empty_vector_std.size());
  ASSERT_EQ(empty_vector.capacity(), empty_vector_std.capacity());
  while (!empty_vector.empty() && !empty_vector_std.empty()) {
    ASSERT_EQ(empty_vector.back(), empty_vector_std.back());
    empty_vector.pop_back();
    empty_vector_std.pop_back();
  }
  ASSERT_EQ(int_vector.empty(), int_vector_std.empty());
  ASSERT_TRUE(int_vector.empty());
}

TEST_F(VectorTest, TestInsertMany) {
  int_vector.insert_many(int_vector.begin() + 1, 162342);
  int_vector_std.emplace(int_vector_std.begin() + 1, 162342);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  while (!int_vector.empty() && !int_vector_std.empty()) {
    ASSERT_EQ(int_vector.back(), int_vector_std.back());
    int_vector.pop_back();
    int_vector_std.pop_back();
  }
}

TEST_F(VectorTest, TestInsertManyBack) {
  int_vector.insert_many_back(162342);
  int_vector_std.emplace_back(162342);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  while (!int_vector.empty() && !int_vector_std.empty()) {
    ASSERT_EQ(int_vector.back(), int_vector_std.back());
    int_vector.pop_back();
    int_vector_std.pop_back();
  }
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

TEST(StackTest, TestEmplaceFront) {
  s21::stack<int> int_stack;
  std::stack<int> int_stack_original;
  int_stack.push(324);
  int_stack.push(768678);
  int_stack.insert_many_front(481223);
  int_stack_original.push(324);
  int_stack_original.push(768678);
  int_stack_original.emplace(481223);
  while (!int_stack.empty() && !int_stack_original.empty()) {
    ASSERT_EQ(int_stack.top(), int_stack_original.top());
    int_stack.pop();
    int_stack_original.pop();
  }
  ASSERT_EQ(int_stack.empty(), int_stack_original.empty());
}

// Queue

TEST(TestQueue, Constructor_Default) {
  std::queue<int> queue_1;
  s21::queue<int> queue_2;
  EXPECT_EQ(queue_1.empty(), queue_2.empty());
  EXPECT_EQ(queue_1.size(), queue_2.size());
}

TEST(TestQueue, Constructor_Init) {
  std::deque<int> numbers = {1, 2, 3};
  std::queue<int> std_queue{numbers};
  s21::queue<int> s21_queue = {1, 2, 3};
  while (!s21_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(TestQueue, Constructor_Copy) {
  std::deque<int> numbers = {1, 2, 3};
  std::queue<int> std_queue{numbers};
  std::queue<int> std_queue_2(std_queue);
  std::queue<int> std_queue_3;
  std_queue_3 = std_queue_2;

  s21::queue<int> s21_queue{1, 2, 3};
  s21::queue<int> s21_queue_2(s21_queue);
  s21::queue<int> s21_queue_3;
  s21_queue_3 = s21_queue_2;

  EXPECT_EQ(std_queue.size(), s21_queue.size());
  EXPECT_EQ(std_queue_2.size(), std_queue_2.size());
  EXPECT_EQ(std_queue_3.size(), s21_queue_3.size());
  while (!s21_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
    EXPECT_EQ(s21_queue_3.front(), std_queue_3.front());
    s21_queue.pop();
    std_queue.pop();
    s21_queue_2.pop();
    std_queue_2.pop();
    s21_queue_3.pop();
    std_queue_3.pop();
  }
}

TEST(TestQueue, Constructor_Move) {
  std::deque<int> numbers = {1, 2, 3};
  std::queue<int> std_queue{numbers};
  std::queue<int> std_queue_2(std::move(std_queue));
  s21::queue<int> s21_queue{1, 2, 3};
  s21::queue<int> s21_queue_2(std::move(s21_queue));
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
  while (!s21_queue_2.empty()) {
    EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
    s21_queue_2.pop();
    std_queue_2.pop();
  }

  std::queue<int> std_queue_3{numbers};
  std_queue_2 = std::move(std_queue_3);

  s21::queue<int> s21_queue_3{1, 2, 3};
  s21_queue_2 = std::move(s21_queue_3);

  EXPECT_EQ(s21_queue_3.empty(), std_queue_3.empty());
  while (!s21_queue_2.empty()) {
    EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
    s21_queue_2.pop();
    std_queue_2.pop();
  }
}

TEST(TestQueue, Test_Push) {
  std::queue<int> queue_1;
  s21::queue<int> queue_2;
  for (int i = 0; i < 5; ++i) {
    queue_1.push(i);
    queue_2.push(i);
    EXPECT_EQ(queue_1.size(), queue_2.size());
    EXPECT_EQ(queue_1.back(), queue_2.back());
  }
}

TEST(TestQueue, Test_Push_2) {
  std::deque<std::string> str = {"I Love School"};
  std::queue<std::string> queue_1{str};
  s21::queue<std::string> queue_2 = {"I Love School"};
  queue_1.push(" S21");
  queue_2.push(" S21");
  EXPECT_EQ(queue_1.size(), queue_2.size());
  while (!queue_2.empty()) {
    EXPECT_EQ(queue_1.front(), queue_2.front());
    queue_1.pop();
    queue_2.pop();
  }
}

TEST(TestQueue, Test_Swap) {
  std::deque<std::string> str = {"School S21", " in ", "Kazan"};
  std::queue<std::string> std_queue{str};
  s21::queue<std::string> s21_queue = {"School S21", " in ", "Kazan"};
  std::deque<std::string> str_2 = {"I ", "from ", "Dagestan"};
  std::queue<std::string> std_queue_2{str_2};
  s21::queue<std::string> s21_queue_2 = {"I ", "from ", "Dagestan"};
  std_queue.swap(std_queue_2);
  s21_queue.swap(s21_queue_2);
  while (!std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
  while (!std_queue_2.empty()) {
    EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
    s21_queue_2.pop();
    std_queue_2.pop();
  }
}

TEST(TestQueue, Test_InsertManyBack) {
  std::deque<int> numbers = {1, 2, 3, 4, 5};
  std::queue<int> std_queue{numbers};
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  for (int i = 6; i < 8; ++i) {
    std_queue.push(i);
  }
  s21_queue.insert_many_back(6, 7, 8);
  while (!std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
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
TEST(TestList, Test_InsertMany) {
  std::list<int> std_lst{1, 2, 3, 4, 5};
  auto std_it = std_lst.begin();
  ++std_it;
  ++std_it;
  auto std_i = std_it;
  for (int data = 6; data < 9; ++data) {
    std_i = std_lst.insert(std_it, data);
  }
  s21::list<int> s21_lst{1, 2, 3, 4, 5};
  auto s21_it = s21_lst.begin();
  ++s21_it;
  ++s21_it;
  auto s21_i = s21_lst.insert_many(s21_it, 6, 7, 8);
  std_it = std_lst.begin();
  for (s21_it = s21_lst.begin(); s21_it != s21_lst.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
  EXPECT_EQ(*s21_i, *std_i);

  for (int data = -2; data < 1; ++data) {
    std_lst.push_front(data);
  }
  s21_lst.insert_many_front(-2, -1, 0);
  std_it = std_lst.begin();
  for (s21_it = s21_lst.begin(); s21_it != s21_lst.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }

  for (int data = 10; data < 15; ++data) {
    std_lst.push_back(data);
  }
  s21_lst.insert_many_back(10, 11, 12, 13, 14);
  std_it = std_lst.begin();
  for (s21_it = s21_lst.begin(); s21_it != s21_lst.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

// Set

TEST(SetTest, TestDefaultConstructor) {
  s21::set<int> empty_set;
  EXPECT_TRUE(empty_set.empty());
}

TEST(SetTest, TestInitializerList) {
  s21::set<int> int_set = {4, 8, 15, 16, 23, 42};
  std::set<int> int_set_std = {4, 8, 15, 16, 23, 42};
  EXPECT_EQ(int_set.size(), int_set_std.size());
}

TEST(SetTest, TestCopyConstructor) {
  s21::set<int> int_set = {4, 8, 15, 16, 23, 42};
  s21::set<int> copy_set(int_set);
  auto i = int_set.begin();
  auto j = copy_set.begin();
  while (i != int_set.end() && j != copy_set.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
}

TEST(SetTest, TestMoveConstructor) {
  s21::set<char> char_set = {'a', 'b', 'c'};
  s21::set<char> copy_set(std::move(char_set));
  std::set<char> char_set_std = {'a', 'b', 'c'};
  std::set<char> copy_set_std(std::move(char_set_std));
  EXPECT_EQ(char_set.empty(), char_set_std.empty());
  EXPECT_EQ(copy_set.size(), copy_set_std.size());
}

TEST(SetTest, TestCopyOperator) {
  s21::set<int> int_set = {4, 8, 15, 16, 23, 42};
  s21::set<int> copy_set = int_set;
  auto i = int_set.begin();
  auto j = copy_set.begin();
  while (i != int_set.end() && j != copy_set.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
}

TEST(SetTest, TestMoveOperator) {
  s21::set<char> char_set = {'a', 'b', 'c'};
  s21::set<char> copy_set = std::move(char_set);
  std::set<char> char_set_std = {'a', 'b', 'c'};
  std::set<char> copy_set_std = std::move(char_set_std);
  EXPECT_EQ(char_set.empty(), char_set_std.empty());
  EXPECT_EQ(copy_set.size(), copy_set_std.size());
}

TEST(SetTest, TestEmpty) {
  s21::set<int> empty_set;
  EXPECT_TRUE(empty_set.empty());
}

TEST(SetTest, TestSize) {
  s21::set<std::string> string_set = {"one", "two", "three"};
  std::set<std::string> string_set_std = {"one", "two", "three"};
  EXPECT_EQ(string_set.size(), string_set_std.size());
}

TEST(SetTest, TestMaxSize) {
  s21::set<int> string_set = {1, 2, 3};
  std::set<int> string_set_std = {1, 2, 3};
  EXPECT_EQ(string_set.max_size(), string_set_std.max_size());
}

TEST(SetTest, TestClear) {
  s21::set<std::string> string_set = {"one", "two", "three"};
  std::set<std::string> string_set_std = {"one", "two", "three"};
  string_set.clear();
  string_set_std.clear();
  EXPECT_EQ(string_set.empty(), string_set_std.empty());
  EXPECT_EQ(string_set.size(), string_set_std.size());
}

TEST(SetTest, TestInsert) {
  s21::set<int> int_set = {4, 8, 15, 16, 23, 42};
  std::set<int> int_set_std = {4, 8, 15, 16, 23, 42};
  int_set.insert(36);
  int_set_std.insert(36);
  auto i = int_set.begin();
  std::set<int>::iterator j = int_set_std.begin();
  while (i != int_set.end() && j != int_set_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
}

TEST(SetTest, TestErase) {
  s21::set<int> int_set = {4, 8, 15, 16, 23, 42};
  std::set<int> int_set_std = {4, 8, 15, 16, 23, 42};
  int_set.erase(int_set.begin());
  int_set_std.erase(int_set_std.begin());
  auto i = int_set.begin();
  std::set<int>::iterator j = int_set_std.begin();
  while (i != int_set.end() && j != int_set_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  EXPECT_EQ(int_set.size(), int_set_std.size());
}

TEST(SetTest, TestSwap) {
  s21::set<int> int_set = {4, 8, 15, 16, 23, 42};
  std::set<int> int_set_std = {4, 8, 15, 16, 23, 42};
  s21::set<int> empty_set;
  std::set<int> empty_set_std;
  int_set.swap(empty_set);
  int_set_std.swap(empty_set_std);
  auto i = empty_set.begin();
  std::set<int>::iterator j = empty_set_std.begin();
  while (i != empty_set.end() && j != empty_set_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  EXPECT_EQ(int_set.size(), int_set_std.size());
  EXPECT_EQ(empty_set.size(), empty_set_std.size());
  EXPECT_TRUE(int_set.empty());
}

TEST(SetTest, TestMerge) {
  s21::set<int> first = {4, 8, 15, 16, 23, 42};
  std::set<int> first_std = {4, 8, 15, 16, 23, 42};
  s21::set<int> second = {1, 2, 3, 4};
  std::set<int> second_std = {1, 2, 3, 4};
  first.merge(second);
  first_std.merge(second_std);
  auto i = first.begin();
  std::set<int>::iterator j = first_std.begin();
  while (i != first.end() && j != first_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  EXPECT_EQ(first.size(), first_std.size());
}

TEST(SetTest, TestFind) {
  s21::set<int> int_set = {1, 2, 3, 4, 5};
  std::set<int> int_set_std = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_EQ(*(int_set.find(i)), *(int_set_std.find(i)));
  }
}

TEST(SetTest, TestContains) {
  s21::set<int> int_set = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_TRUE(int_set.contains(i));
  }
}

// Multiset

TEST(MultisetTest, TestDefaultConstructor) {
  s21::multiset<int> empty_set;
  EXPECT_TRUE(empty_set.empty());
}

TEST(MultisetTest, TestInitializerList) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  std::multiset<int> int_set_std = {4, 8, 15, 16, 23, 42};
  EXPECT_EQ(int_set.size(), int_set_std.size());
}

TEST(MultisetTest, TestCopyConstructor) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  s21::multiset<int> copy_set(int_set);
  auto i = int_set.begin();
  auto j = copy_set.begin();
  while (i != int_set.end() && j != copy_set.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
}

TEST(MultisetTest, TestMoveConstructor) {
  s21::multiset<char> char_set = {'a', 'b', 'c'};
  s21::multiset<char> copy_set(std::move(char_set));
  EXPECT_TRUE(char_set.empty());
  EXPECT_EQ(copy_set.size(), 3);
}

TEST(MultisetTest, TestCopyOperator) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  s21::multiset<int> copy_set = int_set;
  auto i = int_set.begin();
  auto j = copy_set.begin();
  while (i != int_set.end() && j != copy_set.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
}

TEST(MultisetTest, TestMoveOperator) {
  s21::multiset<char> char_set = {'a', 'b', 'c'};
  s21::multiset<char> copy_set = std::move(char_set);
  EXPECT_TRUE(char_set.empty());
  EXPECT_EQ(copy_set.size(), 3);
}

TEST(MultisetTest, TestEmpty) {
  s21::multiset<int> empty_set;
  EXPECT_TRUE(empty_set.empty());
}

TEST(MultisetTest, TestSize) {
  s21::multiset<std::string> string_set = {"one", "two", "three"};
  std::multiset<std::string> string_set_std = {"one", "two", "three"};
  EXPECT_EQ(string_set.size(), string_set_std.size());
}

TEST(MultisetTest, TestMaxSize) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  std::multiset<int> int_set_std = {4, 8, 15, 16, 23, 42};
  EXPECT_EQ(int_set.max_size(), int_set_std.max_size());
}

TEST(MultisetTest, TestClear) {
  s21::multiset<std::string> string_set = {"one", "two", "three"};
  std::multiset<std::string> string_set_std = {"one", "two", "three"};
  string_set.clear();
  string_set_std.clear();
  EXPECT_EQ(string_set.empty(), string_set_std.empty());
  EXPECT_EQ(string_set.size(), string_set_std.size());
}

TEST(MultisetTest, TestInsert) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  std::multiset<int> int_set_std = {4, 8, 15, 16, 23, 42};
  int_set.insert(16);
  int_set_std.insert(16);
  auto i = int_set.begin();
  std::multiset<int>::iterator j = int_set_std.begin();
  while (i != int_set.end() && j != int_set_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
}

TEST(MultisetTest, TestErase) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  std::multiset<int> int_set_std = {4, 8, 15, 16, 23, 42};
  int_set.erase(int_set.begin());
  int_set_std.erase(int_set_std.begin());
  auto i = int_set.begin();
  std::multiset<int>::iterator j = int_set_std.begin();
  while (i != int_set.end() && j != int_set_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  EXPECT_EQ(int_set.size(), int_set_std.size());
}

TEST(MultisetTest, TestSwap) {
  s21::multiset<int> int_set = {4, 8, 15, 16, 23, 42};
  std::multiset<int> int_set_std = {4, 8, 15, 16, 23, 42};
  s21::multiset<int> empty_set;
  std::multiset<int> empty_set_std;
  int_set.swap(empty_set);
  int_set_std.swap(empty_set_std);
  auto i = empty_set.begin();
  std::multiset<int>::iterator j = empty_set_std.begin();
  while (i != empty_set.end() && j != empty_set_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  EXPECT_EQ(int_set.size(), int_set_std.size());
  EXPECT_EQ(empty_set.size(), empty_set_std.size());
  EXPECT_TRUE(int_set.empty());
}

TEST(MultisetTest, TestMerge) {
  s21::multiset<int> first = {4, 8, 15, 16, 23, 42};
  std::multiset<int> first_std = {4, 8, 15, 16, 23, 42};
  s21::multiset<int> second = {1, 2, 3, 4, 8};
  std::multiset<int> second_std = {1, 2, 3, 4, 8};
  first.merge(second);
  first_std.merge(second_std);
  auto i = first.begin();
  std::multiset<int>::iterator j = first_std.begin();
  while (i != first.end() && j != first_std.end()) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  EXPECT_EQ(first.size(), first_std.size());
}

TEST(MultisetTest, TestCount) {
  s21::multiset<int> int_set = {1, 2, 2, 3, 4, 5, 5, 5, 5};
  std::multiset<int> int_set_std = {1, 2, 2, 3, 4, 5, 5, 5, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_EQ(int_set.count(i), int_set_std.count(i));
  }
}

TEST(MultisetTest, TestFind) {
  s21::multiset<int> int_set = {1, 2, 3, 4, 5};
  std::multiset<int> int_set_std = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_EQ(*(int_set.find(i)), *(int_set_std.find(i)));
  }
}

TEST(MultisetTest, TestContains) {
  s21::multiset<int> int_set = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_TRUE(int_set.contains(i));
  }
}

TEST(MultisetTest, TestEqualRange) {
  s21::multiset<int> int_set = {1, 2, 3, 4, 5};
  std::multiset<int> int_set_std = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_EQ(*(int_set.equal_range(i).first),
              *(int_set_std.equal_range(i).first));
    EXPECT_EQ(*(int_set.equal_range(i).second),
              *(int_set_std.equal_range(i).second));
  }
}

TEST(MultisetTest, TestLowerBound) {
  s21::multiset<int> int_set = {1, 2, 3, 4, 5};
  std::multiset<int> int_set_std = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_EQ(*(int_set.lower_bound(i)), *(int_set_std.lower_bound(i)));
  }
}

TEST(MultisetTest, TestUpperBound) {
  s21::multiset<int> int_set = {1, 2, 3, 4, 5};
  std::multiset<int> int_set_std = {1, 2, 3, 4, 5};
  for (int i = 1; i <= 5; i++) {
    EXPECT_EQ(*(int_set.upper_bound(i)), *(int_set_std.upper_bound(i)));
  }
}

// Map

TEST(MapTest, TestDefaultConstructor) {
  s21::map<int, char> empty_map;
  EXPECT_TRUE(empty_map.empty());
}

TEST(MapTest, TestInitializerList) {
  s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> std_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  EXPECT_EQ(my_map.size(), std_map.size());
}

// TEST(MapTest, TestCopyConstructor) {
//   s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   s21::map<int, char> copy_map(my_map);
//   auto i = my_map.begin();
//   auto j = copy_map.begin();
//   EXPECT_EQ(my_map.size(), copy_map.size());
//   while (i != my_map.end() && j != copy_map.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
// }

TEST(MapTest, TestMoveConstructor) {
  s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> copy_map(std::move(my_map));
  EXPECT_TRUE(my_map.empty());
  EXPECT_EQ(copy_map.size(), 3);
}

// TEST(MapTest, TestCopyOperator) {
//   s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   s21::map<int, char> copy_map = my_map;
//   auto i = my_map.begin();
//   auto j = copy_map.begin();
//   while (i != my_map.end() && j != copy_map.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
// }

TEST(MapTest, TestMoveOperator) {
  s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> copy_map = std::move(my_map);
  EXPECT_TRUE(my_map.empty());
  EXPECT_EQ(copy_map.size(), 3);
}

// TEST(MapTest, TestAt) {
//   s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> std_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   for (int i = 1; i <= 3; i++) {
//     EXPECT_EQ(my_map.at(i), std_map.at(i));
//   }
// }

// TEST(MapTest, TestReferenceOperator) {
//   s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> std_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   for (int i = 1; i <= 3; i++) {
//     EXPECT_EQ(my_map[i], std_map[i]);
//   }
// }

TEST(MapTest, TestEmpty) {
  s21::map<int, char> my_empty_map;
  std::map<int, char> std_empty_map;
  EXPECT_EQ(my_empty_map.empty(), std_empty_map.empty());
}

TEST(MapTest, TestSize) {
  s21::map<int, std::string> string_map = {
      {1, "one"}, {2, "two"}, {3, "three"}};
  std::map<int, std::string> string_map_std = {
      {1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(string_map.size(), string_map_std.size());
}

TEST(MapTest, TestMaxSize) {
  s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> std_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  EXPECT_EQ(my_map.max_size(), std_map.max_size());
}

TEST(MapTest, TestClear) {
  s21::map<int, std::string> string_map = {
      {1, "one"}, {2, "two"}, {3, "three"}};
  std::map<int, std::string> string_map_std = {
      {1, "one"}, {2, "two"}, {3, "three"}};
  string_map.clear();
  string_map_std.clear();
  EXPECT_EQ(string_map.empty(), string_map_std.empty());
  EXPECT_EQ(string_map.size(), string_map_std.size());
}

// TEST(MapTest, TestInsertPair) {
//   s21::map<int, std::string> string_map = {
//       {1, "one"}, {2, "two"}, {3, "three"}};
//   std::map<int, std::string> string_map_std = {
//       {1, "one"}, {2, "two"}, {3, "three"}};
//   bool my_result = string_map.insert(std::pair{4, "four"}).second;
//   bool std_result = string_map_std.insert(std::pair{4, "four"}).second;
//   EXPECT_EQ(my_result, std_result);
//   auto i = string_map.begin();
//   auto j = string_map_std.begin();
//   while (i != string_map.end() && j != string_map_std.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
// }

// TEST(MapTest, TestInsertKeyValue) {
//   s21::map<int, std::string> string_map = {
//       {1, "one"}, {2, "two"}, {3, "three"}};
//   std::map<int, std::string> string_map_std = {
//       {1, "one"}, {2, "two"}, {3, "three"}};
//   bool my_result = string_map.insert(4, "four").second;
//   bool std_result = string_map_std.insert(std::pair{4, "four"}).second;
//   EXPECT_EQ(my_result, std_result);
//   auto i = string_map.begin();
//   auto j = string_map_std.begin();
//   while (i != string_map.end() && j != string_map_std.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
// }

// TEST(MapTest, TestInsertOrAssign) {
//   s21::map<int, std::string> string_map = {
//       {1, "one"}, {2, "two"}, {3, "three"}};
//   std::map<int, std::string> string_map_std = {
//       {1, "one"}, {2, "two"}, {3, "three"}};
//   bool my_result = string_map.insert_or_assign(3, "assign").second;
//   bool std_result = string_map_std.insert_or_assign(3, "assign").second;
//   EXPECT_EQ(my_result, std_result);
//   my_result = string_map.insert_or_assign(4, "four").second;
//   std_result = string_map_std.insert_or_assign(4, "four").second;
//   EXPECT_EQ(my_result, std_result);
//   auto i = string_map.begin();
//   auto j = string_map_std.begin();
//   while (i != string_map.end() && j != string_map_std.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
// }

// TEST(MapTest, TestErase) {
//   s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> std_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   my_map.erase(my_map.begin());
//   std_map.erase(std_map.begin());
//   s21::map<int, char>::iterator i = my_map.begin();
//   std::map<int, char>::iterator j = std_map.begin();
//   while (i != my_map.end() && j != std_map.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
//   EXPECT_EQ(my_map.size(), std_map.size());
// }

// TEST(MapTest, TestSwap) {
//   s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> std_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   s21::map<int, char> empty_map;
//   std::map<int, char> empty_map_std;
//   my_map.swap(empty_map);
//   std_map.swap(empty_map_std);
//   s21::map<int, char>::iterator i = empty_map.begin();
//   std::map<int, char>::iterator j = empty_map_std.begin();
//   while (i != empty_map.end() && j != empty_map_std.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
//   EXPECT_EQ(my_map.size(), std_map.size());
//   EXPECT_EQ(empty_map.size(), empty_map_std.size());
//   EXPECT_EQ(my_map.empty(), std_map.empty());
// }

// TEST(MapTest, TestMerge) {
//   s21::map<int, char> first = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> first_std = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   s21::map<int, char> second = {{2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'f'}};
//   std::map<int, char> second_std = {{2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'f'}};
//   first.merge(second);
//   first_std.merge(second_std);
//   s21::map<int, char>::iterator i = first.begin();
//   std::map<int, char>::iterator j = first_std.begin();
//   while (i != first.end() && j != first_std.end()) {
//     EXPECT_EQ(*i, *j);
//     i++;
//     j++;
//   }
//   EXPECT_EQ(first.size(), first_std.size());
// }

TEST(MapTest, TestContains) {
  s21::map<int, char> my_map = {
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'f'}};
  for (int i = 1; i <= 5; i++) {
    EXPECT_TRUE(my_map.contains(i));
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
