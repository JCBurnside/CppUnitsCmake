#pragma once
#include <iosfwd>
#include "UnitException.h"

namespace Units::Distance {
    class Inch;
    class Foot;
    class Meter;
    class Kilometer;
    class Millimeter
    {
        friend class Meter;
        friend class Inch;
        friend class Foot;
        friend class Kilometer;
    private:
        long double datum;
    public:
        Millimeter();
        Millimeter(const Millimeter& other) = default;
        Millimeter(Millimeter&& other) = default;
        Millimeter(const Meter& meters);
        explicit Millimeter(long double datum);
        explicit Millimeter(unsigned long long datum);
        explicit Millimeter(long long datum);
        explicit Millimeter(const Inch& inches);
        explicit Millimeter(const Foot& feet);
        ~Millimeter();

        long double RemoveUnits();

        //operators
        Millimeter operator-() const;
        Millimeter& operator=(const Millimeter& other) = default;
        Millimeter& operator=(Millimeter&& other) = default;
        Millimeter& operator=(const long double rhs);
        Millimeter& operator+=(const  Millimeter& rhs);
        Millimeter& operator+=(const long double rhs);
        Millimeter& operator-=(const Millimeter& rhs);
        Millimeter& operator-=(const long double rhs);
        Millimeter& operator*=(const long double rhs);
        Millimeter& operator/=(const long double rhs);
        bool operator==(const Millimeter& rhs) const;
        bool operator==(const long double rhs) const;
        bool operator!=(const Millimeter& rhs) const;
        bool operator!=(const long double rhs) const;
        bool operator<=(const Millimeter& rhs) const;
        bool operator<=(const long double rhs) const;
        bool operator>=(const Millimeter& rhs) const;
        bool operator>=(const long double rhs) const;
        bool operator>(const Millimeter& rhs) const;
        bool operator>(const long double rhs) const;
        bool operator<(const Millimeter& rhs) const;
        bool operator<(const long double rhs) const;
        Millimeter operator++();
        Millimeter operator++(int);
        Millimeter operator--();
        Millimeter operator--(int);
        

        //friend operaotrs
        friend Millimeter operator+(Millimeter, const Millimeter&);
        friend Millimeter operator+(Millimeter, const long double);
        friend Millimeter operator+(const long double, Millimeter);
        friend Millimeter operator-(Millimeter, const Millimeter&);
        friend Millimeter operator-(Millimeter, const long double);
        friend Millimeter operator-(const long double,const Millimeter&);
        friend Millimeter operator*(Millimeter, const long double);
        friend Millimeter operator*(const long double, Millimeter);
        friend Millimeter operator/(Millimeter lhs, const long double rhs);
        friend long double operator/(const Millimeter&, const Millimeter&);
        friend std::ostream& operator<<(std::ostream&, const Millimeter&);
    };
    
    namespace Literals 
    {
        Millimeter operator""_mm(long double datum);
        Millimeter operator""_mm(unsigned long long datum);
    }
    
    Millimeter operator+(Millimeter lhs, const Millimeter& rhs);
    Millimeter operator+(Millimeter lhs, const long double rhs);
    Millimeter operator+(const long double lhs, Millimeter rhs);
    Millimeter operator-(Millimeter lhs, const Millimeter& rhs);
    Millimeter operator-(Millimeter lhs, const long double rhs);
    Millimeter operator-(const long double lhs, const Millimeter& rhs);
    Millimeter operator*(Millimeter lhs, const long double rhs);
    Millimeter operator*(const long double lhs, Millimeter rhs);
    Millimeter operator/(Millimeter lhs, const long double rhs);
    long double operator/(const Millimeter& lhs, const Millimeter& rhs);
    bool operator!=(const long double lhs, const Millimeter& rhs);
    bool operator==(const long double lhs, const Millimeter& rhs);
    bool operator<=(const long double lhs, const Millimeter& rhs);
    bool operator>=(const long double lhs, const Millimeter& rhs);
    bool operator<(const long double lhs, const Millimeter& rhs);
    bool operator>(const long double lhs, const Millimeter& rhs);
    std::ostream& operator<<(std::ostream& os, const Millimeter& self);
}

