#include <iostream>
#include <string>
#include <stack>

using namespace std;

#include "../h/lexer.h"
#include "../h/token.h"
#include "../h/parser.h"


int main() {

    // Instantiate Lexer, Parser, and Tokens
    Lexer lex; 
    Token token;
    Parser parser;

    // Read file with code
    string code = lex.readFile();
    lex.init();
    stack<string> tokens = lex.tokenizer(code.c_str());

    // Testing class methods

    parser.generateTree(tokens);


    // Hello World
    printf("%s\n", "Hello World");

    return 0;
}