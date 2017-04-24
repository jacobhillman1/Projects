#ifndef ANAGRAM_H
#define ANAGRAM_H
#include "wordList.h"

class Anagram
{
private:
    char finFileName[99];
    char foutFileName[99];
    char tempWord[26];
    Word uniqueSets[1000];
    int wordCount = 0;
    int numUniqueSets = 0;

public:
    Anagram();
    Anagram(char fin[], char fout[]);

    void testFiles();
    void handleArray();
    void outputDat();
};

#endif // ANAGRAM_H
