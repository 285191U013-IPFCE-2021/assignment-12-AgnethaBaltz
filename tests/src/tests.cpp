#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("Duration")
{
    Duration d;
    Duration d1(0); //Time = 0
    Duration d2(5); //Time = 5
    Duration d3(15); //Time = 15
    Duration d4(1); //Time = 1
    Duration d5(2); //Time = 2
    Duration d6(60); //Time = 60

    d1.setAlarm(2); //Alarm = 2
    d2.setAlarm(10); //Alarm = 10
    d5.setAlarm(30); //Alarm = 30
    d6.setAlarm(120); //Alarm = 120

    //Testing the duration methods
    REQUIRE(d.getDuration() == 0); 
    REQUIRE(d1.getDuration() == 0);
    REQUIRE(d2.getDuration() == 5);
    REQUIRE(d3.getDuration() == 15);
    REQUIRE(d6.getDuration() == 60);
    
    //Testing the tick method that increments the time
    REQUIRE(d1.tick() == FALSE);
    REQUIRE(d4.tick() == TRUE);
    REQUIRE(d5.tick() == FALSE);
    REQUIRE(d6.tick() == FALSE);

    //Testing the tick method that adds a value to the time
    REQUIRE(d1.tick(5) == TRUE);
    REQUIRE(d2.tick(10) == TRUE);
    REQUIRE(d3.tick(30) == TRUE); 
    REQUIRE(d6.tick(50) == FALSE);
    
}

