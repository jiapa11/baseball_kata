#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballGameFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertInvalidArgument(const string &userGuess) {
        try {
            game.guess(userGuess);
            FAIL();
        }
        catch (const std::exception& e) {
        }
    }

    void assertValidArgument(GuessResult expected, const string &userGuess) {
        GuessResult result = game.guess(userGuess);

        EXPECT_EQ(expected.allCorrect, result.allCorrect);
        EXPECT_EQ(expected.strikes, result.strikes);
        EXPECT_EQ(expected.balls, result.balls);
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

TEST_F(BaseballGameFixture, AllCorrect) {
    assertValidArgument({ true,3,0 }, "123");
}

TEST_F(BaseballGameFixture, AllWrong) {
    assertValidArgument({ false,0,0 }, "456");
}

TEST_F(BaseballGameFixture, PartiallyCorrect) {
    assertValidArgument({ false,2,0 }, "923");
    assertValidArgument({ false,1,2 }, "213");
    assertValidArgument({ false,1,2 }, "321");
    assertValidArgument({ false,1,2 }, "321");
    assertValidArgument({ false,1,0 }, "184");
    assertValidArgument({ false,2,0 }, "125");
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}