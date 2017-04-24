/*
 * ARTICLE CLASS
 * This class is used to hold the information about an article.
 * A vector of articles is held in every Word object, and this is
 * how informatino about the article is returned.
 */
#ifndef ARTICLE_H
#define ARTICLE_H

#include "DSString.h"

class Article
{
private:
    String idNumber;
    String articleTitle;
    String URL;

public:
    void setID(String ID)
    {
        idNumber = ID;
    }

    void setTitle(String title)
    {
        articleTitle = title;
        articleTitle.toLowerCase();
    }

    void setURL(String URL)
    {
        this->URL = URL;
    }

    String getID() const
    {
        return idNumber;
    }

    bool operator<(const Article& rhs)
    {
        return idNumber < rhs.idNumber;
    }

    bool operator>(const Article& rhs)
    {
        return idNumber > rhs.idNumber;
    }

    bool operator==(const Article& rhs)
    {
        if(idNumber == rhs.getID())
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& out, Article& rhs)
    {
        out << rhs.idNumber << "|" << rhs.articleTitle << "|" << rhs.URL;

        return out;
    }


};

#endif // ARTICLE_H

