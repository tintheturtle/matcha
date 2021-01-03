#include <exception>
#include <string>

#include "../h/exception.h"

using namespace std;

MatchaException :: MatchaException(int err_num, const string& msg) noexcept:
    errorMessage(msg),
    errorNumber(err_num) 
    {}

const char* MatchaException::what() const throw() {
    return errorMessage.c_str();
}

int MatchaException::getErrorNumber() const throw() {
    return errorNumber;
}