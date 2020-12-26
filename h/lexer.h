#ifndef LEXER_H
#define LEXER_H

#include <string>

using std::string;

class Lexer {
    private:
        int temp;
    public:
        Lexer(const int temp = 0);
        string readFile();
        void readString();
        int test();
};

#endif