#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using std::string;

struct GuessResult {
    bool allCorrect;
    int strikes, balls;
};

class Baseball {
public:
    explicit Baseball(const std::string& answer) : answer{ answer } 
    {
        for (int position = 0; position < LENGTH_OF_GUESS; position++) {
            int num = answer[position] - '0';
            numberToPosition[num] = position;
        }
    }

    GuessResult guess(const std::string &userGuess) {
        assertInvalidArgument(userGuess);
        if (answer == userGuess) return ALL_CORRECT;
        return evaluate(userGuess);
    }

private:    
    const static int LENGTH_OF_GUESS = 3;
    std::string answer;
    std::unordered_map<int, int> numberToPosition{};
    const struct GuessResult ALL_CORRECT = {true, 3, 0};

    void assertInvalidArgument(const std::string& userGuess)
    {
        if (userGuess.length() != LENGTH_OF_GUESS) {
            throw std::length_error("Must be exactly three letters");
        }

        for (const char& ch : userGuess) {
            if (ch >= '0' && ch <= '9') continue;
            throw std::invalid_argument("Must contain only numbers ");
        }

        if (hasDuplicateNumber(userGuess)) {
            throw std::invalid_argument("Each number in input must be unique");
        }
    }

    bool hasDuplicateNumber(const std::string& userGuess) {
        if (userGuess[0] == userGuess[1] ||
            userGuess[0] == userGuess[2] ||
            userGuess[1] == userGuess[2]) {
            return true;
        }
        return false;
    }

    const GuessResult& evaluate(const std::string& userGuess)
    {
        int strikes{ 0 }, balls{ 0 };
        for (int i = 0; i < LENGTH_OF_GUESS; i++) {
            int num = userGuess[i] - '0';
            auto search = numberToPosition.find(num);
            if (search == numberToPosition.end()) continue;
            else {
                if (i == search->second) strikes++;
                else balls++;
            }
        }

        return { false, strikes, balls };
    }

};