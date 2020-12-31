#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Token {
    private:
        int temp;
        unordered_map<string, string> tokenMap;
    public:
        Token(const int temp = 0);
        void init();
        int ink = 1;
        string classifyString(string input);
        bool isKeyword(string input);
        bool isValidIdentifier(string input);
        bool isDigit(string input);
        bool isOperator(string input);
};

#endif