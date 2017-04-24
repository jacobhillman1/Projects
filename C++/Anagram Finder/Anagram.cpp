#include "Anagram.h"

Anagram::Anagram(char fin[], char fout[])
{
    strcpy(finFileName, fin);
    strcpy(foutFileName, fout);
}

// creates the array of word objects and sorts the words alphabetically. Returns nothing
void Anagram::handleArray()
{
    // instantiat the Wordlist object with the fileName
    wordList list(finFileName);

    // call list member functions
    list.fillArray();
    list.sortWords();
    list.processDat();
    // copy data from wordList object
    numUniqueSets = list.getNumUniqueSets();
    wordCount = list.getWordCount();
    list.getUniqueSets(uniqueSets);
}

// prints the results of the anagram to the file specified in argv[2] of main. Returns nothing
void Anagram::outputDat()
{
    // instantiate ofstream object
    ofstream fout(foutFileName);
    fout << "There are " << numUniqueSets << " unique sets." << endl;
    for(int i = 0; i < wordCount; i++)
    {       
        uniqueSets[i].getWord(tempWord);
        if(strcmp(tempWord, "") != 0)
            fout << tempWord << endl;
    }
    fout.close();
}

// tests if the files open correctly. Returns nothing
void Anagram::testFiles()
{
    //test the fin file
    ifstream fin(finFileName);
    ofstream fout(foutFileName);
    if(!fin.is_open())
    {
        fout << "Incorrect input file name. Please try again." << endl;
        exit(1);
    }

    //test the fout file
    if(!fout.is_open())
    {
        cout << "Incorrect output file name. Please try again." << endl;
        exit(1);
    }

    fin.close();
    fout.close();
}
