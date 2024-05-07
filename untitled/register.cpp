#include "register.h"
#include "ui_register.h"
#include "admin.h"
#include "users.h"
#include "user.h"
Register::Register(Login* login, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    this->login= login;
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    if (!ui->UsernamelineEdit->text().isEmpty() && !ui->PasswordLineEdit->text().isEmpty()) {
        QString username, password;
        username = ui->UsernamelineEdit->text();
        password = ui->PasswordLineEdit->text();
        if (password=="1234") {
            if (!(login->adminCredentials.find(username) != login->adminCredentials.end())) {
                login->adminCredentials[username] = password;
                Admin* admin = new Admin(login);
                admin->show();
                login->saveAdminCredentialsToFile("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/admin_credentials.txt");
                hide();
            }
        }
        else {
            if (!(login->userCredentials.find(username) != login->userCredentials.end())) {
                login->userCredentials[username] = password;
                Users newUser(username,password,false);
                login->users.push_back(newUser);
                User* user = new User(login);
                user->show();
                login->saveUserCredentials("/Users/daliakadry/Documents/cs2/CS2-Lab-proj-/untitled/user_credentials.txt");
                hide();
            }

        }
    }
}

