#include <iostream>
#include <string>

using namespace std;
using std::string;

class Baseball {
public:
    void guess(const string &userGuess) {
        if (userGuess.length() != 3) {
            throw std::length_error("Must be exactly three letters");
        }

        for (const char &ch : userGuess) {
            if (ch < '0' || ch > '9') {
                throw std::invalid_argument("Must contain only numbers ");
            }
        }
    }
};