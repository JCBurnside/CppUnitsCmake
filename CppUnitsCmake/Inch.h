#pragma once
#include <iosfwd>
#include "UnitException.h"
namespace Units::Distance {
    //TODO: converting ctor inch

    class Foot;
    class Meter;
    class Millimeter;
    class Kilometer;
    class Inch
    {
        friend class Foot;
        friend class Meter;
        friend class Millimeter;
        friend class Kilometer;
    private:
        long double datum;
    public:
        Inch();
        Inch(Inch& other) = default;
        Inch(Inch&& other) = default;
        explicit Inch(long double datum);
        explicit Inch(unsigned long long datum);
        explicit Inch(long long datum);
        explicit Inch(const Foot& feet);
        explicit Inch(const Meter& meters);
        explicit Inch(const Millimeter& millimeters);
        ~Inch();

        //operators
        Inch operator-() const;
        Inch& operator=(const Inch& other) = default;
        Inch& operator=(Inch&& other) = default;
        Inch& operator=(const long double rhs);
        Inch& operator+=(const Inch& rhs);
        Inch& operator+=(const long double rhs);
        Inch& operator-=(const Inch& rhs);
        Inch& operator-=(const long double rhs);
        Inch& operator*=(const long double rhs);
        Inch& operator/=(const long double rhs);
        bool operator==(const Inch& rhs) const;
        bool operator==(const long double rhs) const;
        bool operator!=(const Inch& rhs) const;
        bool operator!=(const long double rhs) const;
        bool operator<=(const Inch& rhs) const;
        bool operator<=(const long double rhs) const;
        bool operator>=(const Inch& rhs) const;
        bool operator>=(const long double rhs) const;
        bool operator>(const Inch& rhs) const;
        bool operator>(const long double rhs) const;
        bool operator<(const Inch& rhs) const;
        bool operator<(const long double rhs) const;
        Inch operator++();
        Inch operator++(int);
        Inch operator--();
        Inch operator--(int);
        long double RemoveUnits() const;

        //friend operaotrs
        friend Inch operator+(Inch lhs, const Inch rhs);
        friend Inch operator+(Inch lhs, const long double rhs);
        friend Inch operator+(const long double lhs, Inch rhs);
        friend Inch operator-(Inch lhs, const Inch rhs);
        friend Inch operator-(Inch lhs, const long double rhs);
        friend Inch operator-(const long double lhs, Inch rhs);
        friend Inch operator*(Inch lhs, const long double rhs);
        friend Inch operator*(const long double lhs, Inch rhs);
        friend Inch operator/(Inch lhs, const long double rhs);
        friend long double operator/(const Inch& lhs, const Inch& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Inch& self);
    };

    namespace Literals {
        Inch operator "" _in(long double);

        Inch operator "" _in(unsigned long long);
    }
    
    Inch operator+(Inch lhs, const Inch rhs);
    Inch operator+(Inch lhs, const long double rhs);
    Inch operator+(const long double lhs, Inch rhs);
    Inch operator-(Inch lhs, const Inch rhs);
    Inch operator-(Inch lhs, const long double rhs);
    Inch operator-(const long double lhs, Inch rhs);
    Inch operator*(Inch lhs, const long double rhs);
    Inch operator*(const long double lhs, Inch rhs);
    Inch operator/(Inch lhs, const long double rhs);
    long double operator/(const Inch& lhs, const Inch& rhs);
    bool operator==(const long double lhs, const Inch& rhs);
    bool operator!=(const long double lhs, const Inch& rhs);
    bool operator<=(const long double lhs, const Inch& rhs);
    bool operator>=(const long double lhs, const Inch& rhs);
    bool operator<(const long double lhs, const Inch& rhs);
    bool operator>(const long double lhs, const Inch& rhs);
    std::ostream& operator<<(std::ostream& os, const Inch& self);
}