/********************************************************************************
** Form generated from reading UI file 'createarticle.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEARTICLE_H
#define UI_CREATEARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateArticle
{
public:
    QLabel *articetitle;
    QLineEdit *TitlelineEdit;
    QLabel *label;
    QLineEdit *DescriptionlineEdit;
    QLabel *label_2;
    QLineEdit *DatelineEdit;
    QLabel *label_3;
    QLineEdit *CategorylineEdit;
    QLabel *label_4;
    QLineEdit *RatinglineEdit;
    QPushButton *CreateArticleButton;
    QLabel *CreateArticleUpdate;
    QLabel *CreateArticleupdate;

    void setupUi(QWidget *CreateArticle)
    {
        if (CreateArticle->objectName().isEmpty())
            CreateArticle->setObjectName("CreateArticle");
        CreateArticle->resize(400, 300);
        articetitle = new QLabel(CreateArticle);
        articetitle->setObjectName("articetitle");
        articetitle->setGeometry(QRect(40, 40, 58, 16));
        TitlelineEdit = new QLineEdit(CreateArticle);
        TitlelineEdit->setObjectName("TitlelineEdit");
        TitlelineEdit->setGeometry(QRect(130, 40, 113, 21));
        label = new QLabel(CreateArticle);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 90, 71, 16));
        DescriptionlineEdit = new QLineEdit(CreateArticle);
        DescriptionlineEdit->setObjectName("DescriptionlineEdit");
        DescriptionlineEdit->setGeometry(QRect(130, 90, 113, 21));
        label_2 = new QLabel(CreateArticle);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 140, 58, 16));
        DatelineEdit = new QLineEdit(CreateArticle);
        DatelineEdit->setObjectName("DatelineEdit");
        DatelineEdit->setGeometry(QRect(130, 140, 113, 21));
        label_3 = new QLabel(CreateArticle);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 190, 61, 16));
        CategorylineEdit = new QLineEdit(CreateArticle);
        CategorylineEdit->setObjectName("CategorylineEdit");
        CategorylineEdit->setGeometry(QRect(130, 190, 113, 21));
        label_4 = new QLabel(CreateArticle);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 230, 58, 16));
        RatinglineEdit = new QLineEdit(CreateArticle);
        RatinglineEdit->setObjectName("RatinglineEdit");
        RatinglineEdit->setGeometry(QRect(130, 230, 113, 21));
        CreateArticleButton = new QPushButton(CreateArticle);
        CreateArticleButton->setObjectName("CreateArticleButton");
        CreateArticleButton->setGeometry(QRect(270, 260, 100, 32));
        CreateArticleUpdate = new QLabel(CreateArticle);
        CreateArticleUpdate->setObjectName("CreateArticleUpdate");
        CreateArticleUpdate->setGeometry(QRect(260, 190, 131, 20));
        CreateArticleupdate = new QLabel(CreateArticle);
        CreateArticleupdate->setObjectName("CreateArticleupdate");
        CreateArticleupdate->setGeometry(QRect(290, 200, 58, 16));

        retranslateUi(CreateArticle);

        QMetaObject::connectSlotsByName(CreateArticle);
    } // setupUi

    void retranslateUi(QWidget *CreateArticle)
    {
        CreateArticle->setWindowTitle(QCoreApplication::translate("CreateArticle", "Form", nullptr));
        articetitle->setText(QCoreApplication::translate("CreateArticle", "Title", nullptr));
        label->setText(QCoreApplication::translate("CreateArticle", "description", nullptr));
        label_2->setText(QCoreApplication::translate("CreateArticle", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("CreateArticle", "Category", nullptr));
        label_4->setText(QCoreApplication::translate("CreateArticle", "Rating", nullptr));
        CreateArticleButton->setText(QCoreApplication::translate("CreateArticle", "Create Article", nullptr));
        CreateArticleUpdate->setText(QString());
        CreateArticleupdate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateArticle: public Ui_CreateArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEARTICLE_H
