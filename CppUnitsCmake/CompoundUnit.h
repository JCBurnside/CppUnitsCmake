#pragma once
namespace Units::Complex
{
    template<typename Unit, int POWER>
    class PoweredUnit;

    template<typename... Units>
    class CompoundUnit
    {
    private:
        long double datum;
    public:
        CompoundUnit();
        CompoundUnit(const CompoundUnit&) = default;
        CompoundUnit(CompoundUnit&&) = default;
        ~CompoundUnit();
    };

    template<typename Unit, typename... Units>
    auto operator/(const CompoundUnit<Units...>& lhs, const Unit& rhs);

    template<typename Unit, typename... Units>
    auto operator*(const CompoundUnit<Units...>& lhs, const Unit& rhs);
}
