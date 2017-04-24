#include "origcity.h"

OrigCity::OrigCity()
{

}

OrigCity::OrigCity(String cityName)
{
    this->cityName = cityName;
}

/* Add a new destination city that can be reached from the
 * current origin city. */
void OrigCity::addDestCity(DestCity newDestCity)
{
    destCities.add(newDestCity);
}

String OrigCity::getCityName()
{
    return cityName;
}

/* Return the index of the location in the list of destination
 * cities that contains the same city name that is passed.
 * If there is no match, return -1 */
int OrigCity::getDestCityIndex(String destCity)
{
    for(int i = 0; i < destCities.size(); i++)
    {
        if(destCities.get(i).getCityName() == destCity)
            return i;
    }

    return -1;
}

int OrigCity::getDestCitySize()
{
    return destCities.size();
}

DestCity& OrigCity::getDestCity(int loc)
{
    return destCities.get(loc);
}

// returns the name of the city at the specified location
String OrigCity::getDestCityName(int loc)
{
    return destCities.get(loc).getCityName();
}


