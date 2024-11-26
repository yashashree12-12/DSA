// A. Consider a friend’s network on face book social web site. Model it as a graph to
// represent each node as a user and a link to represent the friend relationship between
// them. Store data such as date of birth, number of comments for each user.
// 1. Find who is having maximum friends
// 2. Find who has post maximum and minimum comments
// 3. Find users having birthday in this month
// Hint: (Use adjacency list representation and perform DFS and BFS traversals).

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <ctime>

using namespace std;

struct User {
    string name;
    string dob;  // Date of Birth in DD-MM-YYYY format
    int comments;  // Number of comments posted by the user
};

class SocialNetwork {
    unordered_map<string, User> users;  // Map of username to User data
    unordered_map<string, vector<string>> adjacencyList;  // Adjacency list for friendships

public:
    void addUser(const string& name, const string& dob, int comments) {
        if (users.find(name) == users.end()) {
            users[name] = {name, dob, comments};
            adjacencyList[name] = {};
            cout << "User " << name << " added successfully.\n";
        } else {
            cout << "User " << name << " already exists.\n";
        }
    }

    void addFriendship(const string& user1, const string& user2) {
        if (users.find(user1) != users.end() && users.find(user2) != users.end()) {
            adjacencyList[user1].push_back(user2);
            adjacencyList[user2].push_back(user1);
            cout << "Friendship added between " << user1 << " and " << user2 << ".\n";
        } else {
            cout << "One or both users do not exist.\n";
        }
    }

    void findMaxFriends() const {
        string maxUser;
        int maxFriends = -1;

        for (const auto& pair : adjacencyList) {
            int friendCount = pair.second.size();
            if (friendCount > maxFriends) {
                maxFriends = friendCount;
                maxUser = pair.first;
            }
        }

        cout << "User with maximum friends: " << maxUser << " with " << maxFriends << " friends.\n";
    }

    void findMinMaxComments() const {
        string maxUser, minUser;
        int maxComments = INT_MIN, minComments = INT_MAX;

        for (const auto& pair : users) {
            int comments = pair.second.comments;
            if (comments > maxComments) {
                maxComments = comments;
                maxUser = pair.first;
            }
            if (comments < minComments) {
                minComments = comments;
                minUser = pair.first;
            }
        }

        cout << "User with maximum comments: " << maxUser << " (" << maxComments << " comments).\n";
        cout << "User with minimum comments: " << minUser << " (" << minComments << " comments).\n";
    }

    void findBirthdaysInMonth(int month) const {
        cout << "Users with birthdays in month " << month << ": ";
        for (const auto& pair : users) {
            const string& dob = pair.second.dob;
            int userMonth = stoi(dob.substr(3, 2));  // Extract month from DOB
            if (userMonth == month) {
                cout << pair.first << " ";
            }
        }
        cout << endl;
    }

    void DFS(const string& startUser, unordered_map<string, bool>& visited) const {
        visited[startUser] = true;
        cout << startUser << " ";

        for (const string& friendName : adjacencyList.at(startUser)) {
            if (!visited[friendName]) {
                DFS(friendName, visited);
            }
        }
    }

    void BFS(const string& startUser) const {
        unordered_map<string, bool> visited;
        queue<string> q;

        q.push(startUser);
        visited[startUser] = true;

        while (!q.empty()) {
            string currentUser = q.front();
            q.pop();
            cout << currentUser << " ";

            for (const string& friendName : adjacencyList.at(currentUser)) {
                if (!visited[friendName]) {
                    visited[friendName] = true;
                    q.push(friendName);
                }
            }
        }
        cout << endl;
    }
};

int getCurrentMonth() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return localTime->tm_mon + 1;
}

int main() {
    SocialNetwork network;

    // Adding users
    network.addUser("Alice", "15-11-1995", 30);
    network.addUser("Bob", "20-11-1990", 10);
    network.addUser("Charlie", "10-05-1992", 50);
    network.addUser("Daisy", "25-11-2000", 5);

    // Adding friendships
    network.addFriendship("Alice", "Bob");
    network.addFriendship("Alice", "Charlie");
    network.addFriendship("Bob", "Daisy");

    // Find user with maximum friends
    network.findMaxFriends();

    // Find user with maximum and minimum comments
    network.findMinMaxComments();

    // Find users with birthdays in the current month
    int currentMonth = getCurrentMonth();
    network.findBirthdaysInMonth(currentMonth);

    // DFS Traversal
    cout << "DFS starting from Alice: ";
    unordered_map<string, bool> visited;
    network.DFS("Alice", visited);
    cout << endl;

    // BFS Traversal
    cout << "BFS starting from Alice: ";
    network.BFS("Alice");

    return 0;
}

