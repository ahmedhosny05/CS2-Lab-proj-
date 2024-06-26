#include "login.h"
#include <iostream>
#include <QMap>
#include <map>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "ui_login.h"
#include <sstream>
#include "Admin.h"
#include "user.h"
#include "fstream"
#include "string"
#include "register.h"
using namespace std;
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    loadAdminCredentialsFromFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/admin_credentials.txt");
    loadUserCredentials("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/user_credentials.txt");
    loadArticlesFromFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/article_credentials.txt");
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);
}

Login::~Login()
{
    delete ui;
}

void Login::on_OnLoginButton_clicked()
{
    QString passwordss = ui->PasswordlineEdit->text();
    QString usernamess = ui->UsernameLineEdit->text();
    if (!passwordss.isEmpty() && !usernamess.isEmpty()) {
    bool found = adminLogin(usernamess,passwordss);
    bool founduser = userLogin(usernamess,passwordss);
    if (!found && !founduser) {
        ui->errorlabel->setVisible(true);
    }
    if (found&&!founduser) {
        Admin *admin = new Admin(this);
        admin->show();
        hide();
    }
    if (founduser&&!found || found && founduser) {
        User* user = new User(this);
        user->show();
        hide();
    }
}
}
bool Login::adminLogin(const QString& username, const QString& password)
{
    loadAdminCredentialsFromFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/admin_credentials.txt");
    auto it = adminCredentials.find(username);
    if (it != adminCredentials.end() && it->second == password) {
        return true;
    }
    return false;
}
bool Login::userLogin(const QString& username, const QString& password) {
    loadUserCredentials("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/user_credentials.txt");
    auto it = userCredentials.find(username);
    if (it != userCredentials.end() && it->second == password) {
        return true;
    }
    else {
        return false;
    }
}

bool Login::saveAdminCredentialsToFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing."));
        return false;
    }
    QTextStream out(&file);
    for (const auto& pair : adminCredentials) {
        out << pair.first << ' ' << pair.second << '\n';
    }
    file.close();
    return true;
}

bool Login::loadAdminCredentialsFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for reading."));
        return false;
    }
    QTextStream in(&file);
    adminCredentials.clear();
    while (!in.atEnd()) {
        QStringList parts = in.readLine().split(' ');
        if (parts.size() == 2) {
            adminCredentials.insert({parts[0], parts[1]});
        }
    }
    file.close();
    return true;
}

bool Login::saveUserCredentials(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing."));
        return false;
    }
    QTextStream out(&file);
    for (const auto& pair : userCredentials) {
        out << pair.first << ' ' << pair.second << '\n';
    }
    file.close();
    return true;
}

bool Login::loadUserCredentials(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for reading."));
        return false;
    }
    QTextStream in(&file);
    userCredentials.clear();
    while (!in.atEnd()) {
        QStringList parts = in.readLine().split(' ');
        if (parts.size() == 2) {
            userCredentials.insert({parts[0], parts[1]});
        }
    }
    file.close();
    return true;
}

bool Login::saveArticlesToFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing."));
        return false;
    }
    QTextStream out(&file);
    for (const auto& article : articles) {
        out << article.title << '\n';
        out << article.description << '\n';
        out << article.date << '\n';
        out << article.category << '\n';
        out << article.rating << '\n';
        out << "=====\n";
    }

    file.close();
    return true;
}

void Login::on_OnRegsiterButton_clicked()
{
    Register* reg = new Register(this);
    reg->show();
    hide();
}
bool Login::loadArticlesFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for reading."));
        return false;
    }

    QTextStream in(&file);
    articles.clear();
    Article article;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty()) {
            continue;
        }

        if (line == "=====") {
            articles.push_back(article);
            article = Article();
        }
        else {
            if (article.title.isEmpty()) {
                article.title = line;
            }
            else if (article.description.isEmpty()) {
                article.description = line;
            }
            else if (article.date.isEmpty()) {
                article.date = line;
            }
            else if (article.rating == 0) {
                article.rating = line.toInt();
            }
            else if (article.category.isEmpty()) {
                article.category = line;
            }

        }
    }

    file.close();
    return true;
}

