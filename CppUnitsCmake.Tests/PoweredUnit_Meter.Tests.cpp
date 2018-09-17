#include "catch2\catch.hpp"
#include "..\CppUnitsCmake\PoweredUnit.h"
#include "..\CppUnitsCmake\Meter.h"
using namespace Units::Complex;
using Units::Distance::Meter;
using namespace Units::Distance::Literals;
TEST_CASE("POWERED OPERATIONS", "[poweredUnit`meter]")
{
    WHEN("Unit is Units::Distance::Meter and POWER is 4")
    {
        SECTION("Lowering powers")
        {
            PoweredUnit<Meter, 4> m4(1ULL);
            PoweredUnit<Meter, 2> m2(1ULL);
            Meter m = 1_m;
            REQUIRE(typeid(m4 / m) == typeid(PoweredUnit<Meter, 3>));
            REQUIRE((m4 / m) == 1);
            REQUIRE(typeid(m2 / m) == typeid(Meter));
            REQUIRE(m2 / m == 1_m);
        }
    }
}