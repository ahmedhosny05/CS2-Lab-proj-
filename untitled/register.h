#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "login.h"
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(Login*,QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    Login* login;
};

#endif // REGISTER_H
