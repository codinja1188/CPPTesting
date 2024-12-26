#include "../src/app.h"
#include <gtest/gtest.h>

TEST(g, Basic) {
    EXPECT_EQ(g("I"), 1);
    EXPECT_EQ(g("V"), 5);
    EXPECT_EQ(g("X"), 10);
    EXPECT_EQ(g("L"), 50);
    EXPECT_EQ(g("C"), 100);
    EXPECT_EQ(g("D"), 500);
    EXPECT_EQ(g("M"), 1000);
}

TEST(g, Addition) {
    EXPECT_EQ(g("III"), 3);
    EXPECT_EQ(g("VIII"), 8);
    EXPECT_EQ(g("XXXI"), 31);
    EXPECT_EQ(g("LXXX"), 80);
    EXPECT_EQ(g("CCC"), 300);
    EXPECT_EQ(g("DCC"), 700);
    EXPECT_EQ(g("MM"), 2000);
}

TEST(g, Subtraction) {
    EXPECT_EQ(g("IV"), 4);
    EXPECT_EQ(g("IX"), 9);
    EXPECT_EQ(g("XL"), 40);
    EXPECT_EQ(g("XC"), 90);
    EXPECT_EQ(g("CD"), 400);
    EXPECT_EQ(g("CM"), 900);
}

TEST(g, Combined) {
    EXPECT_EQ(g("XIV"), 14);
    EXPECT_EQ(g("XIX"), 19);
    EXPECT_EQ(g("XXIV"), 24);
    EXPECT_EQ(g("XLIX"), 49);
    EXPECT_EQ(g("XCIX"), 99);
    EXPECT_EQ(g("CDXCIX"), 499);
    EXPECT_EQ(g("CMXCIX"), 999);
    EXPECT_EQ(g("MCMXCIV"), 1994);
    EXPECT_EQ(g("MMMCMXCIX"), 3999);
}

TEST(g, Invalid) {
    EXPECT_EQ(g("IIII"), 0);
    EXPECT_EQ(g("VV"), 0);
    EXPECT_EQ(g("XXXX"), 0);
    EXPECT_EQ(g("LL"), 0);
    EXPECT_EQ(g("CCCC"), 0);
    EXPECT_EQ(g("DD"), 0);
    EXPECT_EQ(g("MMMM"), 0);
    EXPECT_EQ(g("VX"), 0);
    EXPECT_EQ(g("LC"), 0);
    EXPECT_EQ(g("DM"), 0);
    EXPECT_EQ(g("IL"), 0);
    EXPECT_EQ(g("IC"), 0);
    EXPECT_EQ(g("ID"), 0);
    EXPECT_EQ(g("IM"), 0);
    EXPECT_EQ(g("XD"), 0);
    EXPECT_EQ(g("XM"), 0);
    EXPECT_EQ(g("") , 0);
    EXPECT_EQ(g("ABCDEFG"), 0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}