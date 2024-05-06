#include "user.h"
#include "ui_user.h"
#include "login.h"
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
    for (int i = login->articles.size() - 1; i >= 0; i--) {
        QString latest = "categroy " + login->articles[i].category + " title " + login->articles[i].title + " description " + login->articles[i].description;
        ui->latestarticlesupdate->setText(latest);
    }
}


void User::on_SaveButton_clicked()
{
    login->saveUserCredentials("user_credentials.txt");
    login->saveArticlesToFile("article_credentials.txt");
}

