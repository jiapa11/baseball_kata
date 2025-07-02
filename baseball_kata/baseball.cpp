#include <iostream>
#include <string>

using namespace std;
using std::string;

struct GuessResult {
    bool solved;
    int strikes, balls;
};

class Baseball {
public:
    explicit Baseball(const std::string& answer) : answer{ answer } {};

    GuessResult guess(const std::string &userGuess) {
        assertInvalidArgument(userGuess);
        if (answer == userGuess) return { true, 3, 0 };
    }

private:
    std::string answer;

    void assertInvalidArgument(const std::string& userGuess)
    {
        if (userGuess.length() != 3) {
            throw std::length_error("Must be exactly three letters");
        }

        for (const char& ch : userGuess) {
            if (ch >= '0' && ch <= '9') continue;
            throw std::invalid_argument("Must contain only numbers ");
        }

        if (isNumbersDuplicated(userGuess)) {
            throw std::invalid_argument("Each number in input must be unique");
        }
    }

    bool isNumbersDuplicated(const std::string& userGuess) {
        if (userGuess[0] == userGuess[1] ||
            userGuess[0] == userGuess[2] ||
            userGuess[1] == userGuess[3]) {
            return true;
        }
        return false;
    }
};