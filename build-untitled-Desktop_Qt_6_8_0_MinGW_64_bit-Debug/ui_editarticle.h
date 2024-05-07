/********************************************************************************
** Form generated from reading UI file 'editarticle.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITARTICLE_H
#define UI_EDITARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditArticle
{
public:
    QLabel *label;
    QLineEdit *ArticleTitlelineEdit;
    QLabel *label_2;
    QLineEdit *DescriptionlineEdit;
    QLabel *label_3;
    QLineEdit *DatelineEdit;
    QLabel *label_4;
    QLineEdit *CategorylineEdit;
    QLabel *label_5;
    QLineEdit *RatinglineEdit;
    QPushButton *EditArticleButton;
    QLabel *EditArticleUpdate;

    void setupUi(QWidget *EditArticle)
    {
        if (EditArticle->objectName().isEmpty())
            EditArticle->setObjectName("EditArticle");
        EditArticle->resize(400, 300);
        label = new QLabel(EditArticle);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 58, 16));
        ArticleTitlelineEdit = new QLineEdit(EditArticle);
        ArticleTitlelineEdit->setObjectName("ArticleTitlelineEdit");
        ArticleTitlelineEdit->setGeometry(QRect(130, 20, 113, 21));
        label_2 = new QLabel(EditArticle);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 70, 71, 16));
        DescriptionlineEdit = new QLineEdit(EditArticle);
        DescriptionlineEdit->setObjectName("DescriptionlineEdit");
        DescriptionlineEdit->setGeometry(QRect(130, 70, 113, 21));
        label_3 = new QLabel(EditArticle);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 120, 58, 16));
        DatelineEdit = new QLineEdit(EditArticle);
        DatelineEdit->setObjectName("DatelineEdit");
        DatelineEdit->setGeometry(QRect(130, 120, 113, 21));
        label_4 = new QLabel(EditArticle);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 170, 61, 16));
        CategorylineEdit = new QLineEdit(EditArticle);
        CategorylineEdit->setObjectName("CategorylineEdit");
        CategorylineEdit->setGeometry(QRect(130, 170, 113, 21));
        label_5 = new QLabel(EditArticle);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 220, 58, 16));
        RatinglineEdit = new QLineEdit(EditArticle);
        RatinglineEdit->setObjectName("RatinglineEdit");
        RatinglineEdit->setGeometry(QRect(130, 220, 113, 21));
        EditArticleButton = new QPushButton(EditArticle);
        EditArticleButton->setObjectName("EditArticleButton");
        EditArticleButton->setGeometry(QRect(280, 240, 100, 32));
        EditArticleUpdate = new QLabel(EditArticle);
        EditArticleUpdate->setObjectName("EditArticleUpdate");
        EditArticleUpdate->setGeometry(QRect(280, 150, 58, 16));

        retranslateUi(EditArticle);

        QMetaObject::connectSlotsByName(EditArticle);
    } // setupUi

    void retranslateUi(QWidget *EditArticle)
    {
        EditArticle->setWindowTitle(QCoreApplication::translate("EditArticle", "Form", nullptr));
        label->setText(QCoreApplication::translate("EditArticle", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("EditArticle", "Description ", nullptr));
        label_3->setText(QCoreApplication::translate("EditArticle", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("EditArticle", "Category", nullptr));
        label_5->setText(QCoreApplication::translate("EditArticle", "Rating", nullptr));
        EditArticleButton->setText(QCoreApplication::translate("EditArticle", "Edit Article", nullptr));
        EditArticleUpdate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditArticle: public Ui_EditArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITARTICLE_H
