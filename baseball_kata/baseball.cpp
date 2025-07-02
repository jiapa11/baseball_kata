#include <iostream>
#include <string>

using namespace std;
using std::string;

class Baseball {
public:
    void guess(const string &string) {
        if (string.length() != 3) {
            throw std::length_error("Must be exactly three letters");
        }
    }
};