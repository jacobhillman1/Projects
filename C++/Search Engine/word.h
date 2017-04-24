/*
 * WORD CLASS
 * Word objects hold the name of the word and a vector of the
 * articles in which the word can be found. The AVL tree in the
 * SearchEngine class is comprised of Word objects.
 */
#ifndef WORD_H
#define WORD_H

#include "DSString.h"
#include "DSvector.h"
#include "article.h"

class Word
{
private:
    String name;
    Vector<Article> articles;
public:
    Word(String in)
    {
        name = in;
    }

    Word(String in, Article article)
    {
        name = in;
        addArticle(article);
    }

    bool operator> (const Word& rhs)
    {
        return name > rhs.name;
    }

    bool operator< (const Word& rhs)
    {
        return name < rhs.name;
    }

    void addArticle(Article in)
    {
        if(!articles.contains(in))
            articles.add(in);
    }

    int getNumArticles()
    {
        return articles.size();
    }

    Article& getArticle(int i)
    {
        return articles.get(i);
    }

    friend ostream& operator<<(ostream& out, Word& rhs)
    {
        out << rhs.name;
        return out;
    }

    bool operator==(const String& rhs)
    {
        return name == rhs;
    }



};

#endif // WORD_H

