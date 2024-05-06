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
using namespace std;
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);
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
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream out(&file);
    for (const auto& pair : adminCredentials) {
        out << pair.first << " " << pair.second;
    }
    file.close();
    return true;
}

bool Login::loadAdminCredentialsFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream in(&file);
    adminCredentials.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2) {
            adminCredentials.insert_or_assign(parts[0], parts[1]);
        }
    }
    file.close();
    return true;
}

bool Login::saveUserCredentials(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream out(&file);
    for (const auto& pair : userCredentials) {
        out << pair.first << " " << pair.second;
    }
    file.close();
    return true;
}

bool Login::loadUserCredentials(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream in(&file);
    userCredentials.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2) {
            userCredentials.insert_or_assign(parts[0], parts[1]);
        }
    }
    file.close();
    return true;
}
