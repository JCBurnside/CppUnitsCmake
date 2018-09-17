#define CATCH_CONFIG_RUNNER
#define _SILENCE_CXX17_UNCAUGHT_EXCEPTION_DEPRECATION_WARNING
#include "catch2\catch.hpp"
#include "..\CppUnitsCmake\PoweredUnit.hpp"
#include "..\CppUnitsCmake\Meter.h"

int main(int argc, char* argv[])
{
    using namespace Units::Distance::Literals;
    using namespace Units::Complex;
    int result = Catch::Session().run(argc, argv);
    Units::Complex::PoweredUnit<Units::Distance::Meter, 2> m2 = 1_m * 1_m;
    bool test = operator==<Units::Distance::Meter,2>(m2,2);
    return result;
}