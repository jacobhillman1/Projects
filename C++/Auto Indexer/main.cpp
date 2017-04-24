/* AUTO INDEXER (Sprint 1)
 * Jacob Hillman
 * This program takes in a book and category file. It creates an index based
 * on the words in the file, and is able to associate words with categories. The String
 * and Vector classes used are made from scratch, and each class has a variety of
 * different functions (most tested extensively with the catch library). This project
 * also has several iterations posted to github throughout its development */
//CATCH_CONFIG_RUNNER tells the catch library that this
//project will now explicitly call for the tests to be run.
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSvector.h"
#include "DSString.h"
#include "word.h"
#include <iostream>
#include <fstream>

using namespace std;

void checkArguments(int);
void generateWords(char* file, Vector<Vector<String>>, Vector<Word>& words); //takes in the filename,  vector of word objects
void generateCategories(char*, Vector<Vector<String>>&); //fill the vectors with categories and keywords
void outputData(Vector<Vector<String>>, Vector<Word>, char*); //output the data ontot the out file with correct formatting
void addCategories(Vector<Vector<String>>, Vector<Word>&); // adds the categories to the word list, handles words that are keywords
void formatWords(Vector<Vector<String>>, Vector<Word>&); //changes all words to lowercase, sorts in alphabetical order

#define TEST false // TOGGLE THIS FOR TESTS

int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}

int main( int argc, char* const argv[] )
{
    if (TEST)
    {
        return runCatchTests(argc, argv);
    }

    checkArguments(argc);
    Vector<Vector<String>> categories; // the vectors within the vector contain the name of the category in the first element of the vector, and the keywords of that category following
    Vector<Word> words; //holds all of the words within the book

    generateCategories(argv[2], categories); //pass name of category file, category vector of vectors
    generateWords(argv[1], categories, words); // reads words from the book file

    formatWords(categories, words);

    outputData(categories, words, argv[3]);
    return 0;
}

//checkArguments will make sure that the user has entered exacty 3 arguments into the
//command line
void checkArguments(int argc)
{
    if(argc != 4)
    {
        cout << "Invalid number of command line arguments, please try again.";
        exit(1);
    }
}

void generateCategories(char* file, Vector<Vector<String> >& categories)
{
    ifstream fin(file);
    char tempLine[81];
    String tempString;
    int start = 0;
    int catNum= 0;
    bool afterEqual = false;

    if(!fin.is_open()) //check to make sure the file has actually been opened
    {
        cout << "Error opening the file." << endl;
        exit(1);
    }

    while(fin.good())
    {
        categories.add(Vector<String>()); //add a vector of strings into the vector of vectors
        fin.getline(tempLine, 81);

        tempString = tempLine;

        for(int i = 0; i < tempString.size(); i++)
        {
            if(tempLine[i] == ' ')
            {
                if(!afterEqual) //make sure it's not the space after the equal sign
                {
                categories[catNum].add(tempString.substring(start, i));
                start = i + 1; //the next word will start at the character after the space
                }
                afterEqual = false;
            }
            else if(tempLine[i] == '=')
            {
                afterEqual = true;
                start += 2; //offset the start by two to compensate for the = and the space
            }
            else if(i == tempString.size() - 1) //can't forget about the last word
            {
                categories[catNum].add(tempString.substring(start, i + 1));
            }
        }
        start = 0; //set start back to zero for the next line
        catNum++;
    }
}

void generateWords(char* file, Vector<Vector<String>> categories, Vector<Word>& words)
{
    ifstream fin(file);
    int pageNumber = 0;
    char temp[31];
    String tempString;
    Word tempWord;

    if(!fin.is_open()) //check to make sure the file has actually been opened
    {
        cout << "Error opening the file." << endl;
        exit(1);
    }

    addCategories(categories, words); //add categories here to make sure to account for the page numbers of the names of the categories themselves

    //Reading words from the file
    while(fin.good())
    {
        fin >> temp;
        tempString = temp;
        tempWord = temp; //resides "name" in the word, also resets the page numbers in the word object
        if(strspn(temp, "[]"))
        {
            pageNumber = tempString.extractNumber();
            if(pageNumber == -1) break; //stop when you reach the indicator for the end of the file, -1
        }
        else if(words.contains(tempWord)) //if the word has already occured, just add the page number to the word object
        {
            words[words.containsAt(tempWord)].addPageNumber(pageNumber); //adds the page number at the location where the word is stored
        }
        else
        {
            tempWord.addPageNumber(pageNumber); //add the page number to the temp words
            words.add(tempWord);

        }
    }
}

// adds the categories to the word list
void addCategories(Vector<Vector<String>> categories, Vector<Word>& words)
{
    for(int i = 0; i < categories.size() - 1; i++)
    {
        words.add(categories[i][0]); // the words at [0] is always the master category. Has no page Numbers
    }
}

// make all words lowercase, sort the words in alphabetical order
void formatWords(Vector<Vector<String>> categories, Vector<Word>& words)
{
    for(int i = 0; i < words.size(); i++)
    {
        words[i].toLowerCase();
    }

    words.sort(); //sort words in alphabetical order

    //give the categories the page numbers of the keywords
    for(int i = 0; i < words.size(); i++)
    {
        for(int k = 0; k < categories.size() - 1; k++)
        {
            for(int n = 1; n < categories[k].size(); n++)
            {
                if(words[i] == categories[k][n]) //if the word == a keyword. Starts at 1 bc 0 is the category itself
                {
                    for(int y = 0; y < words[i].getPageNumbersSize(); y++)
                    {
                        words[words.containsAt(categories[k][0])].addPageNumber(words[i].getPageNumber(y));
                        //add the page number of the keyword at the location of the category in the words vector
                    }
                }
            }
        }
    }
}

void outputData(Vector<Vector<String>> categories, Vector<Word> words, char* file)
{
    bool print = true; //prevents from printing page numbers of keywords when false
    char letter;
    int wrapCounter = 50;
    int temp= 0;
    int tempCount = 0; //used for determining the number of ints in a page number
    ofstream fout(file);

    if(!fout.is_open()) //check to make sure the file has actually been opened
    {
        cout << "Error opening the file." << endl;
        exit(1);
    }

    for(int i = 0; i < words.size(); i++)
    {
        //print the first letter of the first word
        if(i == 0)
        {
        letter = toupper(words[0].getCharacter(0));
        fout << "[" << letter << "]" << endl;
        }
        //if it's the start of a new letter, print that letter in brackets
        if(i > 0 && words[i].getCharacter(0) != words[i-1].getCharacter(0))
        {
            letter = toupper(words[i].getCharacter(0));
            fout << "[" << letter << "]" << endl;
        }
        print = true;
        for(int k = 0; k < categories.size() - 1; k++)
        {
            for(int n = 1; n < categories[k].size(); n++)
            {
                if(words[i] == categories[k][n]) //if the word == a keyword. Starts at 1 bc 0 is the category itself
                {
                    fout << "For " << words[i].getWord() << ", see " << categories[k][0].getData() << "." << endl;
                    print = false; //print == false so the word that's a keyword won't be printed again
                }
            }
        }
        if(print)
        {
            wrapCounter = 0;
            //only print the word if it apppears in the text. This is only an issue
            //for categories that don't have any keywords that appear
            if(words[i].getPageNumbersSize() != 0)
            {
            words[i].sortPageNumbers(); //sort the page numbers from lowest to highest
            wrapCounter += words[i].getWord().size(); //add the length of the word to the wrap count
            fout << words[i].getWord() << ": ";
            wrapCounter += 2; //for the ": "
            for(int y = 0; y < words[i].getPageNumbersSize(); y++)
            {
                temp = words[i].getPageNumber(y);
                tempCount = 0;
                while(temp != 0) //add one to wrapCounter for every digit in the page number
                {
                    temp /= 10;
                    tempCount++;
                }
                wrapCounter += tempCount;
                if(y < words[i].getPageNumbersSize() - 1)
                {
                    if(wrapCounter + 2 < 50) //see if there is enough room after the ", "
                    {
                        fout << words[i].getPageNumber(y) << ", ";
                        wrapCounter += 2; //for the ", "
                    }
                    else
                    {
                        fout << endl;
                        fout << "    " << words[i].getPageNumber(y) << ", ";
                        wrapCounter = tempCount + 6; //+6 because 4 for the spaces, 2 for the ", "
                    }

                }
                else //if it's the last page number
                {
                    if(wrapCounter < 50)
                    {
                        fout << words[i].getPageNumber(y);
                    }
                    else
                    {
                        fout << endl;
                        fout << "    " << words[i].getPageNumber(y);

                    }
                }
            }
            fout << endl;
            }
        }
    }
}
