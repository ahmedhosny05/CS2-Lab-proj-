#include "admin.h"
#include "ui_admin.h"
#include "login.h"
#include "article.h"
#include "createarticle.h"
#include "editarticle.h"
Admin::Admin( Login* login,QWidget *parent)
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
    int index = ui->DeleteArticlelineEdit->text().toInt();
    if (index >= 0 && index < login->articles.size()) {
        login->articles.erase(login->articles.begin() + index);
        login->saveArticlesToFile("article_credentials.txt");
        deleted = "deleted";
    }
    ui->DeleteArticleUpdate->setText(deleted);
    ui->DeleteArticleUpdate->setVisible(true);
}


void Admin::on_DisplayAvergaeRatingButton_clicked()
{
    QString title = ui->DisplayAverageRatinglineEdit->text();
    double sum = 0.0;
    int count = 0;

    for (const auto& article : login->articles)
    {
        if (article.title == title)
        {
            sum += article.rating;
            count++;
        }
    }

    if (count > 0)
    {
        ui->DisplayRatingUpdate->setText(QString::number(sum / count));
        ui->DisplayRatingUpdate->setVisible(true);
    }
    else
    {
        ui->DisplayRatingUpdate->setText("not found");
        ui->DisplayRatingUpdate->setVisible(true);
    }
}


void Admin::on_SaveArticleButton_clicked()
{
    if (login->saveArticlesToFile("article_credentials.txt")) {
        ui->SaveArticleUpdate->setText("saved");
        ui->SaveArticleUpdate->setVisible(true);
    }
else {
        ui->SaveArticleUpdate->setText("not saved error");
        ui->SaveArticleUpdate->setVisible(true);
}
}

void Admin::on_SaveAdminButton_clicked()
{
    if (login->saveAdminCredentialsToFile("admin_credentials.txt")) {
        ui->SaveAdminUpdate->setText("saved");
        ui->SaveAdminUpdate->setVisible(true);
    }
else {
            ui->SaveAdminUpdate->setText("not saved error");
            ui->SaveAdminUpdate->setVisible(true);
}
}

void Admin::on_CreateAndPublishNewArticle_clicked()
{
    CreateArticle* create = new CreateArticle(this,login);
    create->show();
    hide();
}


void Admin::on_AddNewCategoryButton_clicked()
{
    QString newCategory = ui->AddCategorylineEdit->text();
if (login->categoryMap.find(newCategory) == login->categoryMap.end())
        login->categoryMap[newCategory] = vector<Article>();
else
        ui->AddCategoryUpdate->setText("category already exists");
    login->saveArticlesToFile("article_credentials.txt");
}


void Admin::on_EditArticle_clicked()
{
    int index = ui->EditArticlelineEdit->text().toInt();
    EditArticle* edit = new EditArticle(login,index);
    edit->show();
    hide();
}

