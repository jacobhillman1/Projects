#include "flightpath.h"

flightPath::flightPath()
{
    cost = 0;
    time = 0;
}

flightPath::flightPath(Stack<String>& path)
{
    for(int i = 0; i < path.size(); i++)
    {
        //add the cities to the vector
        cities.add(path.get(i));
    }
    cost = 0;
    time = 0;
}

flightPath::flightPath(Stack<String>& path, LinkedList<OrigCity> parentCities, bool sortbyCost)
{
    for(int i = 0; i < path.size(); i++)
    {
        //add the cities to the vector
        cities.add(path.get(i));
    }
    calculateTotals(parentCities);
    this->sortbyCost = sortbyCost;
}

int flightPath::size()
{
    return cities.size();
}

int flightPath::getCost()
{
    return cost;
}

int flightPath::getTime()
{
    return time;
}

String flightPath::getCity(int i)
{
    return cities.get(i);
}

/* Using the path, go through the list of cities and calculate
 * the total cost and time of this particular path. Takes in
 * parent cities to use for comparisons */
void flightPath::calculateTotals(LinkedList<OrigCity> parentCities)
{
    for(int i = 0; i < cities.size(); i++)
    {
        for(int k = 0; k < parentCities.size(); k++)
        {
            if(parentCities.get(k).getCityName() == cities.get(i))
            {
                //find where the destination city is from this origin city
                for(int j = 0; j < parentCities.get(k).getDestCitySize(); j++)
                {
                    if(parentCities.get(k).getDestCityName(j) == cities.get(i + 1))
                    {
                        //add the cost of the going from this city to the next
                        cost += parentCities.get(k).getDestCity(j).getCost();
                        //add the time of going from this city to the next
                        time += parentCities.get(k).getDestCity(j).getTime();
                    }
                }
            }
        }
    }
}

void flightPath::setSort(bool in)
{
    sortbyCost = in;
}

bool flightPath::getSort()
{
    return sortbyCost;
}

flightPath& flightPath::operator= (flightPath* rhs)
{
    cities = rhs->cities;
    cost = rhs->cost;
    time = rhs->time;
    sortbyCost = rhs->sortbyCost;

    return *this;
}

ostream& operator<<(ostream& out, flightPath& rhs)
{
    for(int i = 0; i < rhs.cities.size(); i++)
    {
        out << rhs.cities.get(i);
        if(i != rhs.cities.size() - 1)
            out << " -> ";
        else
            out << ". " << "Time: " << rhs.getTime() << " Cost: " << rhs.getCost() << ".00";
    }

    return out;
}
