#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "app.h"


std::vector<std::string> createDungeon(const std::vector<std::string>& input) {
    return input;
}

int main() {
     // Example case
    std::vector<std::string> dungeon1 = createDungeon({
        "##########",
        "#...T....#",
        "#........#",
        "###+##+###",
        "#t......t#",
        "#........#",
        "###+##+###",
        "#t......t#",
        "#........#",
        "########%#"
    });
    assert(g(dungeon1) == 16);


    std::cout << "All test cases passed!" << std::endl;

    return 0;
}