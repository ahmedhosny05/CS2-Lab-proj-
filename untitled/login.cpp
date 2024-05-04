#include "login.h"
#include <iostream>
#include "ui_login.h"
#include <sstream>
#include "Admin.h"
#include "user.h"
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
    QString passwordss = ui->passwordlabel->text();
    QString usernamess = ui->usernamelabel->text();
    bool found = adminLogin(usernamess,passwordss);
    bool founduser = userLogin(usernamess,passwordss);
    if (!found && !founduser) {
        ui->errorlabel->setVisible(true);
    }
    if (found&&!founduser) {
        Admin *admin = new Admin();
        admin->show();
    }
    if (founduser&&!found || found && founduser) {
        User* user = new User();
        user->show();
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
bool Login::userLogin(const string& username, const string& password) {
    auto it = userCredentials.find(username);
    if (it != userCredentials.end() && it->second == password) {
        return true;
    }
    else {
        return false;
    }
}
bool Login::saveAdminCredentialsToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : adminCredentials) {
            file << pair.first << " " << pair.second << endl;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::loadAdminCredentialsFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        adminCredentials.clear();
        string username, password;
        while (file >> username >> password) {
            adminCredentials[username] = password;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::saveArticlesToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& article : articles) {
            file << article.title << endl;
            file << article.description << endl;
            file << article.date << endl;
            file << article.rating << endl;
            file << article.category << endl;
            file << "=====" << endl;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::loadArticlesFromFile(const string& filename) {
    ifstream file(filename);
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
                if (article.title.empty()) {
                    article.title = line;
                }
                else if (article.description.empty()) {
                    article.description = line;
                }
                else if (article.date.empty()) {
                    article.date = line;
                }
                else if (article.rating == 0) {
                    article.rating = stoi(line);
                }
                else if (article.category.empty()) {
                    article.category = line;
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
bool Login::loadUserCredentials(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        userCredentials.clear();
        string username, password;
        while (file >> username >> password) {
            userCredentials[username] = password;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Login::saveUserCredentials(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        userCredentials.clear();
        string username, password;
        while (file >> username >> password) {
            userCredentials[username] = password;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}
