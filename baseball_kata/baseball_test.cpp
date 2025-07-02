#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, ThrowExceptionInvalidInputLength) {
    Baseball game; 
    EXPECT_THROW(game.guess(string{ "12" }), length_error);
}

TEST(BaseballGame, ThrowExceptionInvalidChar) {
    Baseball game;
    EXPECT_THROW(game.guess(string{ "12s" }), invalid_argument);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}