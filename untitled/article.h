#ifndef ARTICLE_H
#define ARTICLE_H
#include <qstring.h>
class Article
{
public:
    Article();
    QString title;
    QString description;
    QString date;
    int rating;
    QString category;
};

#endif // ARTICLE_H
