#pragma once
#include "PoweredUnit.hpp"
#include <math.h>

template<typename Unit>
Unit Units::Complex::PoweredUnit<Unit, 2>::operator/(const Unit & rhs)
{
    return Unit(this->datum / rhs.RemoveUnits());
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>::PoweredUnit(long double datum)
    : datum(datum)
{}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>::PoweredUnit(long long datum)
    : datum(datum)
{}
#pragma warning(push)
#pragma warning(disable:4244)
template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>::PoweredUnit(unsigned long long datum)
    : datum(datum)
{}
#pragma warning(pop)

template<typename Unit>
long double Units::Complex::PoweredUnit<Unit, 2>::RemoveUnits() const
{
    return this->datum;
}

template<typename Unit>
const std::string Units::Complex::PoweredUnit<Unit, 2>::DisplayUnits()
{
    return Unit::DisplayUnits() + "^2";
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2> Units::Complex::PoweredUnit<Unit, 2>::operator-() const
{
    return PoweredUnit(this->datum*-1);
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2> & Units::Complex::PoweredUnit<Unit, 2>::operator+=(const PoweredUnit & rhs)
{
    this->datum += rhs.datum;
    return *this;
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2> & Units::Complex::PoweredUnit<Unit, 2>::operator+=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>& Units::Complex::PoweredUnit<Unit, 2>::operator-=(const PoweredUnit & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>& Units::Complex::PoweredUnit<Unit, 2>::operator-=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>& Units::Complex::PoweredUnit<Unit, 2>::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2>& Units::Complex::PoweredUnit<Unit, 2>::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

template<typename Unit>
bool Units::Complex::PoweredUnit<Unit, 2>::operator==(const PoweredUnit & rhs) const
{
    return this->datum == rhs.datum;
}

template<typename Unit>
bool Units::Complex::PoweredUnit<Unit, 2>::operator!=(const PoweredUnit & rhs) const
{
    return this->datum != rhs.datum;
}

template<typename Unit>
bool Units::Complex::PoweredUnit<Unit, 2>::operator>=(const PoweredUnit & rhs) const
{
    return this->datum >= rhs.datum;
}

template<typename Unit>
bool Units::Complex::PoweredUnit<Unit, 2>::operator<=(const PoweredUnit & rhs) const
{
    return this->datum <= rhs.datum;
}

template<typename Unit>
bool Units::Complex::PoweredUnit<Unit, 2>::operator<(const PoweredUnit & rhs) const
{
    return this->datum < rhs.datum;
}

template<typename Unit>
bool Units::Complex::PoweredUnit<Unit, 2>::operator>(const PoweredUnit & rhs) const
{
    return this->datum > rhs.datum;
}
