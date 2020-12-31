#include <string>
#include <unordered_map>
#include <iostream>

#include "../h/token.h"

using namespace std;
using std::unordered_map;

Token :: Token(const int t) : temp(t) {}

void Token :: init() {

    // Fill map with keywords
    tokenMap["int"] = "Keyword"
    tokenMap["|"] = "LoopConstructor"
    
    // Fill map with braces and parenthesis
    tokenMap["("] = "OpenParenthesis"
    tokenMap[")"] = "CloseParenthesis"
    tokenMap["{"] = "OpenBrace"
    tokenMap["}"] = "CloseBrace"

    // Fill map with operators
    tokenMap["+"] = "Operator"
    tokenMap["-"] = "Operator"
    tokenMap["/"] = "Operator"
    tokenMap["*"] = "Operator"
    tokenMap["%"] = "Operator"

    // Fill map with letters
    for (char c='a'; c<='z'; ++c)
		tokenMap[c] = "Letter";
	for (char c='A'; c<='Z'; ++c)
		tokenMap[c] = "Letter";

    // Fill map with numbers
    for (char c='0'; c<='9'; ++c)
		tokenMap[c]= "Digit";


}

string Token :: classifyString(string input) {

    cout << "10 : " << tokenMap["10"] << endl;

    // Check first and last character for braces/parenthesis
    if (input[0] == '(' || input[-1] == '{') {
        ;
    }

    if (input[-1] == ')' || input[-1] == '}') {
        ;
    }

    // Check for operators
    if (isOperator(input)) {
        
    }

    // Check for digits
    if (isDigit(input)) {

    }

    // Check for keyword
    if (isKeyword(input)) {

    }

    // Check for variable/identifier
    if (isValidIdentifier(input)) {

    }

    return input;

}


bool Token :: isKeyword(string input) {
    return false;
}

bool Token :: isValidIdentifier(string input) {
    return false;
}

bool Token :: isDigit(string input) {
    return false;
}

bool Token :: isOperator(string input) {
    return false;
}
