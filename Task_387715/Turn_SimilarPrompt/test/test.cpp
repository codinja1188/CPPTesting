#include "../src/app.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <string>

// Include the function to be tested
int g(std::vector<std::string> a);

void test_empty_input() {
  std::vector<std::string> a;
  assert(g(a) == 0);
}

void test_empty_rows() {
  std::vector<std::string> a = {""};
   assert(g(a) == 0);
}


void test_single_element() {
  std::vector<std::string> a = {"5"};
  assert(g(a) == 5);
}

void test_single_row() {
    std::vector<std::string> a = {"12345"};
    assert(g(a) == 15);
}

void test_single_column() {
    std::vector<std::string> a = {"1", "2", "3", "4", "5"};
    assert(g(a) == 15);
}

void test_example_input() {
    std::vector<std::string> a = {
        "12345",
        "67891",
        "23456",
        "78912"
    };
    assert(g(a) == 36);
}

void test_different_capacities() {
    std::vector<std::string> a = {
        "912",
        "384",
        "567"
    };
    assert(g(a) == 38);
}

void test_all_ones() {
    std::vector<std::string> a = {
        "111",
        "111",
        "111"
    };
    assert(g(a) == 6);
}

void test_increasing_capacity() {
  std::vector<std::string> a = {
    "123",
    "456",
    "789"
  };
  assert(g(a) == 35);
}

void test_decreasing_capacity() {
    std::vector<std::string> a = {
        "987",
        "654",
        "321"
    };
    assert(g(a) == 35);
}

void test_larger_grid() {
    std::vector<std::string> a = {
        "1234567",
        "8912345",
        "6789123",
        "4567891",
        "2345678"
    };
    assert(g(a) == 110);

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