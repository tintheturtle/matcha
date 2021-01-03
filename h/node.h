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

    private:
        NodeType type;
        string op;
        string num;
        string body;

    public:
        Node* left;
        Node* right;
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