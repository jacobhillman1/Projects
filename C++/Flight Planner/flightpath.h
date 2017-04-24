#ifndef FLIGHTPATH_H
#define FLIGHTPATH_H
#include "DSvector.h"
#include "DSString.h"
#include "stack.h"
#include "linkedlist.h"
#include "origcity.h"


class flightPath
{
private:
    //cities holds the path of the flight
    Vector<String> cities;
    float cost = 0;
    float time = 0;
    bool sortbyCost;
public:
    flightPath();
    flightPath(Stack<String>&);
    flightPath(Stack<String>&, LinkedList<OrigCity>, bool);
    int size();
    int getCost();
    int getTime();
    String getCity(int);
    void calculateTotals(LinkedList<OrigCity>);
    void setSort(bool);
    bool getSort();

    flightPath& operator=(flightPath*);
    friend ostream& operator<<(ostream&, flightPath&);
};

#endif // FLIGHTPATH_H
