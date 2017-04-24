#ifndef WORDLIST_H
#define WORDLIST_H
#include "Word.h"
#include <iostream>
#include <fstream>

using namespace std;

class wordList
{
private:
    int wordCount = 0;
    char tempWord[26];
    char fileName[99];
    Word words[1000]; // Declaring the array of word objects
    int numUniqueSets = 0;

public:
    // constructors
    wordList();
    wordList(char fileName[]);

    // member function prototypes
    void fillArray();
    void sortWords();
    void processDat();
    int getWordCount();
    int getNumUniqueSets();
    void getUniqueSets(Word w[]);
};

#endif // WORDLIST_H
