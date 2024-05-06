#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <map>
#include <vector>
#include <string>
#include "qstring.h"
#include "article.h"
#include "user.h"
#include "users.h"
using namespace std;
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    // Reason: The map<string, string> container is ideal for storing admin credentials (username -> password) because it provides efficient lookup based on the username (key). This allows quick verification of admin credentials during login (adminLogin method) with a time complexity of O(log n) for lookups. also maps don't allow duplicates so it would vbe excellent in this case
    map<QString, QString> adminCredentials;
    // : The vector<Article> container is suitable for storing articles because it allows dynamic resizing and efficient traversal. This makes it easy to add, edit, and delete articles based on index, which is commonly required in news management systems. and it is probable to have duplicates
    vector<Article> articles;
    // same as admin credentials
    map<QString, vector<Article>> categoryMap;

    map<QString, QString> userCredentials; // Store user credentials
    vector<Users> users;
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool adminLogin(const QString& username, const QString& password);
    bool userLogin(const QString& username, const QString& password);
    bool saveAdminCredentialsToFile(const QString& filename);
    bool loadAdminCredentialsFromFile(const QString& filename);
    bool saveArticlesToFile(const QString& filename);
    bool loadArticlesFromFile(const QString& filename);
    bool loadUserCredentials(const QString& filename);
    bool saveUserCredentials(const QString& filename);
private slots:
    void on_OnLoginButton_clicked();

    void on_OnRegsiterButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
