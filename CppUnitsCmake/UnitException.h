#pragma once
#include <stdexcept>
#include <typeinfo>
class UnitException :
    public std::runtime_error
{
public:
    UnitException();
    UnitException(const char* larger, long double datum, const char* smaller);
    ~UnitException();
};

