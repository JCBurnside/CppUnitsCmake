#pragma once
#include <iosfwd>
#include <string>
namespace Units::Complex
{
    template<typename Unit, int POWER>
    class PoweredUnit
    {
    private:
        long double datum;
    public:
        static constexpr int Power = POWER;
        PoweredUnit() = delete;
        PoweredUnit(const PoweredUnit&) = default;
        PoweredUnit(PoweredUnit&&) = default;
        explicit PoweredUnit(long double datum);
        explicit PoweredUnit(long long datum);
        explicit PoweredUnit(unsigned long long datum);
        ~PoweredUnit() = default;

        long double RemoveUnits() const;
        static const std::string DisplayUnits();

        PoweredUnit operator-() const;
        PoweredUnit& operator=(const PoweredUnit&) = default;
        PoweredUnit& operator=(PoweredUnit&&) = default;
        PoweredUnit& operator+=(const PoweredUnit& rhs);
        PoweredUnit& operator+=(const long double rhs);
        PoweredUnit& operator-=(const PoweredUnit& rhs);
        PoweredUnit& operator-=(const long double rhs);
        PoweredUnit& operator*=(const long double rhs);
        PoweredUnit& operator/=(const long double rhs);
        PoweredUnit<Unit, POWER - 1> operator/(const Unit& rhs);
        bool operator==(const PoweredUnit& rhs) const;
        bool operator!=(const PoweredUnit& rhs) const;
        bool operator>=(const PoweredUnit& rhs) const;
        bool operator<=(const PoweredUnit& rhs) const;
        bool operator<(const PoweredUnit& rhs) const;
        bool operator>(const PoweredUnit& rhs) const;

        //friend bool operator==(const PoweredUnit&, long double);
        //friend bool operator!=(const PoweredUnit&, long double);
        //friend bool operator>=(const PoweredUnit&, long double);
        //friend bool operator<=(const PoweredUnit&, long double);
        //friend bool operator<(const PoweredUnit&, long double);
        //friend bool operator>(const PoweredUnit&, long double);

        //friend bool operator==(long double, const PoweredUnit&);
        //friend bool operator!=(long double, const PoweredUnit&);
        //friend bool operator>=(long double, const PoweredUnit&);
        //friend bool operator<=(long double, const PoweredUnit&);
        //friend bool operator<(long double, const PoweredUnit&);
        //friend bool operator>(long double, const PoweredUnit&);

        friend Unit operator/(const PoweredUnit&, const PoweredUnit&);

        friend PoweredUnit<Unit, POWER + 1> operator*(const PoweredUnit&, const Unit&);

    };

    template<typename Unit>
    class PoweredUnit<Unit, 2>
    {

    private:
        long double datum;
    public:
        static constexpr int Power = 2;
        PoweredUnit() = delete;
        PoweredUnit(const PoweredUnit&) = default;
        PoweredUnit(PoweredUnit&&) = default;
        explicit PoweredUnit(long double datum);
        explicit PoweredUnit(long long datum);
        explicit PoweredUnit(unsigned long long datum);
        ~PoweredUnit() = default;

        long double RemoveUnits() const;
        static const std::string DisplayUnits();

        PoweredUnit operator-() const;
        PoweredUnit& operator=(const PoweredUnit&) = default;
        PoweredUnit& operator=(PoweredUnit&&) = default;
        PoweredUnit& operator+=(const PoweredUnit& rhs);
        PoweredUnit& operator+=(const long double rhs);
        PoweredUnit& operator-=(const PoweredUnit& rhs);
        PoweredUnit& operator-=(const long double rhs);
        PoweredUnit& operator*=(const long double rhs);
        PoweredUnit& operator/=(const long double rhs);
        Unit operator/(const Unit& rhs);
        bool operator==(const PoweredUnit& rhs) const;
        bool operator!=(const PoweredUnit& rhs) const;
        bool operator>=(const PoweredUnit& rhs) const;
        bool operator<=(const PoweredUnit& rhs) const;
        bool operator<(const PoweredUnit& rhs) const;
        bool operator>(const PoweredUnit& rhs) const;

        //friend bool operator==(const PoweredUnit&, long double);
        //friend bool operator!=(const PoweredUnit&, long double);
        //friend bool operator>=(const PoweredUnit&, long double);
        //friend bool operator<=(const PoweredUnit&, long double);
        //friend bool operator<(const PoweredUnit&, long double);
        //friend bool operator>(const PoweredUnit&, long double);

        //friend bool operator==(long double, const PoweredUnit&);
        //friend bool operator!=(long double, const PoweredUnit&);
        //friend bool operator>=(long double, const PoweredUnit&);
        //friend bool operator<=(long double, const PoweredUnit&);
        //friend bool operator<(long double, const PoweredUnit&);
        //friend bool operator>(long double, const PoweredUnit&);

        friend long double operator/(const PoweredUnit&, const PoweredUnit&);

    };

    template<typename Unit>
    //Use Unit instead
    class PoweredUnit<Unit, 1>
    {
    public:
        //Use the base unit instead
        PoweredUnit() = delete;
        PoweredUnit(const PoweredUnit&) = delete;
        PoweredUnit(PoweredUnit&&) = delete;
    };

    template<typename Unit>
    //Use another type...
    class PoweredUnit<Unit, 0>
    {
    public:
        PoweredUnit() = delete;
        PoweredUnit(const PoweredUnit&) = delete;
        PoweredUnit(PoweredUnit&&) = delete;
    };

    template<typename Unit, int POWER>
    bool operator==(const PoweredUnit<Unit, POWER>& lhs, long double rhs)
    {
        return lhs.RemoveUnits() == rhs;
    }

    template<typename Unit, int POWER>
    bool operator!=(const PoweredUnit<Unit, POWER>& lhs, long double rhs);

    template<typename Unit, int POWER>
    bool operator>=(const PoweredUnit<Unit, POWER>& lhs, long double rhs);

    template<typename Unit, int POWER>
    bool operator<=(const PoweredUnit<Unit, POWER>& lhs, long double rhs);

    template<typename Unit, int POWER>
    bool operator<(const PoweredUnit<Unit, POWER>& lhs, long double rhs);

    template<typename Unit, int POWER>
    bool operator>(const PoweredUnit<Unit, POWER>& lhs, long double rhs);


    template<typename Unit, int POWER>
    bool operator==(long double lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER>
    bool operator!=(long double lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER>
    bool operator>=(long double lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER>
    bool operator<=(long double lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER>
    bool operator<(long double lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER>
    bool operator>(long double lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER_LEFT, int POWER_RIGHT>
    PoweredUnit<Unit, POWER_LEFT - POWER_RIGHT> operator/(const PoweredUnit<Unit, POWER_LEFT>& lhs, const PoweredUnit<Unit, POWER_RIGHT>& rhs);

    template<typename Unit, int POWER>
    long double operator/(const PoweredUnit<Unit, POWER>& lhs, const PoweredUnit<Unit, POWER>& rhs);
    
    template<typename Unit>
    PoweredUnit<Unit, 2> operator*(const Unit& lhs, const Unit& rhs);

    template<typename Unit, int POWER>
    PoweredUnit<Unit, POWER + 1> operator*(const PoweredUnit<Unit, POWER>& lhs, const Unit& rhs);

    template<typename Unit, int POWER_LEFT, int POWER_RIGHT>
    PoweredUnit<Unit, POWER_LEFT + POWER_RIGHT> operator*(const PoweredUnit<Unit, POWER_LEFT>& lhs, const PoweredUnit<Unit, POWER_RIGHT>& rhs);

    template<typename Unit, int POWER>
    std::ostream& operator<<(std::ostream& lhs, const PoweredUnit<Unit, POWER>& rhs);

    template<typename Unit, int POWER>
    std::istream& operator>>(std::istream& lhs, PoweredUnit<Unit,POWER>& rhs);
}

namespace std
{
    template<typename Unit, int POWER>
    Units::Complex::PoweredUnit<Unit, POWER> pow(const Unit& lhs);

    template<typename Unit, int STARTING_POWER, int RAISING_POWER>
    Units::Complex::PoweredUnit<Unit, STARTING_POWER*RAISING_POWER> pow(const Units::Complex::PoweredUnit<Unit, STARTING_POWER>& lhs);


}

//#include "PoweredUnit_FreeFuncs.tpp"
#include "PoweredUnit_Unit_2.tpp"
#include "PoweredUnit_Unit_Power.tpp"