#include "../src/app.h"

#include <gtest/gtest.h>
#include <vector>

TEST(FloodFillTest, EmptyImage) {
    std::vector<int> image = {};
    EXPECT_EQ(g(image, 0, 0), 0);
}

TEST(FloodFillTest, SinglePixelImage_AllBlack) {
    std::vector<int> image = {0};
    EXPECT_EQ(g(image, 0, 0), 0);
}

TEST(FloodFillTest, SinglePixelImage_AllWhite) {
    std::vector<int> image = {INT_MAX}; 
    EXPECT_EQ(g(image, 0, 0), 32);
}

TEST(FloodFillTest, SingleRowImage_StartAtBlack) {
  std::vector<int> image = {static_cast<int>(0xFFFFFFFF)};
  EXPECT_EQ(g(image, 0, 0), 32);
}

TEST(FloodFillTest, SingleRowImage_StartAtWhite) {
  std::vector<int> image = {0};
  EXPECT_EQ(g(image, 5, 0), 0);
}

TEST(FloodFillTest, MultiRowImage_Island) {
    std::vector<int> image = {
        0b00000000000000000000000000000000,
        0b00000000000000000000000000001000,
        0b00000000000000000000000000001000,
        0b00000000000000000000000000000000,
    };
    EXPECT_EQ(g(image, 28, 1), 2);
}

TEST(FloodFillTest, MultiRowImage_FillFromEdge) {
    std::vector<int> image = {
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000001,
        0b00000000000000000000000000000001,
        0b00000000000000000000000000000000,
    };
    EXPECT_EQ(g(image, 31, 1), 2);
}

TEST(FloodFillTest, LargeImage) {
  std::vector<int> image(1000, 0);
  EXPECT_EQ(g(image, 15, 500), 0);
}

TEST(FloodFillTest, OutOfBounds_X) {
  std::vector<int> image = {static_cast<int>(0xFFFFFFFF)};
  EXPECT_EQ(g(image, 32, 0), 0);
}

TEST(FloodFillTest, OutOfBounds_Y) {
  std::vector<int> image = {static_cast<int>(0xFFFFFFFF)};
  EXPECT_EQ(g(image, 0, 1), 0);
}

int main() {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();

    return 0;
}