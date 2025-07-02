#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballGameFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertInvalidArgument(string userGuess) {
        try {
            game.guess(userGuess);
            FAIL();
        }
        catch (const std::exception& e) {
        }
    }
};

TEST_F(BaseballGameFixture, ThrowExceptionInvalidInput) {
    assertInvalidArgument(string{ "12" });
    assertInvalidArgument(string{ "12s" });
    assertInvalidArgument(string{ "12ss" });
    assertInvalidArgument(string{ "1" });
    assertInvalidArgument(string{ "aaa" });
    assertInvalidArgument(string{ "121" });
}

TEST_F(BaseballGameFixture, ReturnValidResult) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);    
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}