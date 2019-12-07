// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <usualStack.h>
#include "stackArgs.h"

TEST(Example, PushTest) {
    int a = 0;
    usualStack<int> US{};
    stackArgs<std::pair<int, int>> SA{};
    EXPECT_THROW(US.head(), std::exception);
    EXPECT_THROW(SA.head(), std::exception);
    SA.push_emplace(1, 2);
    auto expectedPair = std::make_pair(1, 2);
    for (int i = 0; i < 5; i++) {
        US.push(a);
        a++;
    }
    EXPECT_EQ(US.head(), 4);
    EXPECT_EQ(SA.head(), expectedPair);
}

TEST(Example, PopTest) {
    usualStack<double> US{};
    stackArgs<std::pair<int, int>> SA{};
    EXPECT_THROW(US.pop(), std::exception);
    EXPECT_THROW(SA.pop(), std::exception);
    US.push(1.1);
    US.push(3);
    SA.push_emplace(4, 5);
    SA.push_emplace(0, 0);
    EXPECT_EQ(US.head(), 3);

    auto expectedPair = std::make_pair(0, 0);
    EXPECT_EQ(SA.head(), expectedPair);
    expectedPair = SA.pop();
    auto expectedPairAfterRop = std::make_pair(4, 5);
    EXPECT_EQ(SA.pop(), expectedPairAfterRop);
    US.pop();
    EXPECT_EQ(US.head(), 1.1);
}

TEST(Example, MoveTest) {
    std::string str = "text";
    usualStack<std::string> US{};
    US.push(std::move(str));
    EXPECT_EQ(US.head(), "text");
    EXPECT_TRUE(str.empty());
}

TEST(Example, IsMoveConstructible) {
    EXPECT_TRUE(std::is_move_constructible<usualStack<int>>());
    using stackArgsCheck =
            std::is_move_constructible<stackArgs<std::pair<int, int>>>;
    EXPECT_TRUE(stackArgsCheck());
}

TEST(Example, IsMoveAssignable) {
    EXPECT_TRUE(std::is_move_assignable<usualStack<double>>());
    using stackArgsCheck =
            std::is_move_assignable<stackArgs<std::pair<int, double>>>;
    EXPECT_TRUE(stackArgsCheck());
}

