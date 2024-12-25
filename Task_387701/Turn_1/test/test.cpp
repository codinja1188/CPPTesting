#include <iostream>
#include <cassert>
#include <string>

int g(std::string a);

void test_g() {
    assert(g("0") == 0);
    assert(g("1") == 5);
    assert(g("2") == 7);
    assert(g("3") == 8);
    assert(g("4") == 9);
    assert(g("5") == 10);
    assert(g("6") == 11);
    assert(g("7") == 12);
    assert(g("8") == 12);
    assert(g("9") == 13);
     assert(g("10") == 14);
    assert(g("20") == 18);
    assert(g("25") == 19);
      assert(g("100") == 26);
     assert(g("1000") == 46);
     assert(g("10000") == 74);
      assert(g("24") == 18);
       assert(g("26") == 19);

     // Large number to test limits.
    assert(g("1125899906842623") == 482006); // Test near the limit
    assert(g("1125899906842624") == 482006); // test on the limit

    // Test cases with many zeros
    assert(g("1000000") == 306);

    // Test cases with larger intermediate values
    assert(g("500") == 72);
      assert(g("999") == 94);

    // Edge case with slightly larger numbers
    assert(g("100000") == 210);
    assert(g("10000000") == 642);
}

int main() {
    test_g();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}