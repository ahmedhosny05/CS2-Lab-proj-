#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;


struct Article
{
    string title;
    string description;
    string date;
    int rating;
    string category;
};

// User Class
class User 
{ 
    public:

     string username;
     string password;
     bool isAdmin;
// Constructor
    User(string uname, string pwd, bool admin) : username(uname), password(pwd), isAdmin(admin) {}
};
class NewsPortal {
private:
    // Reason: The map<string, string> container is ideal for storing admin credentials (username -> password) because it provides efficient lookup based on the username (key). This allows quick verification of admin credentials during login (adminLogin method) with a time complexity of O(log n) for lookups. also maps don't allow duplicates so it would vbe excellent in this case
    map<string, string> adminCredentials;
    // : The vector<Article> container is suitable for storing articles because it allows dynamic resizing and efficient traversal. This makes it easy to add, edit, and delete articles based on index, which is commonly required in news management systems. and it is probable to have duplicates
    vector<Article> articles;
    // same as admin credentials
    map<string, vector<Article>> categoryMap;

    map<string, string> userCredentials; // Store user credentials
    vector<User> users; 

public:
    bool adminLogin(const string& username, const string& password)
     {
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

    void addNewCategory(const string& newCategory) {
        if (categoryMap.find(newCategory) == categoryMap.end()) {
            categoryMap[newCategory] = vector<Article>();
            cout << "New category '" << newCategory << "' added successfully!\n";
        } else {
            cout << "Category '" << newCategory << "' already exists.\n";
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


    double getaveragerating(const  string& title )
    {
        double sum = 0.0;
        int count = 0;

        for (const auto& article : articles)
         {
            if (article.title == title)
            {
                sum += article.rating;
                count++;
            }
        }

        if (count > 0)
        {
            return sum / count;
        } else
        {
            return 0.0; // Return 0 if no articles with the given title are found
        }
    }

// Function to check if a user is registered
    bool isUserRegistered(const string& username) {
        return userCredentials.find(username) != userCredentials.end();
    }

     void userRegistration(const string& username, const string& password, bool isAdmin) {
        if (isUserRegistered(username)) {
            cout << "Username already exists. Please choose a different username.\n";
            return;
        } 
        // Add user to credentials map
        userCredentials[username] = password;

        // Create a User object and add it to the users vector
        User newUser(username, password, isAdmin);
        users.push_back(newUser);

        cout << "User registered successfully!\n";
    }


    bool userLogin(const string& username, const string& password) {
        auto it = userCredentials.find(username);
        if (it != userCredentials.end() && it->second == password) {
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Invalid username or password. Please try again.\n";
            return false;
        }
    } 


    void searchNews(const string& keyword) {
    bool found = false;
    for (const auto& article : articles) {
        // Check if the keyword exists in the title, description, or category of the article
        if (article.title.find(keyword) != string::npos ||
            article.description.find(keyword) != string::npos ||
            article.category.find(keyword) != string::npos) {
            // Print the article details
            cout << "Title: " << article.title << endl;
            cout << "Description: " << article.description << endl;
            cout << "Date: " << article.date << endl;
            cout << "Rating: " << article.rating << endl;
            cout << "Category: " << article.category << endl;
            cout << "-----------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No articles found matching the keyword \"" << keyword << "\"." << endl;
    }
}

// Function to display the latest news articles
void displayLatestNews() {
    cout << "Latest News Articles:\n";
    for (int i = articles.size() - 1; i >= 0; --i) {
        // Display articles starting from the latest
        cout << "Title: " << articles[i].title << endl;
        cout << "Description: " << articles[i].description << endl;
        cout << "Date: " << articles[i].date << endl;
        cout << "Rating: " << articles[i].rating << endl;
        cout << "Category: " << articles[i].category << endl;
        cout << "-----------------------" << endl;
    }
}  

// Function to view news articles based on specific categories
void viewNewsByCategory(const string& category) {
    cout << "News Articles in Category \"" << category << "\":\n";
    if (categoryMap.find(category) != categoryMap.end()) {
        for (const auto& article : categoryMap[category]) {
            // Display article details
            cout << "Title: " << article.title << endl;
            cout << "Description: " << article.description << endl;
            cout << "Date: " << article.date << endl;
            cout << "Rating: " << article.rating << endl;
            cout << "Category: " << article.category << endl;
            cout << "-----------------------" << endl;
        }
    } else {
        cout << "No news articles found in category \"" << category << "\"." << endl;
    }
}

// Function to search for an article by title
vector<Article>::iterator findArticleByTitle(const string& title) {
    for (auto it = articles.begin(); it != articles.end(); ++it) {
        if (it->title == title) {
            return it;
        }
    }
    return articles.end(); // Return iterator pointing to the end if article not found
}

// Function to allow users to rate news articles
void rateNewsArticle(const string& username, const string& articleTitle, int rating) {
    // Search for the article with the given title
    auto it = findArticleByTitle(articleTitle);
    if (it != articles.end()) {
        // Update the rating of the article
        it->rating = rating;
        cout << "User \"" << username << "\" rated article \"" << articleTitle << "\" with rating " << rating << ".\n";
    } else {
        cout << "Article with title \"" << articleTitle << "\" not found.\n";
    }
}
}; 


/*int main()
{
    NewsPortal newsPortal;

    // Load admin credentials from file
    if (!newsPortal.loadAdminCredentialsFromFile("admin_credentials.txt")) {
        cout << "Error loading admin credentials. Exiting...\n";
        return 0;
    }

    

    string userType;
    cout << "Are you an admin or a user? Type 'admin' or 'user': ";
    cin >> userType;

    string username, password;

    // Prompt the user for username and password
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool loggedIn = false;

    if (userType == "admin") {
        // Check if admin exists in the loaded credentials
        if (!newsPortal.adminLogin(username, password)) {
            cout << "Admin login failed. Please check your credentials.\n";
            return 0;
        } else {
            cout << "Admin login successful!\n";
            loggedIn = true;
        }
    } else if (userType == "user") {
        // Check if user exists in the loaded credentials
        if (!newsPortal.userLogin(username, password)) {
            cout << "User login failed. Please check your credentials.\n";
            return 0;
        } else {
            cout << "User login successful!\n";
            loggedIn = true;
        }
    } else {
        cout << "Invalid user type. Please type 'admin' or 'user'.\n";
        return 0;
    }

    if (loggedIn) {
        cout << "Welcome to the News Management System!\n";

        // Implement the functionalities based on the requirements

        // I. Allow users to view news articles
        newsPortal.displayLatestNews();

        // II. Implement news rating functionality
        string articleTitle;
        int rating;
        cout << "Enter the title of the article you want to rate: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, articleTitle);
        cout << "Enter your rating (1 to 5): ";
        cin >> rating;
        if (rating < 1 || rating > 5) {
            cout << "Invalid rating. Rating must be between 1 and 5.\n";
        } else {
            newsPortal.rateNewsArticle(username, articleTitle, rating);
        }

        // III. Hide news articles with ratings below 2
        cout << "Hidden articles with ratings below 2:\n";
        //for (const auto& article : newsPortal.articles) {
           // if (article.rating < 2) {
               // cout << "Title: " << article.title << endl;
           // }
        //}

        // IV. Enable users to filter news articles by category
        string category;
        cout << "Enter the category you want to filter: ";
        cin >> category;
        newsPortal.viewNewsByCategory(category);

        // V. Provide users with the option to choose their preferred news categories
        // Implement your code here

        // VI. Validate users' login credentials and determine user roles
        // Already implemented during login
    }

    return 0;
}*/
