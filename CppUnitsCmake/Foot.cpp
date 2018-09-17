#include "Foot.h"
#include "Inch.h"
#include "Meter.h"
#include "Millimeter.h"
#include <utility>
#include <cmath>
#include <ostream>

Units::Distance::Foot::Foot()
    :datum(0)
{}

Units::Distance::Foot::Foot(long double datum)
    : datum(datum)
{}

Units::Distance::Foot::Foot(const Units::Distance::Inch & inches)
    : datum(inches.datum / 12.0L)
{}

Units::Distance::Foot::Foot(const Units::Distance::Meter & meters)
    : datum(meters.datum*3.28084)
{}

Units::Distance::Foot::Foot(const Millimeter & millimeters)
    : datum(millimeters.datum * .00328084)
{}

Units::Distance::Foot::Foot(long long datum, const Units::Distance::Inch& inches)
    : datum(datum + (inches.RemoveUnits() / 12.0L))
{}

#pragma warning (push)
#pragma warning (disable:4244)
Units::Distance::Foot::Foot(long long datum)
    : datum(datum)
{}

Units::Distance::Foot::Foot(unsigned long long datum)
    : datum(datum)
{}
#pragma warning (pop)
Units::Distance::Foot::~Foot()
{}

long double Units::Distance::Foot::RemoveUnits()
{
    return this->datum;
}

Units::Distance::Foot Units::Distance::Foot::operator-() const
{
    return Foot(-this->datum);
}


Units::Distance::Foot& Units::Distance::Foot::operator=(const long double rhs)
{
    this->datum = rhs;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator+=(const Units::Distance::Foot & rhs)
{
    this->datum = rhs.datum;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator+=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator+=(const Inch & rhs)
{
    this->datum += static_cast<Foot>(rhs).datum;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator-=(const Units::Distance::Foot & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator-=(const Units::Distance::Inch & rhs)
{
    this->datum -= static_cast<Foot>(rhs).datum;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator-=(const long double rhs)
{
    this->datum -= rhs;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

Units::Distance::Foot& Units::Distance::Foot::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

bool Units::Distance::Foot::operator==(const Units::Distance::Foot & rhs) const
{
    return this->datum == rhs.datum;
}

bool Units::Distance::Foot::operator==(const long double rhs) const
{
    return this->datum == rhs;
}

bool Units::Distance::Foot::operator!=(const Units::Distance::Foot & rhs) const
{
    return !(*this == rhs);
}

bool Units::Distance::Foot::operator!=(const long double rhs) const
{
    return this->datum != rhs;
}

bool Units::Distance::Foot::operator<=(const Units::Distance::Foot & rhs) const
{
    return this->datum <= rhs.datum;
}

bool Units::Distance::Foot::operator<=(const long double rhs) const
{
    return this->datum <= rhs;
}

bool Units::Distance::Foot::operator>=(const Units::Distance::Foot & rhs) const
{
    return this->datum >= rhs.datum;
}

bool Units::Distance::Foot::operator>=(const long double rhs) const
{
    return this->datum >= rhs;
}

bool Units::Distance::Foot::operator>(const Units::Distance::Foot & rhs) const
{
    return this->datum > rhs.datum;
}

bool Units::Distance::Foot::operator>(const long double rhs) const
{
    return this->datum > rhs;
}

bool Units::Distance::Foot::operator<(const Units::Distance::Foot & rhs) const
{
    return this->datum < rhs.datum;
}

bool Units::Distance::Foot::operator<(const long double rhs) const
{
    return this->datum < rhs;
}

Units::Distance::Foot Units::Distance::Foot::operator++()
{
    this->datum++;
    return *this;
}

Units::Distance::Foot Units::Distance::Foot::operator++(int)
{
    Foot temp = *this;
    this->datum++;
    return temp;
}

Units::Distance::Foot Units::Distance::Foot::operator--()
{
    this->datum--;
    return *this;
}

Units::Distance::Foot Units::Distance::Foot::operator--(int)
{
    Foot temp = *this;
    this->datum--;
    return temp;
}

Units::Distance::Foot Units::Distance::Literals::operator""_ft(long double datum)
{
    return Foot(datum);
}

Units::Distance::Foot Units::Distance::Literals::operator""_ft(unsigned long long datum)
{
    return Foot(datum);
}

Units::Distance::Foot Units::Distance::operator+(Units::Distance::Foot lhs, const Units::Distance::Foot rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator+(Units::Distance::Foot lhs, const long double rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator+(const long double lhs, Units::Distance::Foot rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Foot Units::Distance::operator+(Units::Distance::Foot lhs, const Units::Distance::Inch& rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator+(const Units::Distance::Inch& lhs, Units::Distance::Foot rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Foot Units::Distance::operator-(Units::Distance::Foot lhs, const Units::Distance::Foot rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator-(Units::Distance::Foot lhs, const Units::Distance::Inch& rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator-(Units::Distance::Foot lhs, const long double rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator-(const long double lhs, const Units::Distance::Foot& rhs)
{
    return Foot(lhs - rhs.datum);
}

Units::Distance::Foot Units::Distance::operator*(Units::Distance::Foot lhs, const long double rhs)
{
    lhs *= rhs;
    return lhs;
}

Units::Distance::Foot Units::Distance::operator*(const long double lhs, Units::Distance::Foot rhs)
{
    return rhs * lhs;
}

Units::Distance::Foot Units::Distance::operator/(Units::Distance::Foot lhs, const long double rhs)
{
    lhs /= rhs;
    return lhs;
}

long double Units::Distance::operator/(const Units::Distance::Foot & lhs, const Units::Distance::Foot & rhs)
{
    return lhs.datum / rhs.datum;
}

bool Units::Distance::operator<=(const long double lhs, const Units::Distance::Foot & rhs)
{
    return rhs >= lhs;
}

bool Units::Distance::operator>=(const long double lhs, const Units::Distance::Foot & rhs)
{
    return rhs <= lhs;
}

bool Units::Distance::operator<(const long double lhs, const Units::Distance::Foot & rhs)
{
    return rhs > lhs;
}

bool Units::Distance::operator>(const long double lhs, const Units::Distance::Foot & rhs)
{
    return rhs < lhs;
}

std::ostream & Units::Distance::operator<<(std::ostream & os, const Units::Distance::Foot & self)
{
    os << self.datum << " ft";
    return os;
}
