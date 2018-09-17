# CMakeList.txt : CMake project for CppUnitsCmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_library (CppUnitsCmake STATIC
    "CppUnitsCmake.cpp" "CppUnitsCmake.h"
    Kilometer.cpp Kilometer.h
    Meter.cpp Meter.h
    Millimeter.cpp Millimeter.h
    Foot.cpp Foot.h
    Inch.cpp Inch.h
    PoweredUnit.cpp PoweredUnit.h
    UnitException.cpp UnitException.h
    UnitTraits.hpp
    )

install ( TARGETS CppUnitsCmake DESTINATION lib)
instaLL (FILES 
    CppUnitsCmake.h
    Kilometer.h
    Meter.h
    Millimeter.h
    Foot.h
    Inch.h
    Distance.h
    PoweredUnit.h PoweredUnit_Unit_2.tpp PoweredUnit_Unit_Unit.tpp
    UnitsFwd.h
    UnitTraits.hpp

    DESTINATION inc/Units
)
# TODO: Add tests and install targets if needed.
