#ifndef CREATEARTICLE_H
#define CREATEARTICLE_H

#include <QWidget>
#include "login.h"
#include "admin.h"

namespace Ui {
class CreateArticle;
}

class CreateArticle : public QWidget
{
    Q_OBJECT

public:
    explicit CreateArticle(Admin*, Login*, QWidget *parent = nullptr);
    ~CreateArticle();

private slots:
    void on_CreateArticleButton_clicked();

private:
    Ui::CreateArticle *ui;
    Login* login;
    Admin * admin;
};

#endif // CREATEARTICLE_H
