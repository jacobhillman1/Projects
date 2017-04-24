#ifndef WORD_H
#define WORD_H

#include "word.h"
#include "DSString.h"
#include "DSvector.h"

class Word
{
private:
    String name;
    Vector<int> pageNumbers;


public:
    Word();
    Word(const char*); //constructor that takes a cstring
    Word(const String);
    void addPageNumber(int); //add the page number the word is located at to the page number vector. if the vector already conatins
    //the page number, don't add it again
    void toLowerCase();

    int getPageNumber(int); //returns a specific page number
    int getPageNumbersSize();
    void sortPageNumbers();
    String getWord();
    char getCharacter(int);


    bool operator> (const Word); //evaluates based on ascii value of "name". used to sort in alphabetical order
    bool operator==(const Word);
    Word& operator=(const char*);
};

#endif // PAGE_H


