#pragma once
#include "PoweredUnit.h"
#include <math.h>

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>::PoweredUnit(long double datum)
    : datum(datum)
{}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>::PoweredUnit(long long datum)
    : datum(datum)
{}
#pragma warning(push)
#pragma warning(disable:4244)
template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>::PoweredUnit(unsigned long long datum)
    : datum(datum)
{}
#pragma warning(pop)

template<typename Unit, int POWER>
long double Units::Complex::PoweredUnit<Unit, POWER>::RemoveUnits() const
{
    return this->datum;
}

template<typename Unit, int POWER>
const std::string Units::Complex::PoweredUnit<Unit, POWER>::DisplayUnits()
{
    return Unit::DisplayUnits()+"^"+POWER;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER> Units::Complex::PoweredUnit<Unit, POWER>::operator-() const
{
    return PoweredUnit(this->datum*-1);
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER> & Units::Complex::PoweredUnit<Unit, POWER>::operator+=(const PoweredUnit & rhs)
{
    this->datum += rhs.datum;
    return *this;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER> & Units::Complex::PoweredUnit<Unit, POWER>::operator+=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>& Units::Complex::PoweredUnit<Unit, POWER>::operator-=(const PoweredUnit & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>& Units::Complex::PoweredUnit<Unit, POWER>::operator-=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>& Units::Complex::PoweredUnit<Unit, POWER>::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER>& Units::Complex::PoweredUnit<Unit, POWER>::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER - 1> Units::Complex::PoweredUnit<Unit, POWER>::operator/(const Unit & rhs)
{
    return PoweredUnit<Unit, POWER - 1>(this->datum/rhs.RemoveUnits());
}

template<typename Unit, int POWER>
bool Units::Complex::PoweredUnit<Unit, POWER>::operator==(const PoweredUnit & rhs) const
{
    return this->datum == rhs.datum;
}

template<typename Unit, int POWER>
bool Units::Complex::PoweredUnit<Unit, POWER>::operator!=(const PoweredUnit & rhs) const
{
    return this->datum != rhs.datum;
}

template<typename Unit, int POWER>
bool Units::Complex::PoweredUnit<Unit, POWER>::operator>=(const PoweredUnit & rhs) const
{
    return this->datum >= rhs.datum;
}

template<typename Unit, int POWER>
bool Units::Complex::PoweredUnit<Unit, POWER>::operator<=(const PoweredUnit & rhs) const
{
    return this->datum <= rhs.datum;
}

template<typename Unit, int POWER>
bool Units::Complex::PoweredUnit<Unit, POWER>::operator<(const PoweredUnit & rhs) const
{
    return this->datum < rhs.datum;
}

template<typename Unit, int POWER>
bool Units::Complex::PoweredUnit<Unit, POWER>::operator>(const PoweredUnit & rhs) const
{
    return this->datum > rhs.datum;
}
