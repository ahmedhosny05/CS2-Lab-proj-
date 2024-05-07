#include "editarticle.h"
#include "ui_editarticle.h"
#include "article.h"
#include "login.h"
EditArticle::EditArticle(Login* login, int index, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditArticle)
{
    ui->setupUi(this);
    this->login = login;
    this->index = index;
}

EditArticle::~EditArticle()
{
    delete ui;
}

void EditArticle::on_EditArticleButton_clicked()
{
    QString title = ui->ArticleTitlelineEdit->text();
    QString description = ui->DescriptionlineEdit->text();
    QString date = ui->DatelineEdit->text();
    QString category = ui->CategorylineEdit->text();
    int rating = ui->RatinglineEdit->text().toInt();
    if (!title.isEmpty() && !description.isEmpty() && !date.isEmpty() && !category.isEmpty()) {
    Article article ;
    article.title= title;
    article.description = description;
    article.date= date;
    article.category= category;
    article.rating= rating;
    if (index >= 0 && index < login->articles.size()) {
        login->articles[index] = article;
        login->saveArticlesToFile("C:/Users/dell/Desktop/csss 2/CS2-Lab-proj-/untitled/article_credentials.txt");
        ui->EditArticleUpdate->setText("edited and saved");
        ui->EditArticleUpdate->setVisible(true);
    }
    else {
        ui->EditArticleUpdate->setText("not edited and not saved");
        ui->EditArticleUpdate->setVisible(true);
    }
}
}
