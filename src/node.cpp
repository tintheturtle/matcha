#include <iostream>
#include <string>

#include "../h/node.h"

using namespace std;

Node :: Node(NodeType nodeType) {
    type = nodeType;
}

NodeType Node :: getType() {
    return type;
}

void Node :: setOp(string operation) {
    op = operation;
}

void Node :: setNum(string number) {
    num = number;
}

string Node :: getOp() {
    return op;
}

string Node :: getNum() {
    return num;
}