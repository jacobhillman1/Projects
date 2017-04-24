#ifndef FLIGHTPLANNER_H
#define FLIGHTPLANNER_H
#include <fstream>
#include <iostream>
#include "DSString.h"
#include <cctype>
#include "linkedlist.h"
#include "origcity.h"
#include "destcity.h"
#include "stack.h"
#include "flightpath.h"

using namespace std;

class FlightPlanner
{
private:       
    LinkedList<OrigCity> parentCities;
    Stack<String> path;
    Vector<Vector<flightPath>> possiblePaths;

public:
    FlightPlanner();
    void readFile(char[]);
    void handleCities(String, String, float, float);
    int getOrigCityIndex(String);    
    void readPathFile(ifstream&, String&, String&, bool&);
    void createPaths(char[]);    
    void checkDestCities(String, String, bool, int);
    void sort(bool, int);
    void outputResults(char[]);
    void testCities();

};

#endif // FLIGHTPLANNER_H
