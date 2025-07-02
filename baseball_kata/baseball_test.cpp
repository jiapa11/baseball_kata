#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballGameFixture : public testing::Test {
public:
    Baseball game;
    void assertIllegalArgument(string userGuess) {
        try {
            game.guess(userGuess);
            FAIL();
        }
        catch (const std::exception& e) {
        }
    }
};

TEST_F(BaseballGameFixture, ThrowExceptionInvalidInput) {
    assertIllegalArgument(string{ "12" });
    assertIllegalArgument(string{ "12s" });
    assertIllegalArgument(string{ "12ss" });
    assertIllegalArgument(string{ "1" });
    assertIllegalArgument(string{ "aaa" });
    assertIllegalArgument(string{ "121" });
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}