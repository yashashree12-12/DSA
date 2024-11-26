// A. Read the Credits obtained to students in different club activities and sort the credits
// using merge sort.

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;  
    int n2 = right - mid;      

    int* L = new int[n1];  
    int* R = new int[n2]; 

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];


    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    int* credits = new int[n]; 

    cout << "Enter the credits obtained by each student:\n";
    for (int i = 0; i < n; ++i) {
        cin >> credits[i];
    }

    cout << "Credits before sorting: ";
    printArray(credits, n);

    mergeSort(credits, 0, n - 1);

    cout << "Credits after sorting: ";
    printArray(credits, n);


    delete[] credits;

    return 0;
}
