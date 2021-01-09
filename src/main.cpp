#include <iostream>
#include <string>
#include <stack>

using namespace std;

#include "../h/lexer.h"
#include "../h/token.h"
#include "../h/parser.h"
#include "../h/node.h"


int main() {

    // Instantiate Lexer, Parser, and Tokens
    Lexer lex; 
    Token token;
    Parser parser;
    Node root = Node(NodeType::BinaryOperation);

    // Read file with code
    string name = "./tests/addition.txt";
    string code = lex.readFile(name);
    lex.init();
    stack<string> tokens = lex.tokenizer(code.c_str());

    // Testing class methods
    parser.generateTree(tokens);
    cout << root.getType() << endl;

    // Node testing
    Node *left = new Node(NodeType::Literal);
    left->setNum("10");
    cout << left->getNum() << endl;

    root.children.push_back(left);

    cout << root.children.at(0)->getType() << endl;


    // Hello World
    printf("%s\n", "Hello World");

    return 0;
}