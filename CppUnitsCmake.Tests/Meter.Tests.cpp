#include "catch2\catch.hpp"
#include "..\CppUnitsCmake\Meter.h"
using Units::Distance::Meter;
using namespace Units::Distance::Literals;

TEST_CASE("Meter Ctor Tests", "[meter]")
{
    SECTION("Literal ctor alias")
    {
        REQUIRE(typeid(1_m) == typeid(Meter));
        REQUIRE(typeid(1.0_m) == typeid(Meter));
    }
}