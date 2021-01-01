#ifndef LEXER_H
#define LEXER_H

#include <string>

#include "../h/token.h"

using std::string;

class Lexer {
    private:
        int temp;
        Token token;
    public:
        Lexer(const int temp = 0);
        void init();
        string readFile();
        void tokenizer(string code);
        int test();
};

#endif