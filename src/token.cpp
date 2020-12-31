#include <string>
#include "../h/token.h"

using namespace std;

Token :: Token(const int t) : temp(t) {}

string Token :: classifyString(string input) {

    // Check first and last character for braces/parenthesis
    if (input[0] == '(' || input[-1] == '{') {
        ;
    }

    if (input[-1] == ')' || input[-1] == '}') {
        ;
    }



    return input;

}


bool Token :: isKeyword(string input) {
    return false;
}

bool Token :: isValidIdentifier(string input) {
    return false;
}

bool Token :: isDigit(string input) {
    return false;
}

bool Token :: isOperator(string input) {
    return false;
}
