#include "user.h"
#include "ui_user.h"
#include "login.h"
#include <QVector>
#include <vector>
#include "article.h"
using namespace std;
class User;

namespace Ui {
class Login;
}
User::User(Login* login,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);
    this->login = login;
    login->loadArticlesFromFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/article_credentials.txt");
}

User::~User()
{
    delete ui;
}

void User::on_SearchButton_clicked()
{
    QString keyword = ui->SearchlineEdit->text();
    QString searchResult;
    bool found = false;
    if (!keyword.isEmpty()) {
    for (const auto& article : login->articles) {
        QString articleEntry = article.title + " " + article.description + " " + article.category;
        if (articleEntry.contains(keyword, Qt::CaseInsensitive)) {
            searchResult += "Title: " + article.title + "\nDescription: " + article.description + "\nCategory: " + article.category + "\nRating:" + QString::number(article.rating) + "\n\n";
            found = true;
        }
    }

    if (found) {
        ui->searchupdate->setText(searchResult);
    } else {
        ui->searchupdate->setText("No articles found.");
    }
}
}




void User::on_latestarticlesButton_clicked()
{
    QString latestArticles;
    for (int i = login->articles.size() - 1; i >= 0; i--) {
        QString articleInfo =
            "Title: " + login->articles[i].title + "\n" +
            "Description: " + login->articles[i].description + "\n" +
            "Rating: " + QString::number(login->articles[i].rating) + "\n\n";

        latestArticles += articleInfo;
    }
    ui->viewlatestupdate->setText(latestArticles);
}



void User::on_SaveButton_clicked()
{
    if (login->saveUserCredentials("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/user_credentials.txt"))
        if(login->saveArticlesToFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/article_credentials.txt"))
            ui->saveupdate->setText("updated and saved");
}


void User::on_RateButton_clicked()
{
    int rating = ui->ArticleRatingnumberlineEdit->text().toInt();
    QString articleTitle = ui->ArticleRatinglineEdit->text();
    if (rating >= 1 && rating <= 5) {
        auto it = findArticleByTitle(articleTitle);
        if (it != login->articles.end()) {
            it->rating = rating;
            ui->rateupdate->setText("Rating accepted");
            on_SaveButton_clicked();
        }
    }
}

vector<Article>::iterator User::findArticleByTitle(const QString& title)
{
    for (auto it = login->articles.begin(); it != login->articles.end(); ++it) {
        if (it->title == title) {
            return it;
        }
    }
    return login->articles.end();
}


