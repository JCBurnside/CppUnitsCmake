#include "Millimeter.h"
#include "Inch.h"
#include "Foot.h"
#include "Meter.h"
#include <utility>
#include <ostream>

Units::Distance::Millimeter::Millimeter()
    :datum(0)
{
}

Units::Distance::Millimeter::Millimeter(long double datum)
    : datum(datum)
{
}

Units::Distance::Millimeter::Millimeter(unsigned long long datum)
    : datum(datum)
{
}

Units::Distance::Millimeter::Millimeter(long long datum)
    : datum(datum)
{
}

Units::Distance::Millimeter::Millimeter(const Units::Distance::Inch & inches)
    : datum(inches.datum * 0.0254L)
{
}


Units::Distance::Millimeter::Millimeter(const Units::Distance::Foot & feet)
    : datum(feet.datum * .3048L)
{
}

Units::Distance::Millimeter::Millimeter(const Meter & meters)
    : datum(0)
{
    if (meters.datum > std::numeric_limits<long double>::max() / 1000 || meters.datum < std::numeric_limits<long double>::min() / 1000)
    {
        throw UnitException(typeid(Meter).name(), meters.datum, typeid(Millimeter).name());
    }
    this->datum = meters.datum * 1000;
}

Units::Distance::Millimeter::~Millimeter()
{
}

long double Units::Distance::Millimeter::RemoveUnits()
{
    return this->datum;
}

Units::Distance::Millimeter Units::Distance::Millimeter::operator-() const
{
    return Millimeter(this->datum * -1);
}

Units::Distance::Millimeter& Units::Distance::Millimeter::operator=(const long double rhs)
{
    this->datum = rhs;
    return *this;
}

Units::Distance::Millimeter & Units::Distance::Millimeter::operator+=(const Millimeter & rhs)
{
    this->datum += rhs.datum;
    return *this;
}

Units::Distance::Millimeter & Units::Distance::Millimeter::operator+=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

Units::Distance::Millimeter & Units::Distance::Millimeter::operator-=(const Millimeter & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

Units::Distance::Millimeter & Units::Distance::Millimeter::operator-=(const long double rhs)
{
    this->datum -= rhs;
    return *this;
}

Units::Distance::Millimeter & Units::Distance::Millimeter::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

Units::Distance::Millimeter & Units::Distance::Millimeter::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

bool Units::Distance::Millimeter::operator==(const Millimeter & rhs) const
{
    return this->datum == rhs.datum;
}

bool Units::Distance::Millimeter::operator==(const long double rhs) const
{
    return this->datum == rhs;
}

bool Units::Distance::Millimeter::operator!=(const Millimeter & rhs) const
{
    return this->datum != rhs.datum;
}

bool Units::Distance::Millimeter::operator!=(const long double rhs) const
{
    return this->datum != rhs;
}

bool Units::Distance::Millimeter::operator<=(const Millimeter & rhs) const
{
    return this->datum <= rhs.datum;
}

bool Units::Distance::Millimeter::operator<=(const long double rhs) const
{
    return this->datum <= rhs;
}

bool Units::Distance::Millimeter::operator>=(const Millimeter & rhs) const
{
    return this->datum >= rhs.datum;
}

bool Units::Distance::Millimeter::operator>=(const long double rhs) const
{
    return this->datum >= rhs;
}

bool Units::Distance::Millimeter::operator>(const Millimeter & rhs) const
{
    return this->datum > rhs.datum;
}

bool Units::Distance::Millimeter::operator>(const long double rhs) const
{
    return this->datum > rhs;
}

bool Units::Distance::Millimeter::operator<(const Millimeter & rhs) const
{
    return this->datum < rhs.datum;
}

bool Units::Distance::Millimeter::operator<(const long double rhs) const
{
    return this->datum < rhs;
}

Units::Distance::Millimeter Units::Distance::Millimeter::operator++()
{
    this->datum++;
    return *this;
}

Units::Distance::Millimeter Units::Distance::Millimeter::operator++(int)
{
    Millimeter temp = *this;
    this->datum++;
    return temp;
}

Units::Distance::Millimeter Units::Distance::Millimeter::operator--()
{
    this->datum--;
    return *this;
}

Units::Distance::Millimeter Units::Distance::Millimeter::operator--(int)
{
    Millimeter temp = *this;
    this->datum--;
    return temp;
}


Units::Distance::Millimeter Units::Distance::Literals::operator""_mm(long double datum)
{
    return Millimeter(datum);
}

Units::Distance::Millimeter Units::Distance::Literals::operator""_mm(unsigned long long datum)
{
    return Millimeter(datum);
}

Units::Distance::Millimeter Units::Distance::operator+(Millimeter lhs, const Millimeter & rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Millimeter Units::Distance::operator+(Millimeter lhs, const long double rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Millimeter Units::Distance::operator+(const long double lhs, Millimeter rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Millimeter Units::Distance::operator-(Millimeter lhs, const Millimeter& rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Millimeter Units::Distance::operator-(Millimeter lhs, const long double rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Millimeter Units::Distance::operator-(const long double lhs, const Millimeter & rhs)
{
    return Millimeter(lhs - rhs.datum);
}

Units::Distance::Millimeter Units::Distance::operator*(Millimeter lhs, const long double rhs)
{
    lhs *= rhs;
    return lhs;
}

Units::Distance::Millimeter Units::Distance::operator*(const long double lhs, Millimeter rhs)
{
    rhs *= lhs;
    return rhs;
}

Units::Distance::Millimeter Units::Distance::operator/(Millimeter lhs, const long double rhs)
{
    lhs /= rhs;
    return lhs;
}

long double Units::Distance::operator/(const Millimeter & lhs, const Millimeter & rhs)
{
    return lhs.datum / rhs.datum;
}

bool Units::Distance::operator!=(const long double lhs, const Millimeter & rhs)
{
    return rhs != lhs;
}

bool Units::Distance::operator==(const long double lhs, const Millimeter & rhs)
{
    return rhs == lhs;
}

bool Units::Distance::operator<=(const long double lhs, const Millimeter & rhs)
{
    return rhs >= lhs;
}

bool Units::Distance::operator>=(const long double lhs, const Millimeter & rhs)
{
    return rhs <= lhs;
}

bool Units::Distance::operator<(const long double lhs, const Millimeter & rhs)
{
    return rhs > lhs;
}

bool Units::Distance::operator>(const long double lhs, const Millimeter & rhs)
{
    return rhs < lhs;
}

std::ostream & Units::Distance::operator<<(std::ostream & os, const Millimeter & self)
{
    os << self.datum << " mm";
    return os;
}
