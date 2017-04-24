#include "DSString.h"
#include <iostream>

/* Default constructor */
String::String()
{
    len = 0;
    cap = 0;
    data = nullptr;
}

/* Parameterized constructor. Is passed a char pointer. */
String::String(const char* rhs)
{

    len = strlen(rhs);
    cap = len + 1;

    data = new char[cap]; // creates a new c-string at the location stored in the member variable data. +1 is to store the null terminator

    strcpy(data, rhs); // Copy the characters from the inputed c-string to the c-string stored at the adress held in the data member varaible

}

/* Copy constructor. Is passed a String object.*/
String::String(const String& rhs)
{
    len = rhs.len;
    cap = len + 1;
    data = new char[cap];

    for(int i = 0; i < cap; i++) // Copy the chars from the String object passed in the parameter
        data[i] = rhs.data[i];
}

String::String(const String& rhs, int cap)
{
    this->cap = cap;
    len = cap - 1;
    data = new char[cap];

    for(int i = 0; i < cap; i++) // Copy the chars from the String object passed in the parameter
        data[i] = rhs.data[i];
}


// Destructor - cleans up the memory after it is done being used
String::~String()
{
    if(data != nullptr)
        delete[]data;
}

// Overload the equality operator when equating to another String object
String& String::operator= (const String& rhs)
{
    if(data != nullptr) delete[]data;

    if(this != &rhs) // Coding against self-assignment problem
    {
        if(rhs.data != nullptr) // check to make sure "data" of the String object rhs is not pointing to anything
        {
            this -> len = rhs.len;
            cap = len + 1;
            data = new char[cap];
            for(int i = 0; i < cap; i++) // Copy over the data
                data[i] = rhs. data[i];
        }
    }
    return *this;
}

// Overload the equality operator when equating to a c-string
String& String::operator= (const char* rhs)
{
    if(data != nullptr) delete[] data;

    len = strlen(rhs);
    cap = len + 1;
    data = new char[cap]; // Create a blank character array at address "data"
    strcpy(data, rhs); // Copy over the data

    return *this;
}

String& String::operator+ (const String& rhs)
{
    int tempLen = len + strlen(rhs.data);
    int tempCap = tempLen + 1;

    char* temp = new char[tempCap];

    int rhsLoc = 0; //Used to go through each character in the second word

    if(rhs.data != nullptr)
    {
        for(int i = 0; i < len; i++) // Copy over the initial data
        {
            temp[i] = data[i];
        }
        for(int i = len; i < tempLen; i++) // Start at the end of the lhs word, add until the length of the lhs word + length of the rhs word
        {
            temp[i] = rhs.data[rhsLoc];
            rhsLoc++;
        }
    }

    temp[len + rhsLoc] = '\0';

    String* result = new String(temp);

    delete[] temp;

    return *result;
}


/* This function compares the c-string held in the string object to another c-string. Reutns true if both are the same. */
bool String::operator== (const char* rhs)
{

    bool isEqual = true;

    if(rhs == nullptr)
        isEqual = false;
    else if(len != strlen(rhs)) // First, check to see if the lengths of the words are equal. If they are, proceed to check if all of the characters are the same.
        isEqual = false;
    else
    {
        for(int i = 0; i < len; i++)
        {
            if(data[i] != rhs[i])
            {
                isEqual = false;
            }
        }
    }

    return isEqual;

}

/* This function compares the c-string held in the string object to another c-string held in a String object. Reutns true if both are the same. */
bool String::operator== (const String& rhs)
{

    bool isEqual = true;

    if(len != rhs.len) // First, check to see if the lengths of the words are equal. If they are, proceed to check if all of the characters are the same.
        isEqual = false;

    else
    {
        for(int i = 0; i < len; i++)
        {
            if(data[i] != rhs.data[i])
            {
                isEqual = false;
            }
        }
    }

    return isEqual;
}

/* Retruns true if the lhs word has a higher ASCII value than the rhs word. AKA, if it comes later in the alphabet */
bool String::operator> (const String& rhs)
{
    bool isGreaterThan = false;

    if(data[0] > rhs.data[0])
        isGreaterThan = true;

    return isGreaterThan;

}

/* Access specific characters of the c-string by using brackets. Returns the character held in the specified element of the character array. */
char& String::operator[] (const int element)
{

    if(element > cap) // Prevent the function from reaching passed the bounds of the array.
    {
        cout << "This string does not contain " << element << "characters." << endl;
        return data[0];
    }

    if(element < 0)
    {
        return data[len + element]; // if the number in the braces is negative, then the function will count backwards in the word. [0] Wil be the null terminator.
    }

    else
        return data[element];

}

/* This function returns the number of characters in the c-string held in the String object as an int */
int String::size()
{
    return len; // returns the length of the c-string stored in the object, not counting the null-terminator. This value is already stored in len
}

/* Returns a new String object that will contain only the range of characters specific in the parameter */
String String::substring(int leftBound, int rightBound)
{
    int tempLen = 0;
    int loc = 0;

    //CHECK TO MAKE SURE IN BOUNDS

    char* temp = nullptr; // make a new c-string that will be used to create a new string object

    if(leftBound < 0 && rightBound < 0) // Next three functions account for negative values entered in the parameters.
    {
        tempLen = abs(leftBound) - abs(rightBound);
        temp = new char[tempLen + 1];
        for(int i = len + leftBound + 1; i < len + rightBound + 1; i++)
        {
            temp[loc] = data[i];
            loc++;
        }
    }
    else if(leftBound < 0)
    {
        tempLen = (len + leftBound) - rightBound;
        temp = new char[tempLen + 1];
        for(int i = len + leftBound; i < len; i++)
        {
            temp[loc] = data[i];
            loc++;
        }
    }
    else if(rightBound < 0)
    {
        tempLen = (len + rightBound) - leftBound + 1;
        temp = new char[tempLen + 1];
        for(int i = leftBound; i < len + rightBound + 1; i++)
        {
            temp[loc] = data[i];
            loc++;
        }
        cout << "test " << endl;
    }
    else { // If all parameters are positive.
        tempLen = rightBound - leftBound;
        temp = new char[tempLen + 1];
        for(int i = leftBound; i < rightBound; i++)
        {
            temp[loc] = data[i];
            loc++;
        }
    }

    temp[loc] = '\0'; // Add null-terminator to end of the c-string.

    String sub(temp); // create a new String object with the c-string

    delete[]temp; // free the memory being used by the c-string

    return sub;
}

/* Returns the memory address of the c-string held in the String object */
char* String::c_str()
{
    return data;
}

/* Sorts characters in the c-string according to ASCII values, returns void. */
void String::sort()
{
    bool sorted = false;
    char temp;
    while(!sorted)
    {
        // Set true initially, and eventually set false if characters are out of order
        sorted = true;
        for(int i = 0; i < len - 1; i++)
        {
            if(data[i] > data[i + 1])
            {
                // If words are determined to be out of order, swaps the letters and sets sorted to false to continue the loop.
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

void String::toLowerCase()
{
    for(int i = 0; i < len; i++)
       data[i] = tolower(data[i]);
}

ostream& operator<< (ostream& out, const String& rhs)
{
    out << rhs.data;

    return out;
}
