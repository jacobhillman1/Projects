#include "destcity.h"

DestCity::DestCity()
{

}

/* Constructor that takes in all of the data needed for the
 * destination city */
DestCity::DestCity(String cityName, int flightCost, int flightTime)
{
    this->cityName = cityName;
    this->cost = flightCost;
    this->time = flightTime;
}

String DestCity::getCityName()
{
    return cityName;
}

int DestCity::getCost()
{
    return cost;
}

int DestCity::getTime()
{
    return time;
}
