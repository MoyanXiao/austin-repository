#include <gtest/gtest.h>
#include "PostfixCalculator.h"

TEST(PostfixCalculatorTest, TestCalculate) {
    PostfixCalculator pc;
    std::string input = "5 1 2 + 4 * + 3 -";
    EXPECT_EQ(14, pc.calculate(input)) << "error return" << "\n";
    double a;
    EXPECT_EQ(true, pc.calculate_noexception(input, a)) << "error return" << "\n";
    EXPECT_EQ(14, a);
}


TEST(PostfixCalculatorTest, TestErrorParams) {
    PostfixCalculator pc;
    std::string input = "9a 5 1 2 + 4 * + 3 -";
    try {
        pc.calculate(input);
        FAIL();
    } catch (...) {
    }
    double a;
    EXPECT_EQ(false, pc.calculate_noexception(input, a)) << "error return" << "\n";
}

TEST(PostfixCalculatorTest, TestErrorNumberParams) {
    PostfixCalculator pc;
    std::string input = "9 5 1 2 + 4 * + 3 -";
    try {
        pc.calculate(input);
        FAIL();
    } catch (...) {
    }
    double a;
    EXPECT_EQ(false, pc.calculate_noexception(input, a)) << "error return" << "\n";
}
