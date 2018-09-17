#include "Inch.h"
#include "Foot.h"
#include "Meter.h"
#include "Millimeter.h"
#include <utility>
#include <limits>
#include <ostream>

Units::Distance::Inch::Inch()
    :datum(0)
{
}

Units::Distance::Inch::Inch(long double datum)
    : datum(datum)
{
}

Units::Distance::Inch::Inch(unsigned long long datum)
    : datum(datum)
{
}

Units::Distance::Inch::Inch(long long datum)
    : datum(datum)
{
}

Units::Distance::Inch::Inch(const Units::Distance::Foot & feet)
    : datum(0)
{
    if(feet.datum>std::numeric_limits<long double>::max()/12) throw UnitException();
    datum=feet.datum*12.0L;
}

Units::Distance::Inch::Inch(const Meter & meters)
    : datum(meters.datum*39.3701L)
{
}

Units::Distance::Inch::Inch(const Millimeter & millimeters)
    :datum(millimeters.datum*.0393701L)
{
}

Units::Distance::Inch::~Inch()
{
}

Units::Distance::Inch Units::Distance::Inch::operator-() const
{
    return Inch(-(this->datum));
}

Units::Distance::Inch& Units::Distance::Inch::operator=(const long double rhs)
{
    this->datum = rhs;
    return *this;
}

Units::Distance::Inch& Units::Distance::Inch::operator+=(const Inch & rhs)
{
    this->datum += rhs.datum;
    return *this;
}

Units::Distance::Inch& Units::Distance::Inch::operator+=(const long double rhs)
{
    this->datum += rhs;
    return *this;
}

Units::Distance::Inch& Units::Distance::Inch::operator-=(const Inch & rhs)
{
    this->datum -= rhs.datum;
    return *this;
}

Units::Distance::Inch& Units::Distance::Inch::operator-=(const long double rhs)
{
    this->datum -= rhs;
    return *this;
}

Units::Distance::Inch& Units::Distance::Inch::operator*=(const long double rhs)
{
    this->datum *= rhs;
    return *this;
}

Units::Distance::Inch& Units::Distance::Inch::operator/=(const long double rhs)
{
    this->datum /= rhs;
    return *this;
}

bool Units::Distance::Inch::operator==(const Inch & rhs) const
{
    return this->datum==rhs.datum;
}

bool Units::Distance::Inch::operator==(const long double rhs) const
{
    return this->datum==rhs;
}

bool Units::Distance::Inch::operator!=(const Inch & rhs) const
{
    return !(*this==rhs);
}

bool Units::Distance::Inch::operator!=(const long double rhs) const
{
    return this->datum!=rhs;
}

bool Units::Distance::Inch::operator<=(const Units::Distance::Inch & rhs) const
{
    return this->datum<=rhs.datum;
}

bool Units::Distance::Inch::operator<=(const long double rhs) const
{
    return this->datum<=rhs;
}

bool Units::Distance::Inch::operator>=(const Units::Distance::Inch & rhs) const
{
    return this->datum>=rhs.datum;
}

bool Units::Distance::Inch::operator>=(const long double rhs) const
{
    return this->datum>=rhs;
}

bool Units::Distance::Inch::operator>(const Units::Distance::Inch & rhs) const
{
    return this->datum>rhs.datum;
}

bool Units::Distance::Inch::operator>(const long double rhs) const
{
    return this->datum>rhs;
}

bool Units::Distance::Inch::operator<(const Units::Distance::Inch & rhs) const
{
    return this->datum<rhs.datum;
}

bool Units::Distance::Inch::operator<(const long double rhs) const
{
    return this->datum<rhs;
}

Units::Distance::Inch Units::Distance::Inch::operator++()
{
    this->datum++;
    return *this;
}

Units::Distance::Inch Units::Distance::Inch::operator++(int)
{
    Inch temp = *this;
    this->datum++;
    return temp;
}

Units::Distance::Inch Units::Distance::Inch::operator--()
{
    this->datum--;
    return *this;
}

Units::Distance::Inch Units::Distance::Inch::operator--(int)
{
    Inch temp = *this;
    this->datum--;
    return temp;
}

long double Units::Distance::Inch::RemoveUnits() const
{
    return this->datum;
}

Units::Distance::Inch Units::Distance::Literals::operator""_in(long double datum)
{
    return Inch(datum);
}

Units::Distance::Inch Units::Distance::Literals::operator""_in(unsigned long long datum)
{
    return Inch(datum);
}

Units::Distance::Inch Units::Distance::operator+(Units::Distance::Inch lhs, const Units::Distance::Inch rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Inch Units::Distance::operator+(Units::Distance::Inch lhs, const long double rhs)
{
    lhs += rhs;
    return lhs;
}

Units::Distance::Inch Units::Distance::operator+(const long double lhs, Units::Distance::Inch rhs)
{
    rhs += lhs;
    return rhs;
}

Units::Distance::Inch Units::Distance::operator-(Units::Distance::Inch lhs, const Units::Distance::Inch rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Inch Units::Distance::operator-(Units::Distance::Inch lhs, const long double rhs)
{
    lhs -= rhs;
    return lhs;
}

Units::Distance::Inch Units::Distance::operator-(const long double lhs, Units::Distance::Inch rhs)
{
    return Units::Distance::Inch(lhs - rhs.datum);
}

Units::Distance::Inch Units::Distance::operator*(Units::Distance::Inch lhs, const long double rhs)
{
    lhs *= rhs;
    return lhs;
}

Units::Distance::Inch Units::Distance::operator*(const long double lhs, Units::Distance::Inch rhs)
{
    rhs *= lhs;
    return rhs;
}

Units::Distance::Inch Units::Distance::operator/(Units::Distance::Inch lhs, const long double rhs)
{
    lhs /= rhs;
    return lhs;
}

long double Units::Distance::operator/(const Units::Distance::Inch & lhs, const Units::Distance::Inch & rhs)
{
    return lhs.datum/rhs.datum;
}

bool Units::Distance::operator==(const long double lhs, const Inch & rhs)
{
    return rhs==lhs;
}

bool Units::Distance::operator!=(const long double lhs, const Inch & rhs)
{
    return rhs!=lhs;
}

bool Units::Distance::operator<=(const long double lhs, const Units::Distance::Inch & rhs)
{
    return rhs>=lhs;
}

bool Units::Distance::operator>=(const long double lhs, const Units::Distance::Inch & rhs)
{
    return rhs<=lhs;
}

bool Units::Distance::operator<(const long double lhs, const Units::Distance::Inch & rhs)
{
    return rhs>lhs;
}

bool Units::Distance::operator>(const long double lhs, const Units::Distance::Inch & rhs)
{
    return rhs<lhs;
}

std::ostream & Units::Distance::operator<<(std::ostream & os, const Units::Distance::Inch & self)
{
    os<<self.datum<<" in";
    return os;
}
