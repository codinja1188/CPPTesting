#include "app.h"
#include <cassert>
#include <iostream>

void test() {
    std::string text = "";
    std::string expected = "";
    std::cout << "g(text): " << g(text) << " | expected: " << expected << std::endl;
    assert(g(text) == expected);

    text = "a a a a a a a a a a";
    expected = "a a a a a a a a a a";
    std::cout << "g(text): " << g(text) << " | expected: " << expected << std::endl;
    assert(g(text) == expected);

    text = "a b c d e f g h i j";
    expected = "a b c d e f g h i j";
    std::cout << "g(text): " << g(text) << " | expected: " << expected << std::endl;
    assert(g(text) == expected);

    text = "apple apricot avocado";
    expected = "apple apricot avocado";
    std::cout << "g(text): " << g(text) << " | expected: " << expected << std::endl;
    assert(g(text) == expected);

    text = "apple banana apricot avocado";
    expected = "apple apricot avocado";
    std::cout << "g(text): " << g(text) << " | expected: " << expected << std::endl;
    assert(g(text) == expected);

    text = "xylophone yawn zebra";
    expected = "xylophone yawn zebra";
    std::cout << "g(text): " << g(text) << " | expected: " << expected << std::endl;
    assert(g(text) == expected);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test();
    return 0;
}
