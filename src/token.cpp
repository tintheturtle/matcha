#include <string>
#include <unordered_map>
#include <iostream>

#include "../h/token.h"

using namespace std;
using std::unordered_map;

Token :: Token(const int t) : temp(t) {}

void Token :: init() {

    // Fill map with keywords
    tokenMap["def"] = "Keyword";
    tokenMap["int"] = "Keyword";
    tokenMap["return"] = "Keyword";
    tokenMap["print"] = "Keyword";
    tokenMap["==>"] = "Keyword";
    tokenMap["|"] = "Keyword";
    tokenMap["?"] = "Keyword";
    tokenMap["&&"] = "Keyword";
    tokenMap[":"] = "Keyword";

    
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
    tokenMap["<"] = "Operator";
    tokenMap["<="] = "Operator";
    tokenMap[">"] = "Operator";
    tokenMap[">="] = "Operator";
    tokenMap["=="] = "Operator";
    tokenMap["="] = "Operator";


    // Fill map with letters
    for (char c='a'; c<='z'; ++c)
		tokenMap[string(1, c)] = "Letter";
	for (char c='A'; c<='Z'; ++c)
		tokenMap[string(1, c)] = "Letter";

    // Fill map with numbers
    for (char c='0'; c<='9'; ++c)
		tokenMap[string(1, c)] = "Digit";


}

string Token :: classifyString(string input) {

    string res = "";

    if (input.empty()) {
        return "None";
    }

    // Check first and last character for braces/parenthesis
    // TODO: Fix nested braces/parenthesis by having a while(input[0] == '\c') loop
    if (input[0] == '{') {
        res += tokenMap["{"] + ": {" + "\n";
        input = input.substr(0);
    }

    if (input[0] == '(') {
        res += tokenMap["("] + ": (" + "\n";
        input = input.substr(0);
    }

    bool closeParent = false;
    if (input.back() == ')') {
        closeParent = true;
        input.pop_back();
    }

    bool closeBrace = false;
    if (input.back() == '}') {
        closeBrace = true;
        input.pop_back();
    }

    if (input.empty() == 0) {
        // Check for operators
        bool op = false;
        if (isOperator(input)) {
            res += tokenMap[input] + " : " + input + "\n";
            op = true;
        }

        // Check for digits
        bool digit = false;
        if (isDigit(input) && !op) {
            res += "Digit: " + input + "\n";
            digit = true;
        }

        // Check for keyword
        bool keyword = false;
        if (isKeyword(input) && !digit) {
            res += tokenMap[input] + ": " + input + "\n";
            keyword = true;
        }

        // Check for variable/identifier
        if (isValidIdentifier(input) && !keyword) {
            res +=  "Identifier: " + input + "\n";
        } 
    }

    if (closeParent) {
        res += tokenMap[")"] + ": )" +  + "\n";
    }

    if (closeBrace) {
        res += tokenMap["}"] + ": }" + "\n";
    }

    return res;

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
    return true;
}

bool Token :: isOperator(string input) {

    if (tokenMap[input] == "Operator") {
        return true;
    }
    return false;

}
