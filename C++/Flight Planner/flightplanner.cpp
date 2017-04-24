#include "flightplanner.h"

FlightPlanner::FlightPlanner()
{

}

/* Open the file containing the flight information and create
 * the city objects. Call function handleCities, which
 * stores the cities as an adjacency list of origin city objects
 * called parentCities. */
void FlightPlanner::readFile(char* data)
{
    ifstream flightData(data);
    int numConnections = 0;
    char tempLine[99];
    String tempString;
    int leftBound = 0;
    int i = 0;
    String tempCity1;
    String tempCity2;
    float tempCost = 0;
    float tempMinutes = 0;

    if(!flightData.is_open())
    {
        cout << "Error opening flight data file." << endl;
    }

    flightData >> numConnections;
    flightData.ignore(80, '\n');

    for(int j = 0; j < numConnections; j++)
    {        
       // flightData >> tempLine;
        flightData.getline(tempLine, 99);
        tempString = tempLine;
        leftBound = 0;
        i = 0;

        while(tempString[i] != '|')
            i++;

        tempCity1 = tempString.substring(leftBound, i);
        i++;
        leftBound = i;

        while(tempString[i] != '|')
            i++;

        tempCity2 = tempString.substring(leftBound, i);
        i++;
        leftBound = i;

        while(tempString[i] != '|')
            i++;

        tempCost = atoi(tempString.substring(leftBound, i).c_str());
        i++;
        leftBound = i;

        while(tempString[i] != '\0')
            i++;

        tempMinutes = atoi(tempString.substring(leftBound, i).c_str());

        // update the list with tempCity1 as the Origin and tempCity2 as the desitination
        handleCities(tempCity1, tempCity2, tempCost, tempMinutes);

        // update the list with tempCity2 as the Origin and tempCity1 as the desitination
        handleCities(tempCity2, tempCity1, tempCost, tempMinutes);

    }
}

/* Takes in the info from each line of the flight data
 * input file. If the city does not already exist in the parent
 * cities list, then add it. Call function that then performs
 * similar operations for the destination city */
void FlightPlanner::handleCities(String origCity, String destCity,
                                     float tempCost, float tempMinutes)
{
    // if the city is not already listed as a parent city, add it
    if(getOrigCityIndex(origCity) == -1)
        parentCities.add(origCity);

    // if the parent city does not already have the destination city, add it
    if(parentCities.get(getOrigCityIndex(origCity)).getDestCityIndex(destCity)
            == -1)
    {
        parentCities.get(getOrigCityIndex(origCity)).addDestCity
                (DestCity(destCity, tempCost, tempMinutes));
    }
}


/* getOrigCityIndex returns the index of the location in the list of
 * parent cities that contains the same city name that has been
 * passed. If no match is found, return -1 */
int FlightPlanner::getOrigCityIndex(String city)
{
    for(int i = 0; i < parentCities.size(); i++)
    {
        if(parentCities.get(i).getCityName() == city)
            return i;
    }

    // If there is no match found, return -1
    return -1;
}

/* readPathFile sets gets the value of the starting city, destination
 * and sorting method by reading the file and manipulating the objects
 * (because they are passed by reference) */
void FlightPlanner::readPathFile(ifstream& flightPathFile, String& startingCity,
                                 String& destination, bool& sortbyCost)
{
    char tempLine[99];
    String tempString;
    int i = 0;
    int leftBound = 0;

    flightPathFile.getline(tempLine, 99);
    tempString = tempLine;

    while(tempString[i] != '|')
        i++;

    startingCity = tempString.substring(leftBound, i);
    i++;
    leftBound = i;

    while(tempString[i] != '|')
        i++;

    destination = tempString.substring(leftBound, i);
    i++;
    leftBound = i;

    if(tempString[i] == 'C')
        sortbyCost = true;
    else
        sortbyCost = false;

}

/* createPaths manages the excecution of functions readPathFile
 * and checkDestCities in order to ultimately determine the
 * possible paths. createPaths takas in a char array that it uses
 * to create an ifstream object for the file that contains the starting and
 * destination cities. */
void FlightPlanner::createPaths(char fileName[])
{
    String startingCity;
    String destination;
    bool sortbyCost;
    int numPlans = 0;

    ifstream flightPathFile(fileName);

    if(!flightPathFile.is_open())
        cout << "Error opening flight path file" << endl;
    
    //read in the number of paths from the top of the file
    flightPathFile >> numPlans;
    flightPathFile.ignore(80, '\n');

    for(int i = 0; i < numPlans; i++)
    {
        // clear the path stack
        for(int s = 0; s < path.size(); s++)
            path.pop();
        //add a vector of flightpath objects to the vector
        possiblePaths.add(Vector<flightPath>());

        readPathFile(flightPathFile, startingCity, destination, sortbyCost);
        checkDestCities(startingCity, destination, sortbyCost, i);

        //sort the specific plan
        sort(sortbyCost, i);
    }
}

/* checkDestCities takes in a starting city and the final destinaion.
 * While the starting city will continue to change as the path
 * progresses, the destination with remain constant for each path.
 * The function creates a flightPath object with the the current path
 * if it is determined to end at the destination. */
void FlightPlanner::checkDestCities(String startingCity,
                                    String destination, bool sortbyCost, int planNum)
{
    bool continueFn = true;

    //push the city onto the stack
    path.push(startingCity);

    //check to see if this is the destination
    if(path.peek() == destination)
    {
        //*****RECORD PATH*****
        possiblePaths.get(planNum).add(flightPath(path, parentCities, sortbyCost));
        //pop the desination off to keep searching along this path
        path.pop();
        //do not continue on with the rest of the function
        continueFn = false;

    }

    if(continueFn)
    {
        //find the index of the starting (parent) city associacted with the city
        //we are currently at
        int i = 0;
        for(i = 0; i < parentCities.size(); i++)
        {
            if(parentCities.get(i).getCityName() == startingCity)
                break;
        }

        for(int j = 0; j < parentCities.get(i).getDestCitySize(); j++)
        {
            // if the desination city hasn't been visited yet, call this
            // function again to comtinue the search for the destination
            if(!path.contains(parentCities.get(i).getDestCityName(j)))
                checkDestCities(parentCities.get(i).getDestCityName(j),
                                destination, sortbyCost, planNum);

            //if you reach the end of the list, pop that off the city you're checking
            //to continue checking the other possibilities
            if(j == parentCities.get(i).getDestCitySize() - 1)
                path.pop();
        }
    }
    //once the function has reached the end of all the dest cities, the function
    //will end. This is the base case
}


/* sort sorts the paths in the each vector for each city. Sorting is
 * based on either cost or time, depending on what is read from the
 * file. */
void FlightPlanner::sort(bool sortbyCost, int planNum)
{
    //if sorting by cost...
    if(sortbyCost)
    {
        bool sorted = false;
        flightPath temp;
        while(!sorted)
        {
            // Set true initially, and eventually set false if characters are out of order
            sorted = true;
            for(int k = 0; k < possiblePaths.get(planNum).size() - 1; k++)
            {
                if(possiblePaths.get(planNum).get(k).getCost()
                        > possiblePaths.get(planNum).get(k+1).getCost())
                {
                    // If objects are determined to be out of order, swap the objects
                    //and set sorted to false to continue the loop.
                    temp = possiblePaths.get(planNum).get(k);
                    possiblePaths.get(planNum).get(k) = possiblePaths.get(planNum).get(k + 1);
                    possiblePaths.get(planNum).get(k + 1) = temp;
                    sorted = false;
                }
            }
        }
    }
    //if sorting by time...
    else
    {
        bool sorted = false;
        flightPath temp;
        while(!sorted)
        {
            // Set true initially, and eventually set false if characters are out of order
            sorted = true;
            for(int k = 0; k < possiblePaths.get(planNum).size() - 1; k++)
            {
                if(possiblePaths.get(planNum).get(k).getTime()
                        > possiblePaths.get(planNum).get(k+1).getTime())
                {
                    // If objects are determined to be out of order, swap the objects
                    //and set sorted to false to continue the loop.
                    temp = possiblePaths.get(planNum).get(k);
                    possiblePaths.get(planNum).get(k) = possiblePaths.get(planNum).get(k + 1);
                    possiblePaths.get(planNum).get(k + 1) = temp;
                    sorted = false;
                }
            }
        }
    }
}

void FlightPlanner::outputResults(char fileName[])
{
    ofstream fout(fileName);
    if(!fout.is_open())
    {
        fout << "Error opening output file" << endl;
    }
    else
        for(int i = 0; i < possiblePaths.size(); i++)
        {
            fout << "Flight " << i + 1 << ": ";
            //look at the first path object for each path to get the general flight info
            fout << possiblePaths.get(i).get(0).getCity(0) << ", "
                 << possiblePaths.get(i).get(0).getCity(possiblePaths.get(i).get(0).size() - 1);
            if(possiblePaths.get(i).get(0).getSort())
                fout << " (Cost)" << endl;
            else
                fout << " (Time)" << endl;

            if(possiblePaths.get(i).size() == 0)
                fout << "No flight plabs exist between these two cities." << endl;

            for(int j = 0; j < 3; j++)
            {
                if(j < possiblePaths.get(i).size())
                {
                    fout << "Path " << j + 1 << ": ";
                    fout << possiblePaths.get(i).get(j) << endl;
                }
            }
            fout << endl;
        }
}

/* testCities outputs what is stored in parent cities. Used to
 * visualize the connections between each city, and to make sure
 * everything is working correctly (testing) */
void FlightPlanner::testCities()
{
    for(int i = 0; i < parentCities.size(); i++)
    {
        cout << parentCities.get(i).getCityName() << ": ";

        for(int k = 0; k < parentCities.get(i).getDestCitySize(); k++)
            cout << parentCities.get(i).getDestCityName(k) << " ";
        cout << endl;
    }
}
