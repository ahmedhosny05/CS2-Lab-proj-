#include "createarticle.h"
#include "ui_createarticle.h"
#include "login.h"
#include "article.h"
CreateArticle::CreateArticle(Admin* admin, Login* login,QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::CreateArticle)
{
    ui->setupUi(this);
    this->login=login;
    this->admin = admin;
}

CreateArticle::~CreateArticle()
{
    delete ui;
}

void CreateArticle::on_CreateArticleButton_clicked()
{
    QString Title = ui->TitlelineEdit->text();
    QString Description = ui->DescriptionlineEdit->text();
    QString Date = ui->DatelineEdit->text();
    QString Category = ui->CategorylineEdit->text();
    int Rating = ui->RatinglineEdit->text().toInt();
    if (!Title.isEmpty() && !Description.isEmpty() && !Date.isEmpty() && !Category.isEmpty()) {
    Article article;
    article.title= Title;
    article.description = Description;
    article.date = Date;
    article.category = Category;
    article.rating = Rating;
    login->articles.push_back(article);
    login->categoryMap[article.category].push_back(article);
    if (login->saveArticlesToFile("article_credentials.txt"))
        ui->CreateArticleUpdate->setText("created and saved");
        ui->CreateArticleUpdate->setVisible(true);
        admin->show();
        hide();
}
}

