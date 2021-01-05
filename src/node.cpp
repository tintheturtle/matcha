#include <iostream>
#include <string>

#include "../h/node.h"

using namespace std;

Node :: Node() {}

Node :: Node(NodeType nodeType) {
    type = nodeType;
}

void Node :: setType(NodeType nodeType) {
    type = nodeType;
}

NodeType Node :: getType() {
    return type;
}

void Node :: setOp(string operation) {
    op = operation;
}

string Node :: getOp() {
    return op;
}

void Node :: setNum(string number) {
    num = number;
}

string Node :: getNum() {
    return num;
}

void Node :: setBody(string bodyInfo) {
    body = bodyInfo;
}

string Node :: getBody() {
    return body;
}