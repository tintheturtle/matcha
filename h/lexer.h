#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <stack>

#include "../h/token.h"

using std::string;
using std::stack;

class Lexer {
    private:
        int temp;
        Token token;
    public:
        Lexer(const int temp = 0);
        void init();
        string readFile();
        stack<string> tokenizer(string code);
        int test();
};

#endif