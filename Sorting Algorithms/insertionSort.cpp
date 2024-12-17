#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && curr < arr[prev]){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void printArray(int arr[], int n) {
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
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
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}