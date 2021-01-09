#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <tuple>

#include "../h/parser.h"
#include "../h/node.h"
#include "../h/exception.h"

using namespace std;

stack<string> globalTokens;

Parser :: Parser() {

    typelist["Program"] = -1;
    typelist["Keyword"] = 0;
    typelist["Function"] = 1;
    typelist["Variable"] = 2;
    typelist["Operator"] = 3;
    typelist["Identifier"] = 4;
    // Brace/Parenthesis Types
    typelist["OpenBrace"] = 5;
    typelist["OpenParenthesis"] = 6;
    typelist["CloseParenthesis"] = 7;
    typelist["CloseBrace"] = 8;
    // Keyword Types
    typelist["IfStatement"] = 9;
    typelist[" ElseStatement"] = 10;
    typelist["Condition"] = 11;
    typelist["Print"] = 12;
    // Logical Op Types
    typelist["And"] = 13;
    typelist["Or"] = 14;
    typelist["Not"] = 15;

    // Creating a precedence for operations
    opPrecedence['+'] = 2;
    opPrecedence['-'] = 2;

    // Keyword Type Map
    keywordType["def"] = NodeType::Function;
    keywordType["==>"] = NodeType::Function;
    keywordType["int"] = NodeType::Variable;
    keywordType[":"] = NodeType::Variable;
    keywordType["for"] = NodeType::Loop;
    keywordType["|"] = NodeType::Loop;
    keywordType["print"] = NodeType::Print;
    keywordType["&&"] = NodeType::And;

}

void Parser :: init() {}

/*
*   Method for generating an AST
*/
void Parser :: generateTree(stack<string> tokens) {

    // Will have to manually clean up the AST

    // Pointers for initial AST Nodes
    Node* root = new Node(NodeType::Program);
    Node* curr = root;

    // Previous Type and Token
    string prevToken = "";

    int counter = 0;

    while(!tokens.empty()) {
        
        // Get top token and then pop, since C++ does not return the val on .pop()
        string token = tokens.top();
        tokens.pop();

        // Make a node with the current token
        auto nodeRes = makeNode(token);
        Node* res = std::get<0>(nodeRes);
        string object = std::get<1>(nodeRes);

        Node* prev = root;

        /*
            Function Arg Parsing
            First Function keyword == def
            Second Function keyword == ==>
        */ 
        if (res->getType() == NodeType::Function || prevToken == "def") {

            // Function Declaration
            if (object == "def") {
                curr = res;
            }

            // Args parsed and move on to body
            if (object == "==>") {
                prevToken = "==>";
            }
            continue;
        }

        /*
            Function Body
        */
        if (res->getType() == NodeType::OpenBrace && prevToken == "==>") {

            // Refer back to Function Declaration Node 
           
            
            continue;
        }




        // Debugging/visual statements
        cout << counter << " Type Made : " << res->getType() << " : " << token << endl;
        counter++;

        // Pop the top most token and set prevToken
        prevToken = token;
    }

}

/*
*   Method for parsing an args of a function
*/
stack<string> Parser :: parseArgs(Node* root, stack<string> tokens) {

    Node* args = root;

    int counter = 0;
    while(!tokens.empty()) {   

        if (counter == 4) {
            break;
        }

        cout << "Popped in Parse Args: " << tokens.top() << endl;
        counter++;
        tokens.pop();

    }

    return tokens;

}

/*
*   Method for parsing an if statement
*/
void Parser :: parseIfStatement() {

}

/*
*   Method for parsing an if statement
*/
void Parser :: parseLoopStatement() {

}

/*
*   Method for parsing an if statement
*/
void Parser :: parsePrintStatement() {

}

/*
*   Method for creating an AST Node
*/
std::tuple<Node*, string> Parser :: makeNode(string token) {

    string word = "";
    string type = "";
    bool semicolon = false;
    for (auto x : token) {
        if (x == ':' && !semicolon)
        {
            type = word;
            word = "";
            semicolon = true;
        }
        else {
            word = word + x;
        }
    }
    Node *newNode = new Node();

    try {
        word = word.substr(1);
    } catch(const std::out_of_range& oor) {
        throw(MatchaException(100, "Error with Parser"));
    }

    int typeInt = typelist[type];
    
    switch(typeInt) {
        case -1: 
            newNode->setType(NodeType::Program);
        case 0:
            newNode->setType(keywordType[word]);
            break;
        case 1:
            newNode->setType(NodeType::Function);
            break;
        case 2:
            newNode->setType(NodeType::Variable);
            break;
        case 3:
            newNode->setType(NodeType::BinaryOperation);
            break;
        case 4:
            newNode->setType(NodeType::Literal);
            break;
        case 5:
            newNode->setType(NodeType::OpenBrace);
            break;
        case 6:
             newNode->setType(NodeType::OpenParenthesis);
            break;
        case 7:
            newNode->setType(NodeType::CloseParenthesis);
            break;
        case 8:
            newNode->setType(NodeType::CloseBrace);
            break;
        default:
            throw(MatchaException(404, "Syntax Error"));
            break;
    }

    return std::make_tuple(newNode, word);
}
