#include "../src/app.h"

#include "/opt/homebrew/Cellar/googletest/1.15.2/include/gtest/gtest.h"
#include <vector>
#include <stdexcept>

TEST(FloodFillTest, BasicFill) {
    std::vector<int> image = {0x00000000, static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF), 0x00000000};
    ASSERT_EQ(g(image, 16, 1), 64);
}

TEST(FloodFillTest, FillFromBlack) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF), 0x00000000, 0x00000000, static_cast<int>(0xFFFFFFFF)};
     ASSERT_EQ(g(image, 16, 1), 0);
}

TEST(FloodFillTest, EdgeCaseTop) {
   std::vector<int> image = {static_cast<int>(0xFFFFFFFF), 0x00000000, static_cast<int>(0xFFFFFFFF)};
    ASSERT_EQ(g(image, 16, 0), 32);
}

TEST(FloodFillTest, EdgeCaseBottom) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF), 0x00000000, static_cast<int>(0xFFFFFFFF)};
   ASSERT_EQ(g(image, 16, 2), 32);
}

TEST(FloodFillTest, EdgeCaseLeft) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF)};
     ASSERT_EQ(g(image, 0, 1), 96);
}
TEST(FloodFillTest, EdgeCaseRight) {
   std::vector<int> image = {static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF), static_cast<int>(0xFFFFFFFF)};
    ASSERT_EQ(g(image, 31, 1), 96);
}
TEST(FloodFillTest, CornerTopLeft) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF), 0x00000000, 0x00000000};
     ASSERT_EQ(g(image, 0, 0), 32);
}

TEST(FloodFillTest, CornerTopRight) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF), 0x00000000, 0x00000000};
    ASSERT_EQ(g(image, 31, 0), 32);
}

TEST(FloodFillTest, CornerBottomLeft) {
    std::vector<int> image = {0x00000000, 0x00000000, static_cast<int>(0xFFFFFFFF)};
    ASSERT_EQ(g(image, 0, 2), 32);
}

TEST(FloodFillTest, CornerBottomRight) {
     std::vector<int> image = {0x00000000, 0x00000000, static_cast<int>(0xFFFFFFFF)};
    ASSERT_EQ(g(image, 31, 2), 32);
}


TEST(FloodFillTest, SinglePixelImageWhite) {
    std::vector<int> image = {static_cast<int>(0x80000000)};
    ASSERT_EQ(g(image, 0, 0), 1);
}

TEST(FloodFillTest, SinglePixelImageBlack) {
    std::vector<int> image = {0x7FFFFFFF};
    ASSERT_EQ(g(image, 0, 0), 0);
}
TEST(FloodFillTest, FullWhiteImage) {
   std::vector<int> image(5, 0xFFFFFFFF);
   ASSERT_EQ(g(image, 0, 0), 160);
}
TEST(FloodFillTest, FullBlackImage) {
    std::vector<int> image(5, 0x00000000);
     ASSERT_EQ(g(image, 0, 0), 0);
}

TEST(FloodFillTest, InvalidXCoordinateLow) {
  std::vector<int> image = {0x00000000};
  ASSERT_THROW(g(image, -1, 0), std::invalid_argument);
}

TEST(FloodFillTest, InvalidXCoordinateHigh) {
  std::vector<int> image = {0x00000000};
   ASSERT_THROW(g(image, 32, 0), std::invalid_argument);
}

TEST(FloodFillTest, InvalidYCoordinateLow) {
   std::vector<int> image = {0x00000000};
  ASSERT_THROW(g(image, 0, -1), std::invalid_argument);
}

TEST(FloodFillTest, InvalidYCoordinateHigh) {
    std::vector<int> image = {0x00000000};
    ASSERT_THROW(g(image, 0, 1), std::invalid_argument);
}
TEST(FloodFillTest, DisconnectedRegions) {
    std::vector<int> image = {static_cast<int>(0xFF0000FF), static_cast<int>(0xFF0000FF), static_cast<int>(0xFF0000FF)};
    ASSERT_EQ(g(image, 0, 1), 32);
    ASSERT_EQ(g(image, 31, 1), 32);
}

TEST(FloodFillTest, MaximumSize) {
    std::vector<int> image(100, 0xFFFFFFFF);
    ASSERT_EQ(g(image, 15, 50), 3200);
}


TEST(FloodFillTest, EmptyImage) {
    std::vector<int> image = {};
     ASSERT_EQ(g(image, 0, 0), 0);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}