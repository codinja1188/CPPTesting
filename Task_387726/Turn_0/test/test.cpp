#include "../src/app.h"
#include <gtest/gtest.h>
#include <vector>

// Test case: Empty array
TEST(RelativelyPrimeTest, EmptyArray) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(g(input), expected);
}

// Test case: Single element
TEST(RelativelyPrimeTest, SingleElement) {
    std::vector<int> input = {5};
    std::vector<int> expected = {5};
    EXPECT_EQ(g(input), expected);
}

// Test case: Already relatively prime
TEST(RelativelyPrimeTest, AlreadyRelativelyPrime) {
    std::vector<int> input = {2, 3, 5};
    std::vector<int> expected = {2, 3, 5};
    EXPECT_EQ(g(input), expected);
}

// Test case: Simple pair not relatively prime
TEST(RelativelyPrimeTest, SimplePairNotRelativelyPrime) {
    std::vector<int> input = {2, 4};
    std::vector<int> expected = {4};
    EXPECT_EQ(g(input), expected);
}

// Test case: [2, 4, 3]
TEST(RelativelyPrimeTest, TwoFourThree) {
    std::vector<int> input = {2, 4, 3};
    std::vector<int> expected = {4, 3};
    EXPECT_EQ(g(input), expected);
}

// Test case: [6, 10, 15]
TEST(RelativelyPrimeTest, SixTenFifteen) {
    std::vector<int> input = {6, 10, 15};
    auto result = g(input);
    // Verify all neighbors are relatively prime
    for (size_t i = 0; i < result.size() - 1; i++) {
        EXPECT_EQ(std::gcd(result[i], result[i+1]), 1);
    }
}

// Test case: [12, 18, 24]
TEST(RelativelyPrimeTest, TwelveEighteenTwentyFour) {
    std::vector<int> input = {12, 18, 24};
    auto result = g(input);
    // Verify all neighbors are relatively prime
    for (size_t i = 0; i < result.size() - 1; i++) {
        EXPECT_EQ(std::gcd(result[i], result[i+1]), 1);
    }
}

// Test case: [4, 6, 10]
TEST(RelativelyPrimeTest, FourSixTen) {
    std::vector<int> input = {4, 6, 10};
    auto result = g(input);
    // Verify all neighbors are relatively prime
    for (size_t i = 0; i < result.size() - 1; i++) {
        EXPECT_EQ(std::gcd(result[i], result[i+1]), 1);
    }
}

// Test case: All same numbers
TEST(RelativelyPrimeTest, AllSameNumbers) {
    std::vector<int> input = {5, 5, 5};
    std::vector<int> expected = {5};
    EXPECT_EQ(g(input), expected);
}

// Test case: Powers of 2
TEST(RelativelyPrimeTest, PowersOfTwo) {
    std::vector<int> input = {2, 4, 8, 16};
    std::vector<int> expected = {16};
    EXPECT_EQ(g(input), expected);
}

// Test case: Consecutive integers (always relatively prime)
TEST(RelativelyPrimeTest, ConsecutiveIntegers) {
    std::vector<int> input = {5, 6, 7, 8};
    std::vector<int> expected = {5, 6, 7, 8};
    EXPECT_EQ(g(input), expected);
}

// Test case: [3, 6, 9]
TEST(RelativelyPrimeTest, ThreeSixNine) {
    std::vector<int> input = {3, 6, 9};
    std::vector<int> expected = {18};
    EXPECT_EQ(g(input), expected);
}

// Test case: Large numbers
TEST(RelativelyPrimeTest, LargeNumbers) {
    std::vector<int> input = {100, 200, 300};
    auto result = g(input);
    // Verify all neighbors are relatively prime
    for (size_t i = 0; i < result.size() - 1; i++) {
        EXPECT_EQ(std::gcd(result[i], result[i+1]), 1);
    }
}

// Test case: Mix of relatively prime and non-relatively prime
TEST(RelativelyPrimeTest, MixedCase) {
    std::vector<int> input = {2, 3, 6, 7};
    auto result = g(input);
    // Verify all neighbors are relatively prime
    for (size_t i = 0; i < result.size() - 1; i++) {
        EXPECT_EQ(std::gcd(result[i], result[i+1]), 1);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
