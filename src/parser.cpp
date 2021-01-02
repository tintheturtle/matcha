#include <string>
#include <iostream>
#include <stack>

#include "../h/parser.h"

using namespace std;

Parser :: Parser() {}

void Parser :: init() {}

void Parser :: generateTree(stack<string> tokens) {

    cout << tokens.top() << endl;

}