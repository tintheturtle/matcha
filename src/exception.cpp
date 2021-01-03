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

// class MatchaException: virtual public std::exception {

//     // Constructor
//     explicit MatchaException(const string& msg, int err_num):
//         error_message(msg),
//         error_number(err_num) 
//         {}

//     // Destructor
//     virtual ~MatchaException() throw () {}

//     // Returns pointer to error description
//     virtual const char* what() const throw () {
//        return error_message.c_str();
//     }

//     // Returns error number
//     virtual int getErrorNumber() const throw() {
//         return error_number;
//     }

// };