#include <string>
#include <unordered_map>
#include <iostream>

#include "../h/token.h"

using namespace std;
using std::unordered_map;

Token :: Token(const int t) : temp(t) {}

void Token :: init() {

    // Fill map with keywords
    tokenMap["int"] = "Keyword";
    tokenMap["return"] = "Keyword"
    tokenMap["==>"] = "Keyword"
    tokenMap["|"] = "Keyword";
    
    // Fill map with braces and parenthesis
    tokenMap["("] = "OpenParenthesis";
    tokenMap[")"] = "CloseParenthesis";
    tokenMap["{"] = "OpenBrace";
    tokenMap["}"] = "CloseBrace";

    // Fill map with operators
    tokenMap["+"] = "Operator";
    tokenMap["-"] = "Operator";
    tokenMap["/"] = "Operator";
    tokenMap["*"] = "Operator";
    tokenMap["%"] = "Operator";

    // Fill map with letters
    for (char c='a'; c<='z'; ++c)
		tokenMap[string(1, c)] = "Letter";
	for (char c='A'; c<='Z'; ++c)
		tokenMap[string(1, c)] = "Letter";

    // Fill map with numbers
    for (char c='0'; c<='9'; ++c)
		tokenMap[string(1, c)]= "Digit";


}

string Token :: classifyString(string input) {


    // Check first and last character for braces/parenthesis
    if (input[0] == '(' || input[-1] == '{') {
        ;
    }

    if (input[-1] == ')' || input[-1] == '}') {
        ;
    }

    // Check for operators
    if (isOperator(input)) {
        ;
    }

    // Check for digits
    if (isDigit(input)) {
        ;
    }

    // Check for keyword
    if (isKeyword(input)) {
        ;
    }

    // Check for variable/identifier
    if (isValidIdentifier(input)) {
        ;
    }

    return input;

}


bool Token :: isKeyword(string input) { 
    if (tokenMap[input] == "Keyword") {
        return true;
    }
    return false;
}

bool Token :: isValidIdentifier(string input) {
    for (auto x : input) {
        if (tokenMap[string(1, x)] != "Letter") {
            return false;
        }
    }
    return true;
}

bool Token :: isDigit(string input) {
    for (auto x : input) {
        if (tokenMap[string(1, x)] != "Digit") {
            return false;
        }
    }
    return false;
}

bool Token :: isOperator(string input) {

    if (tokenMap[input] == "Operator") {
        return true;
    }
    return false;

}
