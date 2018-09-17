#pragma once
#include <iosfwd>
#include "UnitException.h"
namespace Units::Distance {
    //TODO: converting ctor Foot
    class Inch;
    class Meter;
    class Millimeter;
    class Kilometer;
    class Foot
    {
        friend class Inch;
        friend class Meter;
        friend class Millimeter;
        friend class Kilometer;
    private:
        long double datum;
    public:
        Foot();
        explicit Foot(long double datum);
        explicit Foot(const Inch& inches);
        explicit Foot(const Meter& meters);
        explicit Foot(const Millimeter& millimeters);
        explicit Foot(long long datum, const Inch& inches);
        explicit Foot(long long datum);
        explicit Foot(unsigned long long datum);
        Foot(const Foot& other) = default;
        Foot(Foot&& other) = default;
        ~Foot();

        long double RemoveUnits();

        //operators
        Foot operator-() const;
        Foot& operator=(const Foot& other) = default;
        Foot& operator=(Foot&& other) = default;
        Foot& operator=(const long double rhs);
        Foot& operator+=(const  Foot& rhs);
        Foot& operator+=(const long double rhs);
        Foot& operator+=(const Inch& rhs);
        Foot& operator-=(const Foot& rhs);
        Foot& operator-=(const Inch& rhs);
        Foot& operator-=(const long double rhs);
        Foot& operator*=(const long double rhs);
        Foot& operator/=(const long double rhs);
        bool operator==(const Foot& rhs) const;
        bool operator==(const long double rhs) const;
        bool operator!=(const Foot& rhs) const;
        bool operator!=(const long double rhs) const;
        bool operator<=(const Foot& rhs) const;
        bool operator<=(const long double rhs) const;
        bool operator>=(const Foot& rhs) const;
        bool operator>=(const long double rhs) const;
        bool operator>(const Foot& rhs) const;
        bool operator>(const long double rhs) const;
        bool operator<(const Foot& rhs) const;
        bool operator<(const long double rhs) const;
        Foot operator++();
        Foot operator++(int);
        Foot operator--();
        Foot operator--(int);

        //friend operaotrs
        friend Foot operator+(Foot lhs, const Foot rhs);
        friend Foot operator+(Foot lhs, const long double rhs);
        friend Foot operator+(const long double lhs, Foot rhs);
        friend Foot operator+(Foot lhs, const Inch& rhs);
        friend Foot operator+(const Inch& lhs, Foot rhs);
        friend Foot operator-(Foot lhs, const Foot rhs);
        friend Foot operator-(Foot lhs, const Inch& rhs);
        friend Foot operator-(Foot lhs, const long double rhs);
        friend Foot operator-(const long double lhs,const Foot& rhs);
        friend Foot operator*(Foot lhs, const long double rhs);
        friend Foot operator*(const long double lhs, Foot rhs);
        friend Foot operator/(Foot lhs, const long double rhs);
        friend long double operator/(const Foot&,const Foot&);
        friend std::ostream& operator<<(std::ostream& os, const Foot& self);
    };

    namespace Literals {
        //internal
        Foot operator "" _ft(long double datum);

        Foot operator "" _ft(unsigned long long datum);
    }

    Foot operator+(Foot lhs, const Foot rhs);
    Foot operator+(Foot lhs, const long double rhs);
    Foot operator+(const long double lhs, Foot rhs);
    Foot operator+(Foot lhs, const Inch& rhs);
    Foot operator+(const Inch& lhs, Foot rhs);
    Foot operator-(Foot lhs, const Foot rhs);
    Foot operator-(Foot lhs, const Inch& rhs);
    Foot operator-(Foot lhs, const long double rhs);
    Foot operator-(const long double lhs,const Foot& rhs);
    Foot operator*(Foot lhs, const long double rhs);
    Foot operator*(const long double lhs, Foot rhs);
    Foot operator/(Foot lhs, const long double rhs);
    long double operator/(const Foot& lhs, const Foot& rhs);
    bool operator==(const long double lhs, const Foot& rhs);
    bool operator!=(const long double lhs, const Foot& rhs);
    bool operator<=(const long double lhs, const Foot& rhs);
    bool operator>=(const long double lhs, const Foot& rhs);
    bool operator<(const long double lhs, const Foot& rhs);
    bool operator>(const long double lhs, const Foot& rhs);
    std::ostream& operator<<(std::ostream& os, const Foot& self);
}