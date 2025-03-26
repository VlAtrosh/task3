#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class BankException : public std::exception {
private:
    std::string message;
public:
    BankException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException() : BankException("Insufficient funds") {}
};


#endif