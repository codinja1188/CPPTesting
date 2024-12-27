#include "../src/app.h"

#include <cassert>
#include <iostream>

void testG() {
    std::cout << "Running test cases" << std::endl;
    std::string result;

    result = g(std::string("bananas berries blueberries cherries coconut"));
    std::cout << "Result: " << result << " | Expected: bananas berries blueberries" << std::endl;
    assert(result == "bananas berries blueberries");

    result = g(std::string("dragons den dennis dave. elephants eels eggs eat."));
    std::cout << "Result: " << result << " | Expected: dragons den dennis dave. elephants eels eggs eat" << std::endl;
    assert(result == "dragons den dennis dave. elephants eels eggs eat");

    result = g(std::string("apple banana apricot avocado blueberry"));
    std::cout << "Result: " << result << " | Expected: apple apricot avocado" << std::endl;
    assert(result == "apple apricot avocado");

    result = g(std::string("only one word"));
    std::cout << "Result: " << result << " | Expected: only one word" << std::endl;
    assert(result == "only one");

    result = g(std::string(""));
    std::cout << "Result: " << result << " | Expected: " << std::endl;
    assert(result == "");

    result = g(std::string("   "));
    std::cout << "Result: " << result << " | Expected: " << std::endl;
    assert(result == "");

    result = g(std::string("a a a a. b b c c"));
    std::cout << "Result: " << result << " | Expected: a a a a. b b c c" << std::endl;
    assert(result == "a a a a. b b c c");

    result = g(std::string("word.  another word"));
    std::cout << "Result: " << result << " | Expected: word. another word" << std::endl;
    assert(result == "word. another word");

    result = g(std::string("aaaa. bbbb. cccc"));
    std::cout << "Result: " << result << " | Expected: aaaa. bbbb. cccc" << std::endl;
    assert(result == "aaaa. bbbb. cccc");

    result = g(std::string("apple banana apricot.   blueberry blackberry"));
    std::cout << "Result: " << result << " | Expected: apple apricot. blueberry blackberry" << std::endl;
    assert(result == "apple apricot. blueberry blackberry");

    result = g(std::string("cat car cow. dog dig"));
    std::cout << "Result: " << result << " | Expected: cat car cow. dog dig" << std::endl;
    assert(result == "cat car cow. dog dig");

    result = g(std::string("  hello   world   how   are you "));
    std::cout << "Result: " << result << " | Expected: hello how" << std::endl;
    assert(result == "hello how");

    result = g(std::string("test test test zebra"));
    std::cout << "Result: " << result << " | Expected: test test test" << std::endl;
    assert(result == "test test test");

    result = g(std::string("  apple  banana  apricot "));
    std::cout << "Result: " << result << " | Expected: apple apricot" << std::endl;
    assert(result == "apple apricot");

    result = g(std::string("  apple   ant   ape "));
    std::cout << "Result: " << result << " | Expected: apple ant ape" << std::endl;
    assert(result == "apple ant ape");

    result = g(std::string("  apple  bat   ant   ape    "));
    std::cout << "Result: " << result << " | Expected: apple ant ape" << std::endl;
    assert(result == "apple ant ape");

    result = g(std::string("apple bat. ant ape"));
    std::cout << "Result: " << result << " | Expected: apple. ant ape" << std::endl;
    assert(result == "apple bat. ant ape");

    std::cout << "All test cases passed!" << std::endl;
}


int main(int argc, char **argv) {
    testG();
    return 0;
}