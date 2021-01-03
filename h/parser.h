#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stack>
#include <unordered_map>

#include "./node.h"

using std::string;
using std::stack;
using std::unordered_map;

class Parser {
    public:
        unordered_map<string, int> typelist;
        explicit Parser();
        void init();
        void generateTree(stack<string> tokens);
        Node* makeNode(string token);
};

#endif