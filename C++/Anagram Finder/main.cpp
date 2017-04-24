/* Jacob Hillman PA05
 * This program parses through a file containing various words and determines how many sets
 * of duplicate sets letters the file contains. The program outputs the number of unique sets
 * as well as the characters themselves in alphabetical order. All of this is achieved using
 * object oriented programming */


#include <iostream>
#include "Anagram.h"

using namespace std;
void checkArguments(int args);
void testOverloadedOperator();

int main(int argc, char* argv[])
{
    checkArguments(argc);
    // instantiate an Anagram object using the data entered in the command line argument.
    // argv[1] is the fin file, and argv[2] is the fout file
    Anagram decoder(argv[1], argv[2]);

    decoder.testFiles(); // make sure the files are legit
    decoder.handleArray(); // sort and analyze all data in the array of Word objects
    decoder.outputDat(); // output the results to the file specified in argv[2]

}

// make sure correct number of command line arguments
void checkArguments(int argc)
{
    if(argc != 3)
    {
        cout << "Invalid number of command line arguments, please try again." << endl;
        exit(1);
    }
}

