#pragma once
#include "UnitException.h"
#include <iosfwd>
namespace Units::Distance {
    //TODO: converting ctor Meter
    class Inch;
    class Foot;
    class Millimeter;
    class Kilometer;
    class Meter
    {
        friend class Inch;
        friend class Foot;
        friend class Millimeter;
        friend class Kilometer;
    private:
        long double datum;
    public:
        Meter();
        Meter(const Meter&) = default;
        Meter(Meter&&) = default;
        Meter(const Millimeter& millimeters);
        explicit Meter(long double datum);
        explicit Meter(unsigned long long datum);
        explicit Meter(long long datum);
        explicit Meter(const Inch& inches);
        explicit Meter(const Foot& feet);
        explicit Meter(const Kilometer& kilos);
        ~Meter();

        long double RemoveUnits() const;

        //operators
        Meter operator-() const;
        Meter& operator=(const Meter& other) = default;
        Meter& operator=(Meter&& other) = default;
        Meter& operator=(const long double rhs);
        Meter& operator+=(const Meter& rhs);
        Meter& operator+=(const Millimeter& rhs);
        Meter& operator+=(const long double rhs);
        Meter& operator-=(const Meter& rhs);
        Meter& operator-=(const Millimeter& rhs);
        Meter& operator-=(const long double rhs);
        Meter& operator*=(const long double rhs);
        Meter& operator/=(const long double rhs);
        bool operator==(const Meter& rhs) const;
        bool operator==(const long double rhs) const;
        bool operator!=(const Meter& rhs) const;
        bool operator!=(const long double rhs) const;
        bool operator<=(const Meter& rhs) const;
        bool operator<=(const long double rhs) const;
        bool operator>=(const Meter& rhs) const;
        bool operator>=(const long double rhs) const;
        bool operator>(const Meter& rhs) const;
        bool operator>(const long double rhs) const;
        bool operator<(const Meter& rhs) const;
        bool operator<(const long double rhs) const;
        Meter operator++();
        Meter operator++(int);
        Meter operator--();
        Meter operator--(int);

        //friend operaotrs
        friend Meter operator+(Meter lhs, const Meter rhs);
        friend Meter operator+(Meter lhs, const long double rhs);
        friend Meter operator+(const long double lhs, Meter rhs);
        friend Meter operator+(Meter lhs, const Millimeter& rhs);
        friend Meter operator+(const Millimeter& lhs, Meter rhs);
        friend Meter operator-(Meter lhs, const Meter rhs);
        friend Meter operator-(Meter lhs, const Millimeter& rhs);
        friend Meter operator-(Meter lhs, const long double rhs);
        friend Meter operator-(const long double lhs, const Meter& rhs);
        friend Meter operator*(Meter lhs, const long double rhs);
        friend Meter operator*(const long double lhs, Meter rhs);
        friend Meter operator/(Meter lhs, const long double rhs);
        friend long double operator/(const Meter&,const Meter&);
        friend std::ostream& operator<<(std::ostream& os, const Meter& self);
    };

    namespace Literals {
        Meter operator "" _m(long double);

        Meter operator "" _m(unsigned long long datum);
    }

    Meter operator+(Meter lhs, const Meter rhs);
    Meter operator+(Meter lhs, const long double rhs);
    Meter operator+(const long double lhs, Meter rhs);
    Meter operator+(Meter lhs, const Millimeter& rhs);
    Meter operator+(const Millimeter& lhs, Meter rhs);
    Meter operator-(Meter lhs, const Meter rhs);
    Meter operator-(Meter lhs, const Millimeter& rhs);
    Meter operator-(Meter lhs, const long double rhs);
    Meter operator-(const long double lhs, const Meter& rhs);
    Meter operator*(Meter lhs, const long double rhs);
    Meter operator*(const long double lhs, Meter rhs);
    Meter operator/(Meter lhs, const long double rhs);
    long double operator/(const Meter& lhs, const Meter& rhs);
    bool operator==(const long double lhs, const Meter& rhs);
    bool operator!=(const long double lhs, const Meter& rhs);
    bool operator<=(const long double lhs, const Meter& rhs);
    bool operator>=(const long double lhs, const Meter& rhs);
    bool operator<(const long double lhs, const Meter& rhs);
    bool operator>(const long double lhs, const Meter& rhs);
    std::ostream& operator<<(std::ostream& os, const Meter& self);
    std::istream& operator>>(std::istream& is, Meter& self);
}