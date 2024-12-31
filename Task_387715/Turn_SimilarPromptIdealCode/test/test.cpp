#include "../src/app.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <string>

// Include the function to be tested
int g(std::vector<std::string> a);

void test_empty_input() {
  std::vector<std::string> a;
  int result = g(a);
  int expected = 0;
  std::cout << "test_empty_input: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_empty_rows() {
  std::vector<std::string> a = {""};
  int result = g(a);
  int expected = 0;
  std::cout << "test_empty_rows: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_single_element() {
  std::vector<std::string> a = {"5"};
  int result = g(a);
  int expected = 5;
  std::cout << "test_single_element: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_single_row() {
  std::vector<std::string> a = {"12345"};
  int result = g(a);
  int expected = 15;
  std::cout << "test_single_row: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_single_column() {
  std::vector<std::string> a = {"1", "2", "3", "4", "5"};
  int result = g(a);
  int expected = 15;
  std::cout << "test_single_column: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_example_input() {
  std::vector<std::string> a = {
    "12345",
    "67891",
    "23456",
    "78912"
  };
  int result = g(a);
  int expected = 44;
  std::cout << "test_example_input: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_different_capacities() {
  std::vector<std::string> a = {
    "912",
    "384",
    "567"
  };
  int result = g(a);
  int expected = 33;
  std::cout << "test_different_capacities: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_all_ones() {
  std::vector<std::string> a = {
    "111",
    "111",
    "111"
  };
  int result = g(a);
  int expected = 5;
  std::cout << "test_all_ones: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_increasing_capacity() {
  std::vector<std::string> a = {
    "123",
    "456",
    "789"
  };
  int result = g(a);
  int expected = 29;
  std::cout << "test_increasing_capacity: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_decreasing_capacity() {
  std::vector<std::string> a = {
    "987",
    "654",
    "321"
  };
  int result = g(a);
  int expected = 29;
  std::cout << "test_decreasing_capacity: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

void test_larger_grid() {
  std::vector<std::string> a = {
    "1234567",
    "8912345",
    "6789123",
    "4567891",
    "2345678"
  };
  int result = g(a);
  int expected = 81;
  std::cout << "test_larger_grid: expected " << expected << ", got " << result << std::endl;
  assert(result == expected);
}

int main() {
  test_empty_input();
  test_empty_rows();
  test_single_element();
  test_single_row();
  test_single_column();
  test_example_input();
  test_different_capacities();
  test_all_ones();
  test_increasing_capacity();
  test_decreasing_capacity();
  test_larger_grid();
  std::cout << "All test cases passed!" << std::endl;
  return 0;
}