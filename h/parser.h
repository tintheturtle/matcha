#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stack>

using std::string;
using std::stack;

class Parser {
    public:
        explicit Parser();
        void init();
        void generateTree(stack<string> tokens);
};

#endif