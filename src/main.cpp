#include <iostream>
#include <string>

using namespace std;

#include "../h/lexer.h"



int main() {

    Lexer mc; 
    int test = mc.test();
    mc.readFile();

    printf("%d\n", test);


    printf("%s\n", "Hello World");

    return 0;
}