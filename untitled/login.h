#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <map>
#include <vector>
#include <string>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    // Reason: The map<string, string> container is ideal for storing admin credentials (username -> password) because it provides efficient lookup based on the username (key). This allows quick verification of admin credentials during login (adminLogin method) with a time complexity of O(log n) for lookups. also maps don't allow duplicates so it would vbe excellent in this case
    map<string, string> adminCredentials;
    // : The vector<Article> container is suitable for storing articles because it allows dynamic resizing and efficient traversal. This makes it easy to add, edit, and delete articles based on index, which is commonly required in news management systems. and it is probable to have duplicates
    vector<Article> articles;
    // same as admin credentials
    map<string, vector<Article>> categoryMap;

    map<string, string> userCredentials; // Store user credentials
    vector<User> users;
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool adminLogin(const string& username, const string& password);
    bool userLogin(const string& username, const string& password);
    bool saveAdminCredentialsToFile(const string& filename);
    bool loadAdminCredentialsFromFile(const string& filename);
    bool saveArticlesToFile(const string& filename);
    bool loadArticlesFromFile(const string& filename);
    bool loadUserCredentials(const string& filename);
    bool saveUserCredentials(const string& filename);
private slots:
    void on_OnLoginButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
