#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class String
{

    public:


        String();
        String(const char*);
        String(const String&);
        String(const String&, int cap); // NEW function, passing a pre-desired capacity. Used by the addition operator


        String& operator= (const char*);
        String& operator= (const String&);
        String& operator+ (const String&);
        String& operator+= (const String&);
        bool operator== (const char*);
        bool operator== (const String&);
        bool operator> (const String& rhs);
        bool operator< (const String& rhs);
        char& operator[] (const int);


        int size();
        void sort();
        void toLowerCase();
        void removePunctuation();
        String substring(int, int);
        char* c_str();

        friend ostream& operator<< (ostream&, const String&);


        ~String();

    private:

        char* data; // Pointer to the c-string storing the characters that make up the string
        int len; // Stores the number of letters in the word +1 for the null terminator
        int cap; // Represents the maximum number of letters a word can contain





};

#endif // STRING_H
