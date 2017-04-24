#include "word.h"

Word::Word()
{

}

Word::Word(const char* in)
{
    name = in;
}

Word::Word(String rhs)
{
    name = rhs.getData();

}

void Word::addPageNumber(int p)
{
    if(!pageNumbers.contains(p))
        pageNumbers.add(p);
}

int Word::getPageNumber(int i )
{
    return pageNumbers[i];
}

int Word::getPageNumbersSize()
{
    return pageNumbers.size();
}

String Word::getWord()
{
    return name;
}

void Word::toLowerCase()
{
    name.toLowerCase();
}

bool Word::operator> (const Word rhs)
{
    bool isGreaterThan = false;

    if(name > rhs.name)
        isGreaterThan = true;

    return isGreaterThan;
}

bool Word::operator== (const Word rhs)
{

    bool isEqual = true;

    if(!(name == rhs.name))
        isEqual = false;

    return isEqual;
}

Word& Word::operator= (const char* rhs)
{
    name = rhs;
    pageNumbers.deleteData();

    return *this;
}

char Word::getCharacter(int i)
{
    return name[i];
}

void Word::sortPageNumbers()
{
    pageNumbers.sort();
}
