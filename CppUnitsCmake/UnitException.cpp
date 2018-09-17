#include "UnitException.h"
#include <string>


UnitException::UnitException()
    : std::runtime_error("WE ARE GOING TO NEED A BIGGER UNIT!")
{
}

UnitException::UnitException(const char* larger, long double datum, const char* smaller)
    : std::runtime_error("WE ARE GOING TO NEED A BIGGER UNIT! " + std::to_string(datum) + " " + larger + " is too large to fit into " + smaller)
{
}

UnitException::~UnitException()
{
}
