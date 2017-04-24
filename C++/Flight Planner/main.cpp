/* Jacob Hillman
 * Flight Planner (Sprint 2)
 * This program takes in flight data, containing which
 * cities can access each other, as well as the cost and time
 * of each flight. The program also takes in requested flight plans,
 * containing a pair of cities and the priority by which the results
 * should be listed (cost or time). The program then outputs up to the
 * top three most effecient paths between these two cities. */

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "../Sprint1/DSString.h"
#include "origcity.h"
#include "destcity.h"
#include "flightplanner.h"

void testCityCreation();
void checkArguments(int);

//If you don't want tests to run, change true to false in the line below.
#define TEST false

int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}

int main( int argc, char* const argv[] )
{

    if (TEST)
    {
        return runCatchTests(argc, argv);
    }

    checkArguments(argc);

    FlightPlanner flights;
    flights.readFile(argv[1]);
    flights.createPaths(argv[2]);
    flights.outputResults(argv[3]);

    return 0;
}

 void checkArguments(int argc)
 {
     if(argc != 4)
     {
         cout << "Invalid number of command line arguments, please try again.";
         exit(1);
     }
 }
