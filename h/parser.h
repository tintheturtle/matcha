#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stack>
#include <unordered_map>
#include <tuple>

#include "./node.h"

using std::string;
using std::stack;
using std::unordered_map;

class Parser {
    public:
        unordered_map<string, int> typelist;
        unordered_map<char, int> opPrecedence;
        unordered_map<string, NodeType> keywordType;
        explicit Parser();
        void init();
        void generateTree(stack<string> tokens);
        void parseIfStatement();
        void parseLoopStatement();
        void parsePrintStatement();
        std::tuple<Node*, string> makeNode(string token);
        NodeType determineKeyword(string word);
};

#endif