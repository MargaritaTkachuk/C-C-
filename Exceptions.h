#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class ThreeByteException : public std::runtime_error {
public:
    explicit ThreeByteException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class OverflowException : public ThreeByteException {
public:
    OverflowException()
        : ThreeByteException("Error: Three-byte integer overflow") {}
};

class DivisionByZeroException : public ThreeByteException {
public:
    DivisionByZeroException()
        : ThreeByteException("Error: Division by zero") {}
};

#endif
