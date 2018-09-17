#include "Kilometer.h"
#include "Distance.h"
#include <ostream>


Units::Distance::Kilometer::Kilometer()
    : datum(0)
{}

Units::Distance::Kilometer::Kilometer(long double datum)
    : datum(datum)
{}

#pragma warning (push)
#pragma warning (disable:4244)
Units::Distance::Kilometer::Kilometer(unsigned long long datum)
    : datum(datum)
{}

Units::Distance::Kilometer::Kilometer(long long datum)
    : datum(datum)
{}
#pragma warning (pop)
Units::Distance::Kilometer::Kilometer(const Inch & inches)
    : datum(inches.datum / 39370.0L)
{}

Units::Distance::Kilometer::Kilometer(const Foot & feet)
    : datum(feet.datum * .0039624L)
{}

Units::Distance::Kilometer::Kilometer(const Meter & meters)
    : datum(meters.datum / 1000.0L)
{}

Units::Distance::Kilometer::Kilometer(const Millimeter & millimeter)
    : datum(millimeter.datum / 1e6)
{}

Units::Distance::Kilometer::~Kilometer()
{}

long double Units::Distance::Kilometer::RemoveUnits()
{
    return this->datum;
}

Units::Distance::Kilometer Units::Distance::Kilometer::operator-() const
{
    return Kilometer(this->datum * -1);
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator=(const long double rhs)
{
    this->datum = datum;
    return *this;
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator+=(const Kilometer & rhs)
{
    this->datum += rhs.datum;
    return *this;
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator+=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator-=(const Kilometer & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator-=(const long double rhs)
{
    this->datum -= rhs;
    return *this;
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

Units::Distance::Kilometer & Units::Distance::Kilometer::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

bool Units::Distance::Kilometer::operator==(const Kilometer & rhs) const
{
    return this->datum == rhs.datum;
}

bool Units::Distance::Kilometer::operator==(const long double rhs) const
{
    return this->datum == rhs;
}

bool Units::Distance::Kilometer::operator!=(const Kilometer & rhs) const
{
    return this->datum != rhs.datum;
}

bool Units::Distance::Kilometer::operator!=(const long double rhs) const
{
    return this->datum != rhs;
}

bool Units::Distance::Kilometer::operator<=(const Kilometer & rhs) const
{
    return this->datum <= rhs.datum;
}

bool Units::Distance::Kilometer::operator<=(const long double rhs) const
{
    return this->datum <= rhs;
}

bool Units::Distance::Kilometer::operator>=(const Kilometer & rhs) const
{
    return this->datum >= rhs.datum;
}

bool Units::Distance::Kilometer::operator>=(const long double rhs) const
{
    return this->datum >= rhs;
}

bool Units::Distance::Kilometer::operator>(const Kilometer & rhs) const
{
    return this->datum > rhs.datum;
}

bool Units::Distance::Kilometer::operator>(const long double rhs) const
{
    return this->datum > rhs;
}

bool Units::Distance::Kilometer::operator<(const Kilometer & rhs) const
{
    return this->datum < rhs.datum;
}

bool Units::Distance::Kilometer::operator<(const long double rhs) const
{
    return this->datum < rhs;
}

Units::Distance::Kilometer Units::Distance::Kilometer::operator++()
{
    this->datum++;
    return *this;
}

Units::Distance::Kilometer Units::Distance::Kilometer::operator++(int)
{
    Kilometer temp = *this;
    this->datum++;
    return temp;
}

Units::Distance::Kilometer Units::Distance::Kilometer::operator--()
{
    this->datum--;
    return *this;
}

Units::Distance::Kilometer Units::Distance::Kilometer::operator--(int)
{
    Kilometer temp = *this;
    this->datum--;
    return temp;
}

Units::Distance::Kilometer Units::Distance::operator+(Kilometer lhs, const Kilometer & rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Kilometer Units::Distance::operator+(Kilometer lhs, const long double rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Kilometer Units::Distance::operator+(const long double lhs, Kilometer rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Kilometer Units::Distance::operator-(Kilometer lhs, const Kilometer & rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Kilometer Units::Distance::operator-(Kilometer lhs, const long double rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Kilometer Units::Distance::operator-(const long double lhs, const Kilometer & rhs)
{
    return Kilometer(lhs - rhs.datum);
}

Units::Distance::Kilometer Units::Distance::operator*(Kilometer lhs, const long double rhs)
{
    lhs *= rhs;
    return lhs;
}

Units::Distance::Kilometer Units::Distance::operator*(const long double lhs, Kilometer rhs)
{
    rhs *= lhs;
    return rhs;
}

Units::Distance::Kilometer Units::Distance::operator/(Kilometer lhs, const long double rhs)
{
    lhs /= rhs;
    return lhs;
}

long double Units::Distance::operator/(const Kilometer & lhs, const Kilometer & rhs)
{
    return lhs.datum / rhs.datum;
}

bool Units::Distance::operator!=(const long double lhs, const Kilometer & rhs)
{
    return rhs != lhs;
}

bool Units::Distance::operator==(const long double lhs, const Kilometer & rhs)
{
    return rhs == lhs;
}

bool Units::Distance::operator<=(const long double lhs, const Kilometer & rhs)
{
    return rhs >= lhs;
}

bool Units::Distance::operator>=(const long double lhs, const Kilometer & rhs)
{
    return rhs <= lhs;
}

bool Units::Distance::operator<(const long double lhs, const Kilometer & rhs)
{
    return rhs > lhs;
}

bool Units::Distance::operator>(const long double lhs, const Kilometer & rhs)
{
    return rhs < lhs;
}

std::ostream & Units::Distance::operator<<(std::ostream & os, const Kilometer & self)
{
    os << self.datum << " km";
    return os;
}

Units::Distance::Kilometer Units::Distance::Literals::operator""_km(long double datum)
{
    return Kilometer(datum);
}

Units::Distance::Kilometer Units::Distance::Literals::operator""_km(unsigned long long datum)
{
    return Kilometer(datum);
}
