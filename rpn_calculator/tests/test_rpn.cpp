#include <gtest/gtest.h>
#include "rpn.h"
#include <stdexcept>

TEST(RPNTest, BasicAddition) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("2 3 +"), 5.0);
}

TEST(RPNTest, ComplexExpression) {
    EXPECT_NEAR(evaluate_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -"), 5.0, 1e-9);
}

TEST(RPNTest, DivisionByZero) {
    EXPECT_THROW(evaluate_rpn("1 0 /"), std::invalid_argument);
}

TEST(RPNTest, InvalidExpression) {
    EXPECT_THROW(evaluate_rpn("2 +"), std::invalid_argument);
}

TEST(RPNTest, PowerOperation) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("2 3 ^"), 8.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("4 0.5 ^"), 2.0);
}

TEST(RPNTest, ModuloOperation) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("7 3 %"), 1.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("10 5 %"), 0.0);
}

TEST(RPNTest, NegateOperation) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("5 ~"), -5.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("-3 ~"), 3.0);
}

TEST(RPNTest, IncrementDecrement) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("5 ++"), 6.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("5 --"), 4.0);
}

TEST(RPNTest, FactorialOperation) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("5 !"), 120.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("0 !"), 1.0);
}

TEST(RPNTest, ModuloRequiresIntegers) {
    EXPECT_THROW(evaluate_rpn("5.5 2 %"), std::invalid_argument);
}

TEST(RPNTest, FactorialRequiresNonNegativeInteger) {
    EXPECT_THROW(evaluate_rpn("-1 !"), std::invalid_argument);
    EXPECT_THROW(evaluate_rpn("2.5 !"), std::invalid_argument);
}

TEST(RPNTest, ComplexExpressionsWithNewOperators) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("5 ~ 3 * 2 ^"), 225.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("10 3 % 2 +"), 3.0);
}
