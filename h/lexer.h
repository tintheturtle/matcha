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
        string readFile(string fileName);
        stack<string> tokenizer(string code);
        stack<string> cleanStack(stack<string> tokens);
        int test();
};

#endif