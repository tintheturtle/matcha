#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include "../h/lexer.h"

using namespace std;

Lexer :: Lexer(const int t) : temp(t) {}

// Takes a file and reads it into a string
string Lexer :: readFile() {

    // Object for reading file
    ifstream code;

    // Open file to read and get ASCII Test 
    // (Note: Must consider directory of makefile for handling files)
    code.open("./tests/fizzbuzz.txt",ios::in); 

    // Result string from file
    string res;

    // Check if file is open
    if (code.is_open()){   
        string tmp;
        // Read each line in the file
        while(getline(code, tmp)){ 
            // Add line in string to tmp string

            res = res + tmp;
        }
        // Close file
        code.close(); 

        return res;
    }

    return "Failed";

}

// Takes a string and tokenizes it
void Lexer :: tokenizer(string code) {

    // Initialize stack (holds tokens to return)
    stack<string> tokens;
    std::string tokenText = "";

    // Add end file symbol
    code = code + '\0';

    // Iterate through string
    for (auto x : code) {

        if ( x == ' ' || x == '\t' || x == '\0' ) {

            int whitespace = tokenText.compare(" ");
            int tab = tokenText.compare("\t");
            int newline = tokenText.compare("\n");

            if (whitespace > 0 && tab > 0 && newline > 0) {
                tokens.push(tokenText);
            } 
            tokenText = "";
        } else {
            tokenText = tokenText + x;
        }  
    }

    cout << tokens.top() << endl;

}

int Lexer :: test()
{
    return 1;
}