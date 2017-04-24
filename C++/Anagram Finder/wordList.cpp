#include "wordList.h"

using namespace std;

// parameterized constructor
wordList::wordList(char input[])
{
    strcpy(fileName, input);
}

// use an ifstream object to read an words and assign them to word objects
// in the array words. Returns nothing
void wordList::fillArray()
{
    ifstream fin(fileName);

    // obtain the wordcount
    fin >> wordCount;

    for(int i = 0; i < wordCount; i++)
    {
        fin >> tempWord;

        words[i].setWord(tempWord);
    }

    fin.close();
}

// sort the word object in each element of the array. Returns nothing
void wordList::sortWords()
{
    for(int i = 0; i < wordCount; i++)
    {
        words[i].sort();
    }

}

// return the number of words read from the file by copying it over to the array in the parameter
int wordList::getWordCount()
{
    return wordCount;
}

// determine the amount of unique character sets in the array of word objects. Returns nothing
void wordList::processDat()
{
    // put the sorted char data into a two dimensional array
    char temp[26];
    char listOfWords[1000][26];
    for(int i = 0; i < wordCount; i++)
    {
        words[i].getSortedWord(temp);
        strcpy(listOfWords[i], temp);
    }

    for(int i = 0; i < wordCount; i++)
    {
        if(strlen(listOfWords[i]) != 0)
        {
            for(int c = 1; c < wordCount; c++)
            {
                if(strlen(listOfWords[c]) != 0 && c != i)
                {
                    if(strcmp(listOfWords[i], listOfWords[c]) == 0)
                    {
                        // Set the duplicates = "" so the final count of unique sets is not eventually
                        // affected by these sets
                        strcpy(listOfWords[c], "");
                    }
                }
            }
            numUniqueSets++;
        }
    }

    // convert the 2D array back into an array of word objects
    for(int i = 0; i < wordCount; i++)
    {
        words[i].setWord(listOfWords[i]);
    }
}

// return int uniqueSets
int wordList::getNumUniqueSets()
{
    return numUniqueSets;
}

// copy the array of data holding the unique sets using the copy constructor. Returns nothing
void wordList::getUniqueSets(Word w[])
{
    for(int i = 0; i < wordCount; i++)
        w[i] = words[i];
}
