#ifndef WORD_H
#define WORD_H

#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

class Word
{
private:
    // Declaring c-strings
    char origLetters[25] = {0};
    char sortedLetters[25] = {0};

public:
    // Declaring constructors
    Word();
    Word(char w[]);

    // Declaring member functions
    void setWord(char w[]);
    void getWord(char w[]);
    void getSortedWord(char w[]);
    void sort();
    void swap(char& a, char& b);
    friend ostream& operator<<(ostream& out, Word& rhs);
};

#endif // WORD_H
