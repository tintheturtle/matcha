#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>

#include "../h/parser.h"
#include "../h/node.h"

using namespace std;

Parser :: Parser() {
    
    typelist["OpenBrace"] = 0;
    typelist["OpenParenthesis"] = 1;
    typelist["Identifier"] = 2;
    typelist["Keyword"] = 3;
    typelist["Operator"] = 4;
    typelist["Digit"] = 5;
    typelist["CloseParenthesis"] = 6;
    typelist["CloseBrace"] = 7;

}

void Parser :: init() {}

void Parser :: generateTree(stack<string> tokens) {

    // Will have to manually clean up the AST

    Node* root = NULL;
    Node* curr = NULL;

    while(!tokens.empty()) {
        
        // Get top token, since C++ does not return the val on .pop()
        string token = tokens.top();

        // Make a node with the current token
        Node* res = makeNode(token);

        // Base Case first token will be made the root
        if (root == NULL) {
            root = res;
            curr = res;
        } else {
            // Construct AST 
            

        }

        // Debugging/visual statements
        cout << "Token found: " << token << endl;
        cout << "Made a node: " << res->getType() << endl;

        // Pop the top most token
        tokens.pop();
    }

}

Node* Parser :: makeNode(string token) {

    string word = "";
    string type = "";
    for (auto x : token) {
        if (x == ':')
        {
            type = word;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    Node *newNode = new Node();
    word = word.substr(0);

    int typeInt = typelist[type];
    
    switch(typeInt) {
        case 0:
            newNode->setType(NodeType::Brace);
            break;
        case 1:
            newNode->setType(NodeType::Parenthesis);
            break;
        case 2:
            newNode->setType(NodeType::Function);
            break;
        case 3:
            newNode->setType(NodeType::Variable);
            break;
        case 4:
            newNode->setType(NodeType::BinaryOperation);
            break;
        case 5:
            newNode->setType(NodeType::Literal);
            break;
        case 6:
             newNode->setType(NodeType::Parenthesis);
            break;
        case 7:
            newNode->setType(NodeType::Brace);
            break;
        default:
            newNode->setType(NodeType::Brace);
            break;
    }

    return newNode;
}