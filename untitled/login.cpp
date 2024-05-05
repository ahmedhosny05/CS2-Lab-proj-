#include "login.h"
#include <iostream>
#include "ui_login.h"
#include <sstream>
#include "Admin.h"
#include "user.h"
#include "fstream"
#include "string"
using namespace std;
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_OnLoginButton_clicked()
{
    loadAdminCredentialsFromFile("admin_credentials");
    loadUserCredentials("user_credentials");
    QString passwordss = ui->PasswordlineEdit->text();
    QString usernamess = ui->UsernameLineEdit->text();
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
        User* user = new User();
        user->show();
        hide();
    }
}

bool Login::adminLogin(const QString& username, const QString& password)
{
    auto it = adminCredentials.find(username);
    if (it != adminCredentials.end() && it->second == password) {
        return true;
    }
    return false;
}
bool Login::userLogin(const QString& username, const QString& password) {
    auto it = userCredentials.find(username);
    if (it != userCredentials.end() && it->second == password) {
        return true;
    }
    else {
        return false;
    }
}
bool Login::saveAdminCredentialsToFile(const QString& filename) {
    string filenameStd = filename.toStdString();
    ofstream file(filenameStd);
    if (file.is_open()) {
        for (const auto& pair : adminCredentials) {
            file << pair.first.toStdString() << " " << pair.second.toStdString() << endl;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::loadAdminCredentialsFromFile(const QString& filename) {
    string filenameStd = filename.toStdString();
    ifstream file(filenameStd);
    if (file.is_open()) {
        adminCredentials.clear();
        string username, password;
        while (file >> username >> password) {
            adminCredentials.insert(make_pair(QString::fromStdString(username), QString::fromStdString(password)));
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::saveArticlesToFile(const QString& filename) {
    string filenameStd = filename.toStdString();
    ofstream file(filenameStd);
    if (file.is_open()) {
        for (const auto& article : articles) {
            file << article.title.toStdString() << endl;
            file << article.description.toStdString() << endl;
            file << article.date.toStdString() << endl;
            file << article.rating << endl;
            file << article.category.toStdString() << endl;
            file << "=====" << endl;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::loadArticlesFromFile(const QString& filename) {
    string filenameStd = filename.toStdString();
    ifstream file(filenameStd);
    if (file.is_open()) {
        articles.clear();
        string line;
        Article article;

        while (getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            if (line == "=====") {
                articles.push_back(article);
                article = Article();
            }
            else {
                if (article.title.isEmpty()) {
                    article.title.toStdString() = line;
                }
                else if (article.description.isEmpty()) {
                    article.description.toStdString() = line;
                }
                else if (article.date.isEmpty()) {
                    article.date.toStdString() = line;
                }
                else if (article.rating == 0) {
                    article.rating = stoi(line);
                }
                else if (article.category.isEmpty()) {
                    article.category.toStdString() = line;
                }
            }
        }

        file.close();
        return true;
    }
    else {
        return false;
    }
}
bool Login::loadUserCredentials(const QString& filename) {
    string filenameStd = filename.toStdString();
    ifstream file(filenameStd);
    if (file.is_open()) {
        userCredentials.clear();
        string username, password;
        while (file >> username >> password) {
            userCredentials.insert(make_pair(QString::fromStdString(username), QString::fromStdString(password)));
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::saveUserCredentials(const QString& filename) {
    string filenameStd = filename.toStdString();
    ifstream file(filenameStd);
    if (file.is_open()) {
        userCredentials.clear();
        for (const auto& pairs : userCredentials) {
            file << pairs.first.toStdString() << " " << pairs.second.toStdString() << endl;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}
