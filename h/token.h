#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using std::string;

class Token {
    private:
        int temp;
    public:
        Token(const int temp = 0);
        int ink = 1;
        string classifyString(string input);
        bool isKeyword(string input);
        bool isValidIdentifier(string input);
        bool isDigit(string input);
        bool isOperator(string input);
};

#endif