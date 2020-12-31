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
        enum Type {
            Identifier,
            Keyword,
            Separator,
            Operator,
            Literal,
            Comment,
            Whitespace,
            Endline
        };
};

#endif