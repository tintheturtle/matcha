#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

enum NodeType {
    Program = -1,
    Keyword = 0,
    Function = 1,
    Variable = 2,
    BinaryOperation = 3,
    Literal = 4,
    // Brace/Parenthesis Types
    OpenBrace = 5,
    OpenParenthesis = 6,
    CloseParenthesis = 7,
    CloseBrace = 8,
    // Keyword Types
    IfStatement = 9,
    ElseStatement = 10,
    Condition = 11,
    Print = 12,
    // Logical Op Types
    And = 13,
    Or = 14,
    Not = 15,
    // Loop Types
    Loop = 16,
};

class Node {

    private:
        NodeType type;
        string op;
        string num;
        string body;

    public:
        vector<Node*> children;
        Node();
        Node(NodeType type);
        void setType(NodeType type);
        NodeType getType();
        void setOp(string operation);
        string getOp();
        void setNum(string number);
        string getNum();
        void setBody(string bodyInfo);
        string getBody();

};

#endif