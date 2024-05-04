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
    explicit Admin(QWidget *parent = nullptr, Login*);
    ~Admin();

private slots:
    void on_DeleteArticle_clicked();

private:
    Ui::Admin *ui;
    Login* login;
};

#endif // ADMIN_H
