#include <gtest/gtest.h>
#include "PostfixCalculator.h"

TEST(PostfixCalculatorTest, TestCalculate) {
    PostfixCalculator pc;
    std::string input = "5 1 2 + 4 * + 3 -";
    EXPECT_EQ(0, pc.calculate(input)) << "error return" << "\n";
    EXPECT_EQ(14, pc.getResult()) << "result error" << "\n";
    EXPECT_STREQ(std::string("success").c_str(), pc.getResultMsg().c_str());

}
