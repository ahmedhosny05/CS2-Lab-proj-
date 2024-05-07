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

    for (const auto& article : login->articles) {
        QString articleEntry = article.title + " " + article.description + " " + article.category;
        if (articleEntry.contains(keyword, Qt::CaseInsensitive)) {
            searchResult += "Title: " + article.title + "\nDescription: " + article.description + "\nCategory: " + article.category + "\n\n";
            found = true;
        }
    }

    if (found) {
        ui->SearchUpdate->setText(searchResult);
    } else {
        ui->SearchUpdate->setText("No articles found.");
    }
}


void User::on_ViewArticlesButton_clicked()
{
    QString category = ui->ViewArticleslineEdit->text();
    QString categoryArticles;
    auto it = login->categoryMap.find(category);
    if (it != login->categoryMap.end()) {
        for (const auto& article : it->second) {
            categoryArticles += "Title: " + article.title + "\nDescription: " + article.description + "\nCategory: " + article.category + "\n\n";
        }
        ui->viewarticlesupdate->setText(categoryArticles);
    } else {
        ui->viewarticlesupdate->setText("No articles found in this category.");
    }
}



void User::on_latestarticlesButton_clicked()
{
    QString latestArticles;
    for (int i = login->articles.size() - 1; i >= 0; i--) {
        QString articleInfo = "Category: " + login->articles[i].category + "\n" +
                              "Title: " + login->articles[i].title + "\n" +
                              "Description: " + login->articles[i].description + "\n\n";
        latestArticles += articleInfo;
    }
    ui->latestarticlesupdate->setText(latestArticles);
}



void User::on_SaveButton_clicked()
{
    login->saveUserCredentials("C:/Users/dell/Desktop/csss 2/CS2-Lab-proj-/untitled/user_credentials.txt");
    login->saveArticlesToFile("C:/Users/dell/Desktop/csss 2/CS2-Lab-proj-/untitled/article_credentials.txt");
}


void User::on_RateButton_clicked()
{
    int rating = ui->ArticleRatingnumberlineEdit->text().toInt();
    QString articleTitle = ui->ArticleRatinglineEdit->text();
    if (rating >= 1 && rating <= 5) {
        auto it = findArticleByTitle(articleTitle);
        if (it != login->articles.end()) {
            it->rating = rating;
            ui->RateUpdate->setText("Rating accepted");
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

