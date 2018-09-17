#pragma once
#include "PoweredUnit.h"
template<typename Unit, int POWER>
bool Units::Complex::operator==(const PoweredUnit<Unit, POWER>& lhs, long double rhs)
{
    return lhs.RemoveUnits() == rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator!=(const PoweredUnit<Unit, POWER>& lhs, long double rhs)
{
    return lhs.RemoveUnits() != rhs;
}


template<typename Unit, int POWER>
bool Units::Complex::operator>=(const PoweredUnit<Unit, POWER>& lhs, long double rhs)
{
    return lhs.RemoveUnits() >= rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<=(const PoweredUnit<Unit, POWER>& lhs, long double rhs)
{
    return lhs.RemoveUnits() <= rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<(const PoweredUnit<Unit, POWER>& lhs,  long double rhs)
{
    return lhs.RemoveUnits() < rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator>(const PoweredUnit<Unit, POWER>& lhs,  long double rhs)
{
    return lhs.RemoveUnits() > rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator==( long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs == lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator!=( long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs != lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator>=( long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs <= lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<=( long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs >= lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<( long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs > lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator>( long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs < lhs;
}

template<typename Unit, int POWER_LEFT, int POWER_RIGHT>
Units::Complex::PoweredUnit<Unit, POWER_LEFT - POWER_RIGHT> Units::Complex::operator/(const PoweredUnit<Unit, POWER_LEFT>& lhs, const PoweredUnit<Unit, POWER_RIGHT>& rhs)
{
    return PoweredUnit<Unit, POWER_LEFT - POWER_RIGHT>(lhs.RemoveUnits() / rhs.RemoveUnits());
}

template<typename Unit, int POWER>
long double Units::Complex::operator/(const Units::Complex::PoweredUnit<Unit, POWER>& lhs, const Units::Complex::PoweredUnit<Unit, POWER>& rhs)
{
    return lhs.RemoveUnits() / rhs.RemoveUnits();
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2> Units::Complex::operator*(const Unit & lhs, const Unit & rhs)
{
    return PoweredUnit<Unit, 2>(lhs.RemoveUnits()*rhs.RemoveUnits());
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER + 1> Units::Complex::operator*(const PoweredUnit<Unit, POWER>& lhs, const Unit & rhs)
{
    return PoweredUnit<Unit, POWER + 1>(lhs.RemoveUnits() *rhs.RemoveUnits());
}

template<typename Unit, int POWER_LEFT, int POWER_RIGHT>
Units::Complex::PoweredUnit<Unit, POWER_LEFT + POWER_RIGHT> Units::Complex::operator*(const PoweredUnit<Unit, POWER_LEFT>& lhs, const PoweredUnit<Unit, POWER_RIGHT>& rhs)
{
    return PoweredUnit<Unit, POWER_LEFT + POWER_RIGHT>(lhs.RemoveUnits() * rhs.RemoveUnits());
}

template<typename Unit, int POWER>
std::ostream & Units::Complex::operator<<(std::ostream & lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    lhs << rhs.RemoveUnits() << rhs.DisplayUnits();
    return lhs;
}

template<typename Unit, int POWER>
std::istream & Units::Complex::operator>>(std::istream & lhs, PoweredUnit<Unit, POWER>& rhs)
{
    long double in;
    lhs >> in;
    rhs = in;
    return lhs;
}
