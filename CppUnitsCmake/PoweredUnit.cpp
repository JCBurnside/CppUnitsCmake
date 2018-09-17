#include "PoweredUnit.h"

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER> std::pow(const Unit& lhs)
{
    return Units::Complex::PoweredUnit<Unit, POWER>(std::pow(lhs.RemoveUnits(), POWER));
}

template<typename Unit, int STARTING_POWER, int RAISING_POWER>
Units::Complex::PoweredUnit<Unit, STARTING_POWER*RAISING_POWER> std::pow(const Units::Complex::PoweredUnit<Unit, STARTING_POWER>& lhs)
{
    return Units::Complex::PoweredUnit<Unit, STARTING_POWER*RAISING_POWER>(std::pow(lhs.RemoveUnits(), RAISING_POWER));
}

template<typename Unit, int POWER>
bool Units::Complex::operator==(const PoweredUnit<Unit, POWER>& lhs, const long double rhs)
{
    return lhs.datum == rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator!=(const PoweredUnit<Unit, POWER>& lhs, const long double rhs)
{
    return lhs.datum != rhs;
}


template<typename Unit, int POWER>
bool Units::Complex::operator>=(const PoweredUnit<Unit, POWER>& lhs, const long double rhs)
{
    return lhs.datum >= rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<=(const PoweredUnit<Unit, POWER>& lhs, const long double rhs)
{
    return lhs.datum <= rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<(const PoweredUnit<Unit, POWER>& lhs, const long double rhs)
{
    return lhs.datum < rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator>(const PoweredUnit<Unit, POWER>& lhs, const long double rhs)
{
    return lhs.datum > rhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator==(const long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs == lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator!=(const long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs != lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator>=(const long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs <= lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<=(const long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs >= lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator<(const long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs > lhs;
}

template<typename Unit, int POWER>
bool Units::Complex::operator>(const long double lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    return rhs < lhs;
}

template<typename Unit, int POWER_LEFT, int POWER_RIGHT>
Units::Complex::PoweredUnit<Unit, POWER_LEFT - POWER_RIGHT> Units::Complex::operator/(const PoweredUnit<Unit, POWER_LEFT>& lhs, const PoweredUnit<Unit, POWER_RIGHT>& rhs)
{
    return PoweredUnit<Unit, POWER_LEFT - POWER_RIGHT>(lhs.datum / rhs.datum);
}

template<typename Unit, int POWER>
long double Units::Complex::operator/(const Units::Complex::PoweredUnit<Unit, POWER>& lhs, const Units::Complex::PoweredUnit<Unit, POWER>& rhs)
{
    return lhs.datum / rhs.datum;
}

template<typename Unit>
Units::Complex::PoweredUnit<Unit, 2> Units::Complex::operator*(const Unit & lhs, const Unit & rhs)
{
    return PoweredUnit<Unit, 2>(lhs.RemoveUnits()*rhs.RemoveUnits());
}

template<typename Unit, int POWER>
Units::Complex::PoweredUnit<Unit, POWER + 1> Units::Complex::operator*(const PoweredUnit<Unit, POWER>& lhs, const Unit & rhs)
{
    return PoweredUnit<Unit, POWER + 1>(lhs.datum*rhs.RemoveUnits());
}

template<typename Unit, int POWER_LEFT, int POWER_RIGHT>
Units::Complex::PoweredUnit<Unit, POWER_LEFT + POWER_RIGHT> Units::Complex::operator*(const PoweredUnit<Unit, POWER_LEFT>& lhs, const PoweredUnit<Unit, POWER_RIGHT>& rhs)
{
    return PoweredUnit<Unit, POWER_LEFT + POWER_RIGHT>(lhs.datum*rhs.datum);
}

template<typename Unit, int POWER>
std::ostream & Units::Complex::operator<<(std::ostream & lhs, const PoweredUnit<Unit, POWER>& rhs)
{
    lhs<<rhs.datum<<rhs.DisplayUnits();
    return lhs;
}

template<typename Unit, int POWER>
std::istream & Units::Complex::operator>>(std::istream & lhs, PoweredUnit<Unit, POWER>& rhs)
{
    long double in;
    lhs>>in;
    rhs=in;
    return lhs;
}

