// B. Implement quick sort for sorting students credits they received in last 2 years and
// display the names of top 3 students

#include <iostream>
#include <string>
using namespace std;

int partition(int credits[], string names[], int low, int high) {
    int pivot = credits[high];
    int i = low - 1; 

    for (int j = low; j < high; ++j) {
        if (credits[j] >= pivot) {  
            ++i;
            swap(credits[i], credits[j]); 
            swap(names[i], names[j]);   
        }
    }
    swap(credits[i + 1], credits[high]);
    swap(names[i + 1], names[high]);
    return i + 1;
}

void quickSort(int credits[], string names[], int low, int high) {
    if (low < high) {
        int pi = partition(credits, names, low, high);  

        quickSort(credits, names, low, pi - 1);
        quickSort(credits, names, pi + 1, high);
    }
}

void displayTop3(int credits[], string names[], int n) {
    cout << "\nTop 3 Students based on Credits:\n";
    for (int i = 0; i < 3 && i < n; ++i) {
        cout << i + 1 << ". " << names[i] << " - " << credits[i] << " credits\n";
    }
}

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    string* names = new string[n];  
    int* credits = new int[n];  

    cout << "Enter the names and credits obtained by each student:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> names[i];
        cout << "Credits: ";
        cin >> credits[i];
    }

    quickSort(credits, names, 0, n - 1);

    displayTop3(credits, names, n);

    delete[] names;
    delete[] credits;

    return 0;
}
