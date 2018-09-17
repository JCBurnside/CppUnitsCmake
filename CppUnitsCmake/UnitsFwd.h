#pragma once
#include <chrono>
namespace Units
{
    namespace Distance
    {
        class Foot;
        class Inch;
        class Meter;
        class Kilometer;
        class Millimeter;
    }

    namespace Complex
    {
        template<typename Unit, int POWER>
        class PoweredUnit;

        template<typename... Units>
        class CompoundUnit;

    }

    namespace Chrono {
        using Second = std::chrono::seconds;
        using Minute = std::chrono::minutes;
        using Hour = std::chrono::hours;
        using Millisecond = std::chrono::milliseconds;
        using Nanosecond = std::chrono::nanoseconds;
        using Microsecond = std::chrono::microseconds;
    }
}