/*
 * SEARCH ENGINE CLASS
 * The search engine class coordinates everything regarding searching.
 * It reads the files, and parses the AVL tree to search for the words
 * requested in the query.
 */
#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "DSString.h"
#include <iostream>
#include <fstream>
#include "article.h"
#include "word.h"
#include "avltree.h"
#include "linkedlist.h"

class SearchEngine
{
private:
    AvlTree<Word> searchWords;
    Vector<String> stopWords;
public:
    SearchEngine();
    void addStopWords(char fileName[]);
    void readFile(char fileName[]);
    void handleHeader(ifstream& fin, Article&);
    void handleParagraph(ifstream& fin, Article&);
    void processQueries(char fileName[], char output[]);
    void search(fstream& fin, ofstream& out, String& tempString);
    void ANDWords(LinkedList<Article>&, fstream& fin, String&);
    void NOTWords(LinkedList<Article>&,fstream& fin, String&);
    void ORWords(LinkedList<Article>&, fstream& fin, String& );
};

#endif // SEARCHENGINE_H
