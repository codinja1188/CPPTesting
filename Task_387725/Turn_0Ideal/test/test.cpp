#include "../src/app.h"
#include <gtest/gtest.h>
#include <vector>

// Helper function to create a dungeon from a string vector
std::vector<std::string> createDungeon(const std::vector<std::string>& input) {
    return input;
}

TEST(MinStepsToBigKeyTest, BasicTests) {
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
    ASSERT_EQ(g(dungeon1), 16);

    // No doors or keys
    std::vector<std::string> dungeon2 = createDungeon({
        "####",
        "#.T#",
        "#..#",
        "####"
    });
    ASSERT_EQ(g(dungeon2), -1);

    // No path to big key
    std::vector<std::string> dungeon3 = createDungeon({
        "####",
        "#.T#",
        "#.#.",
        "###%"
    });
    ASSERT_EQ(g(dungeon3), -1);
}

TEST(MinStepsToBigKeyTest, KeyAndDoorTests) {
    // Multiple keys, single door
    std::vector<std::string> dungeon4 = createDungeon({
        "#####",
        "#.T.#",
        "#+.+#",
        "#ttt#",
        "####%"
    });
    ASSERT_EQ(g(dungeon4), -1);

    // Single key, multiple doors
    std::vector<std::string> dungeon5 = createDungeon({
        "#######",
        "#.T...#",
        "#+...+#",
        "#.....#",
        "#t+...#",
        "#.....#",
        "#######%"
    });
    ASSERT_EQ(g(dungeon5), -1); // Not enough keys

    // Enough keys, multiple doors
    std::vector<std::string> dungeon6 = createDungeon({
        "#######",
        "#.T...#",
        "#+...+#",
        "#.....#",
        "#t+t..#",
        "#.....#",
        "#######%"
    });
    ASSERT_EQ(g(dungeon6), -1);

}


TEST(MinStepsToBigKeyTest, EdgeCases) {
    // Big key at entrance
    std::vector<std::string> dungeon7 = createDungeon({
        "###",
        "#T#",
        "###%"
    });
    ASSERT_EQ(g(dungeon7), -1);

    // Entrance blocked
    std::vector<std::string> dungeon8 = createDungeon({
        "###",
        "#T#",
        "###"
    });
    ASSERT_EQ(g(dungeon8), -1);


    // Complex maze with redundant keys and doors
    std::vector<std::string> dungeon9 = createDungeon({
            "##########",
            "#...T....#",
            "#........#",
            "###+##+###",
            "#tt.....t#",
            "#........#",
            "###+##+###",
            "#t......t#",
            "#........#",
            "########%#"
    });
    ASSERT_EQ(g(dungeon9), 16);
}

TEST(MinStepsToBigKeyTest, EdgeCasesAdditional) {

    // Empty dungeon
    std::vector<std::string> emptyDungeon = {};
    ASSERT_EQ(g(emptyDungeon), -1);

    // No big key or entrance
    std::vector<std::string> invalidDungeon = {
        "#####",
        "#...#",
        "#...#",
        "#####"
    };
    ASSERT_EQ(g(invalidDungeon), -1);

    // Single-tile dungeon (only entrance)
    std::vector<std::string> singleTileDungeon = {"%"};
    ASSERT_EQ(g(singleTileDungeon), -1);

    // Large dungeon test
    std::vector<std::string> largeDungeon(1000, std::string(1000, '.'));
    largeDungeon[500][500] = '%';
    largeDungeon[750][750] = 'T';
    ASSERT_EQ(g(largeDungeon), 500);  // Example expectation
}

TEST(MinStepsToBigKeyTest, CircularPathTest) {
    std::vector<std::string> circularDungeon = {
        "######",
        "#....#",
        "#.##.#",
        "#.#T.#",
        "#...%#",
        "######"
    };
    ASSERT_EQ(g(circularDungeon), 2);
}

TEST(MinStepsToBigKeyTest, SparseKeys) {
    std::vector<std::string> sparseKeysDungeon = {
        "##########",
        "#...+....#",
        "#...t....#",
        "#.+T+...+#",
        "#...t...+#",
        "#...+....#",
        "########%#"
    };
    ASSERT_EQ(g(sparseKeysDungeon), 8);
}
