#ifndef DESTCITY_H
#define DESTCITY_H
#include "DSString.h"


class DestCity
{
private:
    String cityName;
    float cost, time = 0;
public:
    DestCity();
    DestCity(String cityName, int flightCost, int flightTime);
    String getCityName();
    int getCost();
    int getTime();
};

#endif // DESTCITY_H
