#ifndef USERS_H
#define USERS_H
#include <QString>
class Users
{
public:
 Users(QString uname, QString pwd, bool admin);
    QString username;
    QString password;
    bool isAdmin;
};

#endif // USERS_H
