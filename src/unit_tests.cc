#include <gtest/gtest.h>

#include "s21_vector.h"
#include "stack/stack.h"
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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
