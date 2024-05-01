#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;


struct Article
{
    string title;
    string description;
    string date;
    int rating;
    string category;
};

class NewsPortal {
private:
    // Reason: The map<string, string> container is ideal for storing admin credentials (username -> password) because it provides efficient lookup based on the username (key). This allows quick verification of admin credentials during login (adminLogin method) with a time complexity of O(log n) for lookups. also maps don't allow duplicates so it would vbe excellent in this case
    map<string, string> adminCredentials;
    // : The vector<Article> container is suitable for storing articles because it allows dynamic resizing and efficient traversal. This makes it easy to add, edit, and delete articles based on index, which is commonly required in news management systems. and it is probable to have duplicates
    vector<Article> articles;
    // same as admin credentials
    map<string, vector<Article>> categoryMap;

public:
    bool adminLogin(const string& username, const string& password) {
        auto it = adminCredentials.find(username);
        if (it != adminCredentials.end() && it->second == password) {
            return true;
        }
        return false;
    }
    void adminSignup(const string& username, const string& password) {
       
        if (adminCredentials.find(username) != adminCredentials.end()) {
            cout << "Username already exists. Please choose a different username.\n";
            return;
        }

        adminCredentials[username] = password;
        cout << "Admin account created successfully!\n";
    }

    void createArticle(const Article& article) {
        articles.push_back(article);
        categoryMap[article.category].push_back(article);
    }

    void editArticle(int index, const Article& newArticle) {
        if (index >= 0 && index < articles.size()) {
            articles[index] = newArticle;
        }
    }

    void deleteArticle(int index) {
        if (index >= 0 && index < articles.size()) {
            articles.erase(articles.begin() + index);
        }
    }

    void addCategory(const string& category) {
        if (categoryMap.find(category) == categoryMap.end()) {
            categoryMap[category] = vector<Article>();
        }
    }

    bool saveAdminCredentialsToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& pair : adminCredentials) {
                file << pair.first << " " << pair.second << endl;
            }
            file.close();
            return true;
        }
        else {
            cout << "Error: Unable to open file for writing." << endl;
            return false;
        }
    }

    bool loadAdminCredentialsFromFile(const string& filename) {
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
            cout << "Error: Unable to open file for reading." << endl;
            return false;
        }
    }

    void saveArticlesToFile(const string& filename) {
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
        }
        else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void loadArticlesFromFile(const string& filename) {
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
        }
        else {
            cout << "Error: Unable to open file '" << filename << "' for reading." << endl;
        }
    }
};

int main() {
    NewsPortal portal;

    // Attempt to load admin credentials from file
    if (!portal.loadAdminCredentialsFromFile("admin_credentials.txt")) {
        cerr << "Failed to load admin credentials from file." << endl;
        return 1; // Exit with error status
    }

    string username, password;
    cout << "Enter username then password for admin: ";
    cin >> username >> password;

    // Check if admin login is successful
    if (portal.adminLogin(username, password)) {
        cout << "Admin login successful!\n";

        // Example: Create and manage articles
        Article newArticle = { "Title", "Description", "2024-04-27", 5, "Sports" };
        portal.createArticle(newArticle);

        portal.saveArticlesToFile("articles.txt");

        Article updatedArticle = { "Updated Title", "Updated Description", "2024-04-28", 4, "Sports" };
        portal.editArticle(0, updatedArticle);

        portal.deleteArticle(0);

        portal.addCategory("Health");

        // Save admin credentials (in case of any changes)
        portal.saveAdminCredentialsToFile("admin_credentials.txt");
    }
    else {
        cout << "Admin login failed!\n";
        cout << "Would you like to sign up as a new admin? (yes/no): ";
        string choice;
        cin >> choice;

        if (choice == "yes")
        {
            // Prompt for username and password for signup
            cout << "Enter new username: ";
            string newUsername, newPassword;
            cin >> newUsername;
            cout << "Enter new password: ";
            cin >> newPassword;

            // Perform admin signup
            portal.adminSignup(newUsername, newPassword);

            // Save updated admin credentials to file
            portal.saveAdminCredentialsToFile("admin_credentials.txt");
        }
    }

    return 0;
}

