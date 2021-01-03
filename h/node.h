#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

enum NodeType {
    Function = 0,
    Variable = 1,
    BinaryOperation = 2,
    Literal = 3,
    Brace = 4,
    Parenthesis = 5,
};

class Node {

    public:
        Node* left;
        Node* right;
        Node();
        Node(NodeType type);
        NodeType getType();
        void setOp(string operation);
        void setNum(string number);
        void setType(NodeType type);
        string getOp();
        string getNum();
    
    private:
        NodeType type;
        string op;
        string num;
};

#endif