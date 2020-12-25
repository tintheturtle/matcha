#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../h/lexer.h"

using namespace std;

Lexer :: Lexer(const int t) : temp(t) {}

string Lexer :: readFile() {
    ifstream file;
    file.open("../tests/addition.txt");//open the input file

    string code;

    stringstream strStream;
    strStream << file.rdbuf();
    code = strStream.str();

    return code;
}

void Lexer :: readString() {
    
}

int Lexer :: test()
{
    return 1;
}