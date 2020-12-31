#include <string>
#include "../h/token.h"

using namespace std;

Token :: Token(const int t) : temp(t) {}

string Token :: classifyString(string input) {

    for (std::string::size_type i = 0; i < input.size(); i++ ) {
        if (input[i] != ' ') {
            printf("%c\n", input[i]);
        }
    }

    return input;

}

