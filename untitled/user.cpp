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
    if(!ui->SearchlineEdit->text().isEmpty()) {
        QString keyword = ui->SearchlineEdit->text();
        for (const auto& article : login->articles) {
            if (article.title.contains(keyword, Qt::CaseInsensitive) ||
                article.description.contains(keyword, Qt::CaseInsensitive) ||
                article.category.contains(keyword, Qt::CaseInsensitive)) {
                QString search =  "Title " + article.title + " description " + article.description + " category " + article.category;
                ui->SearchUpdate->setText(search);
            }
            else {
                ui->SearchUpdate->setText("not found");
            }
    }
}
}

void User::on_ViewArticlesButton_clicked()
{
    if (!ui->ViewArticleslineEdit->text().isEmpty()) {
        QString category = ui->ViewArticleslineEdit->text();
        if (login->categoryMap.find(category) != login->categoryMap.end()) {
            for (const auto& article : login->categoryMap[category]) {
                QString search =  "Title " + article.title + " description " + article.description + " category " + article.category + " Date " + article.date + " Rating " + QString::number(article.rating);
                ui->viewarticlesupdate->setText(search);
            }
    }
        else {
            ui->viewarticlesupdate->setText("not found");
        }
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
    ui->latestarticlesupdate->setVisible(true);
    ui->latestarticlesupdate->setText(latestArticles);
}



void User::on_SaveButton_clicked()
{
    login->saveUserCredentials("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/user_credentials.txt");
    login->saveArticlesToFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/article_credentials.txt");
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

