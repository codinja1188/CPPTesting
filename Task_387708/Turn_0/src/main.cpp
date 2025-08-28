#include "app.h"
#include <cassert>
#include <iostream>

void test() {
    // std::string text = "one orange owl octopus. two tree train tractor. three thirty. four.";
    // std::string expected = "one orange owl octopus. two tree train tractor. three thirty. four.";
    // assert(g(text) == expected);

    // text = "hello. . world.";
    // expected = "hello. . world.";
    // assert(g(text) == expected);    

    // text = "hello. world. test.";
    // expected = "hello. world. test.";
    // assert(g(text) == expected);

    std::string text = "";
    std::string expected = "";
    std::cout << "g(\"" << text << "\") = \"" << g(text) << "\" | expected: \"" << expected << "\"" << std::endl;
    assert(g(text) == expected);

    text = "a a a a a a a a a a";
    expected = "a a a a a a a a a a";
    std::cout << "g(\"" << text << "\") = \"" << g(text) << "\" | expected: \"" << expected << "\"" << std::endl;
    assert(g(text) == expected);

    text = "a b c d e f g h i j";
    expected = "a";
    std::cout << "g(\"" << text << "\") = \"" << g(text) << "\" | expected: \"" << expected << "\"" << std::endl;
    assert(g(text) == expected);

    text = "apple apricot avocado";
    expected = "apple apricot avocado";
    std::cout << "g(\"" << text << "\") = \"" << g(text) << "\" | expected: \"" << expected << "\"" << std::endl;
    assert(g(text) == expected);

    text = "apple banana apricot avocado";
    expected = "apple apricot avocado";
    std::cout << "g(\"" << text << "\") = \"" << g(text) << "\" | expected: \"" << expected << "\"" << std::endl;
    assert(g(text) == expected);
}

int main() {
    test();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}