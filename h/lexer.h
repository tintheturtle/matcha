#ifndef LEXER_H
#define LEXER_H

class Lexer {
    private:
        int temp;
    public:
        Lexer(const int temp = 0);
        void readFile();
        void readString();
        int test();
};

#endif