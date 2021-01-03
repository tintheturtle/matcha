#ifndef MATCHAEXCEPTION_H
#define MATCHAEXCEPTION_H

#include <exception>
#include <string>

using std::string;

class MatchaException : public std::exception {
    public: 
        MatchaException(int errorCode, const std::string &message) noexcept;
        int getErrorNumber() const throw();
        virtual ~MatchaException() = default;
        virtual const char* what() const noexcept override;

    private:
        int errorNumber;
        std::string errorMessage;
};

#endif