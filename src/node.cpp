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