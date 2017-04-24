#include "Word.h"

using namespace std;


Word::Word(){

}

// A parameterized constructor to pass the object a c-string
Word::Word(char w[])
{
    strcpy(origLetters, w);
}

// Set the word through this function  by receiving a c-string. Returns nothing
void Word::setWord(char w[])
{
    strcpy(origLetters, w);
}

// Copy the private c-string origLetters to a char[] passed throught the paramter of the method
// Returns nothing
void Word::getWord(char w[])
{
    strcpy(w, origLetters);
}

// Copy the priavte c-string sortedLetters to a char[] passed through the paramter of the method
// Returns nothing
void Word::getSortedWord(char w[])
{
    strcpy(w, sortedLetters);
}

// Sort the characters in alphabetical order by calling swap function. Returns nothing
void Word::sort()
{
    strcpy(sortedLetters, origLetters);

    bool sorted = false;
    while(!sorted)
    {
        // Set true initially, and eventually set false if characters are out of order
        sorted = true;
        for(int i = 0; i < (strlen(sortedLetters) - 1); i++)
        {
            if(sortedLetters[i] > sortedLetters[i + 1])
            {
                // If words are determined to be out of order, calls the swap function and sets
                // sorted to false to contunie the loop
                swap(sortedLetters[i], sortedLetters[i + 1]);
                sorted = false;
            }
        }
    }
}

// Simple swap function that uses pass by reference to swap the characters. Working towards
// alphabetical order. Returns nothing
void Word::swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

ostream& operator<<(ostream& out, Word& rhs)
{
    out << rhs.origLetters;
    return out;
}

