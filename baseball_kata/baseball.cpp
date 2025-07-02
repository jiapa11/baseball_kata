#include <iostream>
#include <string>

using namespace std;
using std::string;

class Baseball {
public:
    void guess(const string &userGuess) {
        assertIllegalArgument(userGuess);
    }

private:
    void assertIllegalArgument(const std::string& userGuess)
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