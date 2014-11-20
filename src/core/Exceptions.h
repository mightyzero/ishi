#ifndef CORE_EXCEPTIONS_H
#define CORE_EXCEPTIONS_H

#include <exception> // std::exception

class BaseException : public std::exception {};

class TooManyArgumentException : public BaseException {};

#endif // CORE_EXCEPTIONS_H
