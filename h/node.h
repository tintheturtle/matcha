#ifndef NODE_H
#define NODE_H

enum NodeType {
    Operation = 0,
    Number = 1,
};

class Node {

    private:
        NodeType type;

    public:
        Node(NodeType type);
        NodeType getType();
};

#endif