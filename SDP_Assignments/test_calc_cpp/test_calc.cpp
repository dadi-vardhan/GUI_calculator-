#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch2/catch.hpp"
#include "../calc_cpp/calculator_without_gui.cpp"

TEST_CASE("calculator without GUI is tested","[addition,subtraction,multiplication and division]"){
calculator a;

// test calculator functions 
REQUIRE(a.add(3,6)==9);
REQUIRE(a.subtract(3,6)==-3);
REQUIRE(a.multiply(3,6)==18);
REQUIRE(a.divide(6,3)==2); 

// test if an exception is thrown 
REQUIRE_THROWS_WITH(a.divide(6,0)==2,"Divide by zero exception");
}

//how to compile and run 
//g++ -std=c++11 -o test_calc test_calc.cpp 
//./test_calc


