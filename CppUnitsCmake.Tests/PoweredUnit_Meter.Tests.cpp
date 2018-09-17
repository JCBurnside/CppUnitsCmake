#include "..\CppUnitsCmake\PoweredUnit.hpp"
#include "..\CppUnitsCmake\Meter.h"
#include "catch2\catch.hpp"
using namespace Units::Complex;
using Units::Distance::Meter;
using namespace Units::Distance::Literals;
SCENARIO("POWERED OPERATIONS", "[poweredUnit`meter]")
{
    GIVEN("A few units ( 2 m^2, 4 m^4, 1 m)")
    {
        PoweredUnit<Meter, 4> m4(4ULL);
        PoweredUnit<Meter, 2> m2(2ULL);
        Meter m = 1_m;

        WHEN("Dividing 4 m^4 by 1 m")
        {
            auto m3 = m4 / m;

            THEN("power is reduced and it will equal 4 m^3")
            {
                REQUIRE(m3.Power == 3);
                //REQUIRE(m3 == 4.0L);
            }
        }

        WHEN("Dividing 4 m^4 by 2 m^2")
        {
            auto result = m4 / m2;
            THEN("power is reduced and it will equal 2 m^2")
            {
                REQUIRE(result.Power == 2);
                //REQUIRE(result == 2.0L);
            }
        }

    }
}