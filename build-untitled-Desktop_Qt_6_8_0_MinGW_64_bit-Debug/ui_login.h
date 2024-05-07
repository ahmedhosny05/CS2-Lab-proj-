/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *errorlabel;
    QLabel *label;
    QLineEdit *UsernameLineEdit;
    QLabel *label_2;
    QLineEdit *PasswordlineEdit;
    QPushButton *OnLoginButton;
    QPushButton *OnRegsiterButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        errorlabel = new QLabel(Login);
        errorlabel->setObjectName("errorlabel");
        errorlabel->setGeometry(QRect(140, 270, 251, 16));
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 71, 16));
        UsernameLineEdit = new QLineEdit(Login);
        UsernameLineEdit->setObjectName("UsernameLineEdit");
        UsernameLineEdit->setGeometry(QRect(160, 60, 113, 21));
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 110, 61, 16));
        PasswordlineEdit = new QLineEdit(Login);
        PasswordlineEdit->setObjectName("PasswordlineEdit");
        PasswordlineEdit->setGeometry(QRect(160, 110, 113, 21));
        PasswordlineEdit->setEchoMode(QLineEdit::Password);
        OnLoginButton = new QPushButton(Login);
        OnLoginButton->setObjectName("OnLoginButton");
        OnLoginButton->setGeometry(QRect(80, 190, 100, 32));
        OnRegsiterButton = new QPushButton(Login);
        OnRegsiterButton->setObjectName("OnRegsiterButton");
        OnRegsiterButton->setGeometry(QRect(210, 190, 100, 32));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        errorlabel->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" color:#ff2600;\">Username or password not found!</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Login", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Password", nullptr));
        OnLoginButton->setText(QCoreApplication::translate("Login", "Login", nullptr));
        OnRegsiterButton->setText(QCoreApplication::translate("Login", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
