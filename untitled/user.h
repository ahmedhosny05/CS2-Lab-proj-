#ifndef USER_H
#define USER_H
#include "login.h"
#include <QWidget>
#include <vector>
using namespace std;
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



    void on_latestarticlesButton_clicked();

    void on_SaveButton_clicked();

    void on_RateButton_clicked();
    vector<Article>::iterator findArticleByTitle(const QString& title);
private:
    Ui::User *ui;
    Login* login;
};

#endif // USER_H
