// Read the marks obtained by students of second year in an online examination of
// particular subject. Find out maximum and minimum marks obtained in that subject.
// Use heap data structure. Analyse the algorithm.
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    priority_queue<int> maxHeap;  
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    cout << "Enter the marks obtained by the students:\n";
    for (int i = 0; i < n; ++i) {
        int mark;
        cin >> mark;
        maxHeap.push(mark);  
        minHeap.push(mark);  
    }

    int maxMarks = maxHeap.top();
    int minMarks = minHeap.top(); 

    cout << "Maximum marks obtained: " << maxMarks << endl;
    cout << "Minimum marks obtained: " << minMarks << endl;

    return 0;
}
