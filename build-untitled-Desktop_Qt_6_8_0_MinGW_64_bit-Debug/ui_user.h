/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QLabel *label;
    QLineEdit *SearchlineEdit;
    QLabel *SearchUpdate;
    QPushButton *SearchButton;
    QPushButton *ViewArticlesButton;
    QLineEdit *ViewArticleslineEdit;
    QLabel *viewarticlesupdate;
    QPushButton *latestarticlesButton;
    QLabel *latestarticlesupdate;
    QLineEdit *ArticleRatinglineEdit;
    QLineEdit *ArticleRatingnumberlineEdit;
    QPushButton *RateButton;
    QLabel *RateUpdate;
    QPushButton *SaveButton;
    QLabel *SaveUpdate;

    void setupUi(QWidget *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName("User");
        User->resize(471, 473);
        label = new QLabel(User);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 161, 16));
        SearchlineEdit = new QLineEdit(User);
        SearchlineEdit->setObjectName("SearchlineEdit");
        SearchlineEdit->setGeometry(QRect(170, 10, 113, 21));
        SearchUpdate = new QLabel(User);
        SearchUpdate->setObjectName("SearchUpdate");
        SearchUpdate->setGeometry(QRect(227, 20, 171, 191));
        SearchButton = new QPushButton(User);
        SearchButton->setObjectName("SearchButton");
        SearchButton->setGeometry(QRect(300, 10, 131, 32));
        ViewArticlesButton = new QPushButton(User);
        ViewArticlesButton->setObjectName("ViewArticlesButton");
        ViewArticlesButton->setGeometry(QRect(160, 50, 131, 32));
        ViewArticleslineEdit = new QLineEdit(User);
        ViewArticleslineEdit->setObjectName("ViewArticleslineEdit");
        ViewArticleslineEdit->setGeometry(QRect(20, 50, 113, 21));
        viewarticlesupdate = new QLabel(User);
        viewarticlesupdate->setObjectName("viewarticlesupdate");
        viewarticlesupdate->setGeometry(QRect(180, 90, 131, 101));
        latestarticlesButton = new QPushButton(User);
        latestarticlesButton->setObjectName("latestarticlesButton");
        latestarticlesButton->setGeometry(QRect(10, 140, 141, 32));
        latestarticlesupdate = new QLabel(User);
        latestarticlesupdate->setObjectName("latestarticlesupdate");
        latestarticlesupdate->setGeometry(QRect(150, 120, 241, 201));
        ArticleRatinglineEdit = new QLineEdit(User);
        ArticleRatinglineEdit->setObjectName("ArticleRatinglineEdit");
        ArticleRatinglineEdit->setGeometry(QRect(20, 180, 113, 21));
        ArticleRatingnumberlineEdit = new QLineEdit(User);
        ArticleRatingnumberlineEdit->setObjectName("ArticleRatingnumberlineEdit");
        ArticleRatingnumberlineEdit->setGeometry(QRect(20, 340, 113, 21));
        RateButton = new QPushButton(User);
        RateButton->setObjectName("RateButton");
        RateButton->setGeometry(QRect(170, 330, 100, 32));
        RateUpdate = new QLabel(User);
        RateUpdate->setObjectName("RateUpdate");
        RateUpdate->setGeometry(QRect(280, 170, 171, 241));
        SaveButton = new QPushButton(User);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setGeometry(QRect(30, 420, 100, 32));
        SaveUpdate = new QLabel(User);
        SaveUpdate->setObjectName("SaveUpdate");
        SaveUpdate->setGeometry(QRect(210, 420, 58, 16));

        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QWidget *User)
    {
        User->setWindowTitle(QCoreApplication::translate("User", "Form", nullptr));
        label->setText(QCoreApplication::translate("User", "Enter title to search for:", nullptr));
        SearchUpdate->setText(QString());
        SearchButton->setText(QCoreApplication::translate("User", "Search for Article", nullptr));
        ViewArticlesButton->setText(QCoreApplication::translate("User", "View articles", nullptr));
        viewarticlesupdate->setText(QString());
        latestarticlesButton->setText(QCoreApplication::translate("User", "View latest articles", nullptr));
        latestarticlesupdate->setText(QString());
        RateButton->setText(QCoreApplication::translate("User", "Rate", nullptr));
        RateUpdate->setText(QString());
        SaveButton->setText(QCoreApplication::translate("User", "Save To file", nullptr));
        SaveUpdate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
