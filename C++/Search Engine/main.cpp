#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "searchengine.h"
#include "avltree.h"
#include "word.h"

//If you want tests to run, change true to false in the line below.
#define TEST false

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

    SearchEngine miniSearchEngine;
    miniSearchEngine.addStopWords(argv[3]);
    miniSearchEngine.readFile(argv[1]);
    miniSearchEngine.processQueries(argv[2], argv[4]);

    return 0;
}
