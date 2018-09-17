
add_executable(tests
    Main.cpp
    Meter.Tests.cpp
    PoweredUnit_Meter.Tests.cpp)
target_link_libraries(tests CppUnitsCmake)
install (TARGETS tests DESTINATION ./bin)