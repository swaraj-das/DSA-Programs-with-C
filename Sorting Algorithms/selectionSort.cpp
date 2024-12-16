#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++){
        int smallest = i; 
        for (int j = i + 1; j < n; j++) {  
            if (arr[smallest] > arr[j]) {
                smallest = j;  
            }
        }
        swap(arr[i], arr[smallest]);
    }
}

void printArray(int arr[], int n) {
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, arr[10];
    cout << "Enter the Array Size <= 10: ";
    cin >> n;
    if (n > 10 || n <= 0) {
        cout << "Invalid size. Please enter a size between 1 and 10." << endl;
        return 1;
    }
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cout << "-> ";
        cin >> arr[i];
    }
    SelectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
