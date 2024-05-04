#include "admin.h"
#include "ui_admin.h"
#include "login.h"
Admin::Admin(QWidget *parent, Login* login)
    : QWidget(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->login = login;
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_DeleteArticle_clicked()
{
    QString deleted = "not deleted";
    int index = ui->DeleteArticlelineEdit->text();
    if (index >= 0 && index < login->articles.size()) {
        login->articles.erase(articles.begin() + index);
        login->saveArticlesToFile("article_credentials.txt");
        deleted = "deleted";
    }
    ui->DeleteArticleUpdate->setText(deleted);
    ui->DeleteArticleUpdate->show();
}

