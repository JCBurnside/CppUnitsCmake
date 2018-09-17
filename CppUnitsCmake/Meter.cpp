#include "Meter.h"
#include "Distance.h"
#include <iostream>

Units::Distance::Meter::Meter()
{}

Units::Distance::Meter::Meter(long double datum)
    :datum(datum)
{}

#pragma warning (push)
#pragma warning (disable:4244)
Units::Distance::Meter::Meter(unsigned long long datum)
    : datum(datum)
{}
Units::Distance::Meter::Meter(long long datum)
    : datum(datum)
{}
#pragma warning (pop)

Units::Distance::Meter::Meter(const Units::Distance::Millimeter & millimeters)
    : datum(millimeters.datum / 1000.0L)
{}

Units::Distance::Meter::Meter(const Units::Distance::Inch & inches)
    : datum(inches.datum*.0254L)
{}

Units::Distance::Meter::Meter(const Units::Distance::Foot & feet)
    : datum(feet.datum*.3048L)
{}

Units::Distance::Meter::Meter(const Kilometer & kilos)
    : datum(0)
{
    if (kilos.datum > std::numeric_limits<long double>::max() / 1000 || kilos.datum < std::numeric_limits<long double>::min() / 1000)
    {
        throw UnitException(typeid(Kilometer).name(), kilos.datum, typeid(Meter).name());
    }
    datum = kilos.datum * 1000;
}

Units::Distance::Meter::~Meter()
{}

const std::string Units::Distance::Meter::DisplayUnits()
{
    return "m";
}

long double Units::Distance::Meter::RemoveUnits() const
{
    return this->datum;
}

Units::Distance::Meter Units::Distance::Meter::operator-() const
{
    return Meter(this->datum*-1);
}

Units::Distance::Meter & Units::Distance::Meter::operator=(const long double rhs)
{
    this->datum = rhs;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator+=(const Units::Distance::Meter & rhs)
{
    this->datum += rhs.datum;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator+=(const Units::Distance::Millimeter & rhs)
{
    this->datum += rhs.datum / 1000.0L;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator+=(const long double rhs)
{
    this->datum += rhs;

    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator-=(const Units::Distance::Meter & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator-=(const Units::Distance::Millimeter & rhs)
{
    this->datum -= rhs.datum / 1000.0L;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator-=(const long double rhs)
{
    this->datum -= rhs;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

Units::Distance::Meter & Units::Distance::Meter::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

bool Units::Distance::Meter::operator==(const Units::Distance::Meter & rhs) const
{
    return this->datum == rhs.datum;
}

bool Units::Distance::Meter::operator==(const long double rhs) const
{
    return this->datum == rhs;
}

bool Units::Distance::Meter::operator!=(const Units::Distance::Meter & rhs) const
{
    return this->datum != rhs.datum;
}

bool Units::Distance::Meter::operator!=(const long double rhs) const
{
    return this->datum != rhs;
}

bool Units::Distance::Meter::operator<=(const Units::Distance::Meter & rhs) const
{
    return this->datum <= rhs.datum;
}

bool Units::Distance::Meter::operator<=(const long double rhs) const
{
    return this->datum <= rhs;
}

bool Units::Distance::Meter::operator>=(const Units::Distance::Meter & rhs) const
{
    return this->datum >= rhs.datum;
}

bool Units::Distance::Meter::operator>=(const long double rhs) const
{
    return this->datum >= rhs;
}

bool Units::Distance::Meter::operator>(const Units::Distance::Meter & rhs) const
{
    return this->datum > rhs.datum;
}

bool Units::Distance::Meter::operator>(const long double rhs) const
{
    return this->datum > rhs;
}

bool Units::Distance::Meter::operator<(const Units::Distance::Meter & rhs) const
{
    return this->datum < rhs.datum;
}

bool Units::Distance::Meter::operator<(const long double rhs) const
{
    return this->datum < rhs;
}

Units::Distance::Meter Units::Distance::Meter::operator++()
{
    this->datum++;
    return *this;
}

Units::Distance::Meter Units::Distance::Meter::operator++(int)
{
    Meter temp = *this;
    this->datum++;
    return temp;
}

Units::Distance::Meter Units::Distance::Meter::operator--()
{
    this->datum--;
    return *this;
}

Units::Distance::Meter Units::Distance::Meter::operator--(int)
{
    Meter temp = *this;
    this->datum--;
    return temp;
}

Units::Distance::Meter Units::Distance::Literals::operator""_m(long double datum)
{
    return Meter(datum);
}

Units::Distance::Meter Units::Distance::Literals::operator""_m(unsigned long long datum)
{
    return Meter(datum);
}

Units::Distance::Meter Units::Distance::operator+(Units::Distance::Meter lhs, const Units::Distance::Meter rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator+(Units::Distance::Meter lhs, const long double rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator+(const long double lhs, Meter rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Meter Units::Distance::operator+(Units::Distance::Meter lhs, const Units::Distance::Millimeter & rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator+(const Units::Distance::Millimeter & lhs, Units::Distance::Meter rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Meter Units::Distance::operator-(Units::Distance::Meter lhs, const Units::Distance::Meter rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator-(Units::Distance::Meter lhs, const Units::Distance::Millimeter & rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator-(Units::Distance::Meter lhs, const long double rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator-(const long double lhs, const Units::Distance::Meter & rhs)
{
    return Meter(lhs - rhs.datum);
}

Units::Distance::Meter Units::Distance::operator*(Units::Distance::Meter lhs, const long double rhs)
{
    lhs *= rhs;
    return lhs;
}

Units::Distance::Meter Units::Distance::operator*(const long double lhs, Units::Distance::Meter rhs)
{
    rhs *= lhs;
    return rhs;
}

Units::Distance::Meter Units::Distance::operator/(Units::Distance::Meter lhs, const long double rhs)
{
    lhs /= rhs;
    return lhs;
}

long double Units::Distance::operator/(const Meter & lhs, const Meter & rhs)
{
    return lhs.datum / rhs.datum;
}

bool Units::Distance::operator==(const long double lhs, const Meter & rhs)
{
    return rhs == lhs;
}

bool Units::Distance::operator!=(const long double lhs, const Meter & rhs)
{
    return rhs != lhs;
}

bool Units::Distance::operator<=(const long double lhs, const Meter & rhs)
{
    return rhs >= lhs;
}

bool Units::Distance::operator>=(const long double lhs, const Meter & rhs)
{
    return rhs <= lhs;
}

bool Units::Distance::operator<(const long double lhs, const Meter & rhs)
{
    return rhs > lhs;
}

bool Units::Distance::operator>(const long double lhs, const Meter & rhs)
{
    return rhs < lhs;
}

std::ostream & Units::Distance::operator<<(std::ostream & os, const Meter & self)
{
    os << self.datum << " m";
    return os;
}

std::istream & Units::Distance::operator>>(std::istream & is, Meter & self)
{
    long double in;
    is>>in;
    self=in;
    return is;
}

