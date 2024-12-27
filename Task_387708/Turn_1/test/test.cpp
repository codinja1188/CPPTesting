#include "../src/app.h"

#include <cassert>


void testG() {
    std::cout << "Running test cases" << std::endl;
    std::string result;

    result = g("bananas berries blueberries cherries coconut");
    std::cout << "Result: " << result << " | Expected: bananas berries blueberries cherries" << std::endl;
    assert(result == "bananas berries blueberries cherries");

    result = g("dragons den dennis dave. elephants eels eggs eat.");
    std::cout << "Result: " << result << " | Expected: dragons den dennis dave. elephants eels eggs eat" << std::endl;
    assert(result == "dragons den dennis dave. elephants eels eggs eat");

    result = g("apple banana apricot avocado blueberry");
    std::cout << "Result: " << result << " | Expected: apple apricot avocado" << std::endl;
    assert(result == "apple apricot avocado");

    result = g("only one word");
    std::cout << "Result: " << result << " | Expected: only one word" << std::endl;
    assert(result == "only one word");

    result = g("");
    std::cout << "Result: " << result << " | Expected: " << std::endl;
    assert(result == "");

    result = g("   ");
    std::cout << "Result: " << result << " | Expected: " << std::endl;
    assert(result == "");

    result = g("a a a a. b b c c");
    std::cout << "Result: " << result << " | Expected: a a a a. b b" << std::endl;
    assert(result == "a a a a. b b");

    result = g("word.  another word");
    std::cout << "Result: " << result << " | Expected: word. another word" << std::endl;
    assert(result == "word. another word");

    result = g("x x x y y z z z z");
    std::cout << "Result: " << result << " | Expected: x x x. z z z z" << std::endl;
    assert(result == "x x x. z z z z");

    result = g("aaaa. bbbb. cccc");
    std::cout << "Result: " << result << " | Expected: aaaa. bbbb. cccc" << std::endl;
    assert(result == "aaaa. bbbb. cccc");

    result = g("apple banana apricot.   blueberry blackberry");
    std::cout << "Result: " << result << " | Expected: apple apricot. blueberry blackberry" << std::endl;
    assert(result == "apple apricot. blueberry blackberry");

    result = g("cat car cow. dog dig");
    std::cout << "Result: " << result << " | Expected: cat car cow. dog dig" << std::endl;
    assert(result == "cat car cow. dog dig");

    result = g("  hello   world   how   are you ");
    std::cout << "Result: " << result << " | Expected: hello how" << std::endl;
    assert(result == "hello how");

    result = g("test test test zebra");
    std::cout << "Result: " << result << " | Expected: test test test" << std::endl;
    assert(result == "test test test");

    result = g("  apple  banana  apricot ");
    std::cout << "Result: " << result << " | Expected: apple apricot" << std::endl;
    assert(result == "apple apricot");

    result = g("a b c. d e f");
    std::cout << "Result: " << result << " | Expected: a. d" << std::endl;
    assert(result == "a. d");

    result = g("a b c a");
    std::cout << "Result: " << result << " | Expected: a b c a" << std::endl;
    assert(result == "a b c a");

    result = g("  apple   ant   ape ");
    std::cout << "Result: " << result << " | Expected: apple ant ape" << std::endl;
    assert(result == "apple ant ape");

    result = g("  apple  bat   ant   ape    ");
    std::cout << "Result: " << result << " | Expected: apple ant ape" << std::endl;
    assert(result == "apple ant ape");

    result = g("apple bat. ant ape");
    std::cout << "Result: " << result << " | Expected: apple. ant ape" << std::endl;
    assert(result == "apple. ant ape");

    std::cout << "All test cases passed!" << std::endl;
}


int main(int argc, char **argv) {
    testG();
    return 0;
}