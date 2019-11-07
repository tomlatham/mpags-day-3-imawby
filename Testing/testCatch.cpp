//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Addition works", "[math]"){
  REQUIRE(1+1 == 2);
}

TEST_CASE("subtraction works", "[maths]"){
  REQUIRE(1-1 == 0);
}
