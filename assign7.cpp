// Consider a telephone book database of N clients. Make use of a hash table implementation to quickly
// look up client‘s telephone number. Make use of two collision handling techniques and compare them
// using number of comparisons required to find a set of telephone numbers

#include <iostream>
#include <string>
#include <list>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

int hashFunction(const string& name) {
    int hash = 0;
    for (char ch : name) {
        hash = (hash + ch) % TABLE_SIZE;
    }
    return hash;
}

class ChainingHashTable {
    list<pair<string, string>> table[TABLE_SIZE];

public:
    void insert(const string& name, const string& phone) {
        int index = hashFunction(name);
        table[index].push_back({name, phone});
    }

    int search(const string& name) {
        int index = hashFunction(name);
        int comparisons = 0;
        for (const auto& entry : table[index]) {
            comparisons++;
            if (entry.first == name) {
                cout << "Found " << name << " -> " << entry.second << endl;
                return comparisons;
            }
        }
        cout << name << " not found.\n";
        return comparisons;
    }
};

class LinearProbingHashTable {
    string names[TABLE_SIZE];
    string phones[TABLE_SIZE];

public:
    LinearProbingHashTable() {
        memset(names, 0, sizeof(names));
    }

    void insert(const string& name, const string& phone) {
        int index = hashFunction(name);
        int originalIndex = index;

        while (!names[index].empty()) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                cout << "Hash table is full.\n";
                return;
            }
        }
        names[index] = name;
        phones[index] = phone;
    }

    int search(const string& name) {
        int index = hashFunction(name);
        int originalIndex = index;
        int comparisons = 0;

        while (!names[index].empty()) {
            comparisons++;
            if (names[index] == name) {
                cout << "Found " << name << " -> " << phones[index] << endl;
                return comparisons;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break;
        }
        cout << name << " not found.\n";
        return comparisons;
    }
};

int main() {
    ChainingHashTable chainingTable;
    LinearProbingHashTable linearTable;

    int n;
    cout << "Enter the number of entries to insert: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name, phone;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phone;

        chainingTable.insert(name, phone);
        linearTable.insert(name, phone);
    }

    cout << "\n--- Chaining Hash Table ---\n";
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;
    int comparisons1 = chainingTable.search(searchName);
    
    cout << "Enter name to search: ";
    cin >> searchName;
    int comparisons2 = chainingTable.search(searchName);
    
    cout << "Enter name to search: ";
    cin >> searchName;
    int comparisons3 = chainingTable.search(searchName);

    cout << "Chaining Comparisons: " << comparisons1 + comparisons2 + comparisons3 << endl;

    cout << "\n--- Linear Probing Hash Table ---\n";
    cout << "Enter name to search: ";
    cin >> searchName;
    comparisons1 = linearTable.search(searchName);
    
    cout << "Enter name to search: ";
    cin >> searchName;
    comparisons2 = linearTable.search(searchName);
    
    cout << "Enter name to search: ";
    cin >> searchName;
    comparisons3 = linearTable.search(searchName);

    cout << "Linear Probing Comparisons: " << comparisons1 + comparisons2 + comparisons3 << endl;

    return 0;
}
