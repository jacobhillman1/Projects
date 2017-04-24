#include <iostream>
#include <fstream>
#include <cstring>
#include "DSString.h"

using namespace std;
void selectionSort(char**&, int, int, ostream&);
void selectionSortASCII(char**&, int, int);

int main(int argc, char* const argv[])
{    
    char temp[99];
    int numWords = 0;
    int numSorted = 0;

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin >> numWords;
    fin >> numSorted;

    char** words = new char*[numWords];
    for(int i = 0; i < numWords; i++)
    {
        fin >> temp;
        words[i] = new char[41];
        strcpy(words[i], temp);
    }

    selectionSort(words, numWords, numSorted, fout);

    return 0;
}

void selectionSort(char**& words, int numWords, int numSorted, ostream& fout)
{
    char temp[99];
    int loc = 0;
    int leftBound = 0;
    int rightBound = 0;

    for(int i = 0; i < numSorted; i++)
    {
        strcpy(temp, words[i]);
        loc = i;

        for(int j = i + 1; j < numWords; j++)
        {
            if(strlen(temp) >= strlen(words[j]))
            {
                strcpy(temp, words[j]);
                loc = j;
            }

        }
        if(loc != i)
        {
            strcpy(words[loc], words[i]);
            strcpy(words[i], temp);
        }
        //check to see if the strlen of that word that has been swapped in different
        if(i != 0)
        {
            if(strlen(words[i]) != strlen(words[i - 1]))
            {
                rightBound = i;
                selectionSortASCII(words, leftBound, rightBound);
                leftBound = i;
            }
        }
    }

    //make sure the last set of words is sorted
    selectionSortASCII(words, leftBound, numSorted);

    for(int i = 0; i < numSorted; i++)
        fout << words[i] << endl;
    cout << endl;
}

void selectionSortASCII(char**& words, int leftBound, int rightBound)
{
    char temp[99];
    int loc = 0;


    for(int i = leftBound; i < rightBound; i++)
    {
        strcpy(temp, words[i]);
        for(int j = i + 1; j < rightBound; j++)
        {
            if(strcmp(temp, words[j]) > 0)
            {
                strcpy(temp, words[j]);
                loc = j;
            }

        }
        if(loc != i)
        {
        strcpy(words[loc], words[i]);
        strcpy(words[i], temp);
        }
    }
}

