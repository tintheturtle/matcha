#include <iostream>
#include <string>

using namespace std;

#include "../h/lexer.h"
#include "../h/token.h"



int main() {

    // Instantiate Lexer
    Lexer lex; 
    Token token;

    // cout << token.classifyString("He ll o") << "\n";

    // Read file with code
    string code = lex.readFile();
    printf("%s\n", code.c_str());
    lex.tokenizer(code.c_str());


    // Hello World
    printf("%s\n", "Hello World");

    return 0;
}