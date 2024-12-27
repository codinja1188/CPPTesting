#include "../src/app.h"
#include <gtest/gtest.h>


TEST(LiteraryCorrection, EmptyText) {
    std::string text = "";
    std::string expected = "";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, SingleSentence_AllSame) {
    std::string text = "apples apricots avocados amazing";
    std::string expected = "apples apricots avocados amazing";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, SingleSentence_OneDifferent) {
    std::string text = "bananas berries blueberries cherries coconut";
    std::string expected = "bananas berries blueberries cherries";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, SingleSentence_MultipleDifferent) {
    std::string text = "cats canines crocodiles cucumbers";
    std::string expected = "cats crocodiles"; 
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, MultipleSentences) {
    std::string text = "dragons den dennis dave. elephants eels eggs eat.";
    std::string expected = "dragons den dennis dave. elephants eels eggs eat.";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, MultipleSentences_Mixed) {
    std::string text = "fish fin find frog. grapes green grass gorilla goat.";
    std::string expected = "fish fin find. grapes green grass.";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, EdgeCase_OnlySpaces) {
    std::string text = "   ";
    std::string expected = "";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, EdgeCase_SingleWordSentences) {
    std::string text = "hello. world. test.";
    std::string expected = "hello. world. test.";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, EdgeCase_EmptySentences) {
    std::string text = "hello. . world.";
    std::string expected = "hello. . world.";
    EXPECT_EQ(g(text), expected);
}

TEST(LiteraryCorrection, ComplexScenario) {
    std::string text = "one orange owl octopus. two tree train tractor. three thirty. four.";
    std::string expected = "one orange owl. two tree train tractor. three thirty. four.";
    EXPECT_EQ(g(text), expected);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}