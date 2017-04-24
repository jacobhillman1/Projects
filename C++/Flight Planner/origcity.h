#ifndef ORIGCITY_H
#define ORIGCITY_H
#include "DSString.h"
#include "linkedlist.h"
#include "destcity.h"


class OrigCity
{
private:
    String cityName;
    LinkedList<DestCity> destCities;
public:
    OrigCity();
    OrigCity(String);

    void addDestCity(DestCity);
    String getCityName();
    int getDestCityIndex(String);
    int getDestCitySize();
    String getDestCityName(int);
    DestCity& getDestCity(int);
};

#endif // ORIGCITY_H
