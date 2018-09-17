#pragma once
#include <iosfwd>
#include "UnitException.h"

namespace Units
{
    namespace Complex
    {
        template<typename Unit, int POWER>
        class PoweredUnit;
    }
    namespace Distance
    {
        class Inch;
        class Foot;
        class Meter;
        class Millimeter;
        class Kilometer
        {
            friend class Inch;
            friend class Foot;
            friend class Meter;
            friend class Millimeter;
        private:
            long double datum;
        public:
            Kilometer();
            Kilometer(const Kilometer& other) = default;
            Kilometer(Kilometer&& other) = default;
            explicit Kilometer(long double datum);
            explicit Kilometer(unsigned long long datum);
            explicit Kilometer(long long datum);
            explicit Kilometer(const Inch& inches);
            explicit Kilometer(const Foot& feet);
            explicit Kilometer(const Meter& meters);
            explicit Kilometer(const Millimeter& millimeter);
            ~Kilometer();

            long double RemoveUnits();

            //operators
            Kilometer operator-() const;
            Kilometer& operator=(const Kilometer& other) = default;
            Kilometer& operator=(Kilometer&& other) = default;
            Kilometer& operator=(const long double rhs);
            Kilometer& operator+=(const  Kilometer& rhs);
            Kilometer& operator+=(const long double rhs);
            Kilometer& operator-=(const Kilometer& rhs);
            Kilometer& operator-=(const long double rhs);
            Kilometer& operator*=(const long double rhs);
            Kilometer& operator/=(const long double rhs);
            bool operator==(const Kilometer& rhs) const;
            bool operator==(const long double rhs) const;
            bool operator!=(const Kilometer& rhs) const;
            bool operator!=(const long double rhs) const;
            bool operator<=(const Kilometer& rhs) const;
            bool operator<=(const long double rhs) const;
            bool operator>=(const Kilometer& rhs) const;
            bool operator>=(const long double rhs) const;
            bool operator>(const Kilometer& rhs) const;
            bool operator>(const long double rhs) const;
            bool operator<(const Kilometer& rhs) const;
            bool operator<(const long double rhs) const;
            Kilometer operator++();
            Kilometer operator++(int);
            Kilometer operator--();
            Kilometer operator--(int);

            //friend operaotrs
            friend Kilometer operator+(Kilometer, const Kilometer&);
            friend Kilometer operator+(Kilometer, const long double);
            friend Kilometer operator+(const long double, Kilometer);
            friend Kilometer operator-(Kilometer, const Kilometer&);
            friend Kilometer operator-(Kilometer, const long double);
            friend Kilometer operator-(const long double, const Kilometer&);
            friend Kilometer operator*(Kilometer, const long double);
            friend Kilometer operator*(const long double, Kilometer);
            friend Kilometer operator/(Kilometer lhs, const long double rhs);
            friend long double operator/(const Kilometer&, const Kilometer&);
            friend std::ostream& operator<<(std::ostream&, const Kilometer&);
        };

        namespace Literals
        {
            Kilometer operator "" _km(long double datum);
            Kilometer operator "" _km(unsigned long long datum);
        }

        Kilometer operator+(Kilometer lhs, const Kilometer& rhs);
        Kilometer operator+(Kilometer lhs, const long double rhs);
        Kilometer operator+(const long double lhs, Kilometer rhs);
        Kilometer operator-(Kilometer lhs, const Kilometer& rhs);
        Kilometer operator-(Kilometer lhs, const long double rhs);
        Kilometer operator-(const long double lhs, const Kilometer& rhs);
        Kilometer operator*(Kilometer lhs, const long double rhs);
        Kilometer operator*(const long double lhs, Kilometer rhs);
        Kilometer operator/(Kilometer lhs, const long double rhs);
        long double operator/(const Kilometer& lhs, const Kilometer& rhs);
        bool operator!=(const long double lhs, const Kilometer& rhs);
        bool operator==(const long double lhs, const Kilometer& rhs);
        bool operator<=(const long double lhs, const Kilometer& rhs);
        bool operator>=(const long double lhs, const Kilometer& rhs);
        bool operator<(const long double lhs, const Kilometer& rhs);
        bool operator>(const long double lhs, const Kilometer& rhs);
        std::ostream& operator<<(std::ostream& os, const Kilometer& self);
    }
}

