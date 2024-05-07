/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QPushButton *CreateAndPublishNewArticle;
    QPushButton *EditArticle;
    QPushButton *DeleteArticle;
    QPushButton *AddNewCategoryButton;
    QLineEdit *DeleteArticlelineEdit;
    QLineEdit *EditArticlelineEdit;
    QLineEdit *DisplayAverageRatinglineEdit;
    QPushButton *DisplayAvergaeRatingButton;
    QPushButton *SaveArticleButton;
    QPushButton *SaveAdminButton;
    QLabel *DeleteArticleUpdate;
    QLabel *DisplayRatingUpdate;
    QLabel *SaveArticleUpdate;
    QLabel *SaveAdminUpdate;
    QLineEdit *AddCategorylineEdit;
    QLabel *AddCategoryUpdate;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(400, 300);
        CreateAndPublishNewArticle = new QPushButton(Admin);
        CreateAndPublishNewArticle->setObjectName("CreateAndPublishNewArticle");
        CreateAndPublishNewArticle->setGeometry(QRect(0, 0, 141, 32));
        EditArticle = new QPushButton(Admin);
        EditArticle->setObjectName("EditArticle");
        EditArticle->setGeometry(QRect(140, 40, 100, 32));
        DeleteArticle = new QPushButton(Admin);
        DeleteArticle->setObjectName("DeleteArticle");
        DeleteArticle->setGeometry(QRect(140, 80, 100, 32));
        AddNewCategoryButton = new QPushButton(Admin);
        AddNewCategoryButton->setObjectName("AddNewCategoryButton");
        AddNewCategoryButton->setGeometry(QRect(130, 130, 151, 32));
        DeleteArticlelineEdit = new QLineEdit(Admin);
        DeleteArticlelineEdit->setObjectName("DeleteArticlelineEdit");
        DeleteArticlelineEdit->setGeometry(QRect(10, 90, 113, 21));
        EditArticlelineEdit = new QLineEdit(Admin);
        EditArticlelineEdit->setObjectName("EditArticlelineEdit");
        EditArticlelineEdit->setGeometry(QRect(10, 40, 113, 21));
        DisplayAverageRatinglineEdit = new QLineEdit(Admin);
        DisplayAverageRatinglineEdit->setObjectName("DisplayAverageRatinglineEdit");
        DisplayAverageRatinglineEdit->setGeometry(QRect(20, 170, 113, 21));
        DisplayAvergaeRatingButton = new QPushButton(Admin);
        DisplayAvergaeRatingButton->setObjectName("DisplayAvergaeRatingButton");
        DisplayAvergaeRatingButton->setGeometry(QRect(150, 170, 100, 32));
        SaveArticleButton = new QPushButton(Admin);
        SaveArticleButton->setObjectName("SaveArticleButton");
        SaveArticleButton->setGeometry(QRect(30, 210, 100, 32));
        SaveAdminButton = new QPushButton(Admin);
        SaveAdminButton->setObjectName("SaveAdminButton");
        SaveAdminButton->setGeometry(QRect(160, 210, 100, 32));
        DeleteArticleUpdate = new QLabel(Admin);
        DeleteArticleUpdate->setObjectName("DeleteArticleUpdate");
        DeleteArticleUpdate->setGeometry(QRect(260, 90, 58, 16));
        DisplayRatingUpdate = new QLabel(Admin);
        DisplayRatingUpdate->setObjectName("DisplayRatingUpdate");
        DisplayRatingUpdate->setGeometry(QRect(280, 180, 58, 16));
        SaveArticleUpdate = new QLabel(Admin);
        SaveArticleUpdate->setObjectName("SaveArticleUpdate");
        SaveArticleUpdate->setGeometry(QRect(40, 250, 58, 16));
        SaveAdminUpdate = new QLabel(Admin);
        SaveAdminUpdate->setObjectName("SaveAdminUpdate");
        SaveAdminUpdate->setGeometry(QRect(200, 250, 58, 16));
        AddCategorylineEdit = new QLineEdit(Admin);
        AddCategorylineEdit->setObjectName("AddCategorylineEdit");
        AddCategorylineEdit->setGeometry(QRect(10, 140, 113, 21));
        AddCategoryUpdate = new QLabel(Admin);
        AddCategoryUpdate->setObjectName("AddCategoryUpdate");
        AddCategoryUpdate->setGeometry(QRect(270, 140, 58, 16));

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Form", nullptr));
        CreateAndPublishNewArticle->setText(QCoreApplication::translate("Admin", "create new article", nullptr));
        EditArticle->setText(QCoreApplication::translate("Admin", "Edit Article", nullptr));
        DeleteArticle->setText(QCoreApplication::translate("Admin", "Delete Article", nullptr));
        AddNewCategoryButton->setText(QCoreApplication::translate("Admin", "Add New Category", nullptr));
        DisplayAverageRatinglineEdit->setText(QString());
        DisplayAvergaeRatingButton->setText(QCoreApplication::translate("Admin", "Display Rating", nullptr));
        SaveArticleButton->setText(QCoreApplication::translate("Admin", "Save Article ", nullptr));
        SaveAdminButton->setText(QCoreApplication::translate("Admin", "Save Admin", nullptr));
        DeleteArticleUpdate->setText(QString());
        DisplayRatingUpdate->setText(QString());
        SaveArticleUpdate->setText(QString());
        SaveAdminUpdate->setText(QString());
        AddCategoryUpdate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
