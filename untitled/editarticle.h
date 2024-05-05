#ifndef EDITARTICLE_H
#define EDITARTICLE_H
#include "login.h"
#include <QWidget>

namespace Ui {
class EditArticle;
}

class EditArticle : public QWidget
{
    Q_OBJECT

public:
    explicit EditArticle(Login*,int ,QWidget *parent = nullptr);
    ~EditArticle();

private slots:
    void on_EditArticleButton_clicked();

private:
    Ui::EditArticle *ui;
    Login* login;
    int index;
};

#endif // EDITARTICLE_H
