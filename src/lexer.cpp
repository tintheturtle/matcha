#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../h/lexer.h"

using namespace std;

Lexer :: Lexer(const int t) : temp(t) {}

string Lexer :: readFile() {

    // Object for reading file
    ifstream code;

    // Open file to read and get ASCII Test 
    // (Note: Must consider directory of makefile for handling files)
    code.open("./tests/fizzbuzz.txt",ios::in); 

    // Check if file is open
    if (code.is_open()){   
        string tmp;
        // Read each line in the file
        while(getline(code, tmp)){ 
            // Add line in string to tmp string
            cout << tmp;
        }
        // Close file
        code.close(); 

        return tmp;
    }

    return "Failed";

}

void Lexer :: readString() {

}

int Lexer :: test()
{
    return 1;
}