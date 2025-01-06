#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at node i in a vector of size n
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);       // Move current root to end
        heapify(arr, i, 0);         // Call heapify on the reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
