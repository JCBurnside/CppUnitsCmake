#pragma once
#include <type_traits>
#include "UnitsFwd.h"
namespace Units::Traits
{
    template<typename UnitLeft, typename UnitRight>
    struct measures_same
    {
        static constexpr bool value = std::is_same_v<UnitLeft, UnitRight>;
    };

    template<typename UnitLeft, typename UnitRight>
    using measures_same_v = measures_same<UnitLeft, UnitRight>::value;

    template<typename UnitCheck, typename UnitAgainst, typename... RemainingUnits>
    struct contains
    {
        static constexpr bool value = std::is_same_v<UnitCheck, UnitAgainst> || contains<UnitCheck, RemainingUnits...>::value;
    };

    template<typename UnitCheck>
    struct contains
    {
        static constexpr bool value = false;
    };

    template<typename... Units>
    using contains_v = contains<Units...>::value;

    template<>
    struct measures_same<Units::Distance::Foot, Units::Distance::Inch>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Foot, Units::Distance::Meter>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Foot, Units::Distance::Kilometer>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Foot, Units::Distance::Millimeter>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Inch, Units::Distance::Foot>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Inch, Units::Distance::Foot>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Inch, Units::Distance::Meter>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Distance::Inch, Units::Distance::Kilometer>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Distance::Inch, Units::Distance::Millimeter>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Meter, Units::Distance::Foot>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Meter, Units::Distance::Inch>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Meter, Units::Distance::Kilometer>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Meter, Units::Distance::Millimeter>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Distance::Millimeter, Units::Distance::Foot>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Millimeter, Units::Distance::Inch>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Millimeter, Units::Distance::Kilometer>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Millimeter, Units::Distance::Meter>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Kilometer, Units::Distance::Foot>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Kilometer, Units::Distance::Inch>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Kilometer, Units::Distance::Meter>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Distance::Kilometer, Units::Distance::Millimeter>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Nanosecond, Units::Chrono::Hour>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Nanosecond, Units::Chrono::Minute>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Nanosecond, Units::Chrono::Second>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Nanosecond, Units::Chrono::Millisecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Nanosecond, Units::Chrono::Microsecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Microsecond, Units::Chrono::Hour>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Microsecond, Units::Chrono::Minute>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Microsecond, Units::Chrono::Second>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Microsecond, Units::Chrono::Millisecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Microsecond, Units::Chrono::Nanosecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Millisecond, Units::Chrono::Hour>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Millisecond, Units::Chrono::Minute>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Millisecond, Units::Chrono::Second>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Millisecond, Units::Chrono::Microsecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Second, Units::Chrono::Nanosecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Second, Units::Chrono::Hour>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Second, Units::Chrono::Minute>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Chrono::Second, Units::Chrono::Millisecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Second, Units::Chrono::Microsecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Second, Units::Chrono::Nanosecond>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Chrono::Minute, Units::Chrono::Hour>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Minute, Units::Chrono::Second>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Minute, Units::Chrono::Millisecond>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Chrono::Minute, Units::Chrono::Microsecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Minute, Units::Chrono::Nanosecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Hour, Units::Chrono::Minute>
    {
        static constexpr bool value = true;
    };
    
    template<>
    struct measures_same<Units::Chrono::Hour, Units::Chrono::Second>
    {
        static constexpr bool value = true;
    };
     
    template<>
    struct measures_same<Units::Chrono::Hour, Units::Chrono::Millisecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Hour, Units::Chrono::Microsecond>
    {
        static constexpr bool value = true;
    };

    template<>
    struct measures_same<Units::Chrono::Hour, Units::Chrono::Nanosecond>
    {
        static constexpr bool value = true;
    };

}
