#include "../src/app.h"

#include <gtest/gtest.h>
#include <vector>

// Test for empty image (no rows)
TEST(FloodFillTest, EmptyImage_NoFill) {
    std::vector<int> image = {};
    EXPECT_EQ(g(image, 0, 0), 0);
}

// Single pixel black image - entire row fills
TEST(FloodFillTest, SinglePixelImage_AllBlack_Fill) {
    std::vector<int> image = {0};  // Single row, all black
    EXPECT_EQ(g(image, 0, 0), 32); // Entire row fills
}

// Single pixel white image - no fill required
TEST(FloodFillTest, SinglePixelImage_AllWhite_NoFill) {
    std::vector<int> image = {INT_MAX};  // Single row, all white
    EXPECT_EQ(g(image, 0, 0), 32);       // Stays white (no new pixels turn white)
}

// Single row starts at a black pixel - entire row should fill
TEST(FloodFillTest, SingleRowImage_StartAtBlack_Fill) {
    std::vector<int> image = {0};  // Single row, all black
    EXPECT_EQ(g(image, 0, 0), 32); // Fill entire row
}

// Single row starts at a white pixel - no fill required
TEST(FloodFillTest, SingleRowImage_StartAtWhite_NoFill) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF)};  // Fully white row
    EXPECT_EQ(g(image, 0, 0), 32);                            // No change
}

// Multi-row with isolated island of white pixels
TEST(FloodFillTest, MultiRowImage_IsolatedIsland_Fill) {
    std::vector<int> image = {
        0b00000000000000000000000000000000,  // Row 0
        0b00000000000000000000000000001000,  // Row 1 (island at x = 28)
        0b00000000000000000000000000001000,  // Row 2 (island at x = 28)
        0b00000000000000000000000000000000,  // Row 3
    };
    EXPECT_EQ(g(image, 28, 1), 2);  // Fill two connected pixels
}

// Multi-row with fill starting from edge pixel
TEST(FloodFillTest, MultiRowImage_FillFromEdge) {
    std::vector<int> image = {
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000001,
        0b00000000000000000000000000000001,
        0b00000000000000000000000000000000,
    };
    EXPECT_EQ(g(image, 31, 1), 2);  // Fill two pixels at edge (x = 31)
}

// Large image with full flood fill
TEST(FloodFillTest, LargeImage_CompleteFill) {
    std::vector<int> image(1000, 0);  // 1000 rows, all black
    EXPECT_EQ(g(image, 15, 500), 32000);  // Entire image should fill
}

// Start flood fill at an out-of-bounds X coordinate
TEST(FloodFillTest, OutOfBounds_X_NoFill) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF)};
    EXPECT_EQ(g(image, 32, 0), 0);  // x = 32 is out of range
}

// Start flood fill at an out-of-bounds Y coordinate
TEST(FloodFillTest, OutOfBounds_Y_NoFill) {
    std::vector<int> image = {static_cast<int>(0xFFFFFFFF)};
    EXPECT_EQ(g(image, 0, 1), 0);  // y = 1 is out of bounds (only one row exists)
}

// Negative X coordinate - No fill should happen
TEST(FloodFillTest, Negative_X_NoFill) {
    std::vector<int> image = {0};
    EXPECT_EQ(g(image, -1, 0), 0);  // Negative x coordinate
}

// Negative Y coordinate - No fill should happen
TEST(FloodFillTest, Negative_Y_NoFill) {
    std::vector<int> image = {0};
    EXPECT_EQ(g(image, 0, -1), 0);  // Negative y coordinate
}

// Test with a partially filled row
TEST(FloodFillTest, PartiallyFilledRow_FillRemaining) {
    std::vector<int> image = {static_cast<int>(0xFFFF0000)};  // First 16 pixels white, last 16 black
    EXPECT_EQ(g(image, 20, 0), 32);         // Fill remaining 16 black pixels
}

// Sparse large image with isolated white pixel
TEST(FloodFillTest, SparseLargeImage_IsolatedWhitePixel) {
    std::vector<int> image(1000, 0);  
    image[500] = 0x00010000;  // One white pixel at x = 15
    EXPECT_EQ(g(image, 15, 500), 1);  // Fill single pixel
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
