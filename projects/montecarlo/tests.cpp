#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "factorial.h"


add_test(circle ./tests [circle])
add_test(rectangle ./tests [rectangle])
add_test(irregular ./tests [irregular])
add_test(combo ./tests [combo])


TEST_CASE( "Circle Calculation", "[circle]" ) {
    REQUIRE( Circle(1) == 1 );
}

TEST_CASE( "Circle Calculation", "[rectangle]" ) {
    REQUIRE( Rectangle(1) == 1 );
}

TEST_CASE( "Irregular Area Calculation", "[irregular]" ) {
    REQUIRE( Irregular(1) == 1 );
}

TEST_CASE( "Combo", "[combo]" ) {
    REQUIRE( Combo(1) == 1 );
}