#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "login.h"
namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(Login* ,QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_DeleteArticle_clicked();

    void on_DisplayAvergaeRatingButton_clicked();

    void on_SaveArticleButton_clicked();

    void on_SaveAdminButton_clicked();

    void on_CreateAndPublishNewArticle_clicked();

    void on_AddNewCategoryButton_clicked();

    void on_EditArticle_clicked();

private:
    Ui::Admin *ui;
    Login* login;
};

#endif // ADMIN_H
