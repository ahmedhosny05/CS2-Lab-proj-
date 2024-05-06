#ifndef USER_H
#define USER_H
#include "login.h"
#include <QWidget>
class Login;
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(Login*,QWidget *parent = nullptr);
    ~User();

private slots:
    void on_SearchButton_clicked();

    void on_ViewArticlesButton_clicked();

    void on_latestarticlesButton_clicked();

private:
    Ui::User *ui;
    Login* login;
};

#endif // USER_H
