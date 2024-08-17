#include <stdio.h>

void insertElement(int arr[], int *n, int element, int position) {
    // Check if the position is valid
    if (position > *n || position < 0) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[position] = element;

    // Increase the size of the array
    (*n)++;
}

void deleteElement(int arr[], int *n, int position) {
    // Check if the position is valid
    if (position >= *n || position < 0) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*n)--;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, element, position;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[100]; // Define a sufficiently large array to accommodate the insertion

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("-> ");
        scanf("%d", &arr[i]);
    }

    printf("Insert element: ");
    scanf("%d", &element);

    printf("The position: ");
    scanf("%d", &position);

    printf("Original array: ");
    printArray(arr, n);

    insertElement(arr, &n, element, position);

    printf("Array after insertion: ");
    printArray(arr, n);

    return 0;
}
