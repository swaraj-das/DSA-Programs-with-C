#include <stdio.h>
#include <stdlib.h>

int deletion(int* ptr, int n, int item) {
    int i, pos = -1;

    // Find the position of the item to be deleted
    for (i = 0; i < n; i++) {
        if (ptr[i] == item) {
            pos = i;
            break;
        }
    }

    // If the item was not found, return the same size
    if (pos == -1) {
        return n;
    }

    // Shift elements to the left to fill the gap
    for (i = pos; i < n - 1; i++) {
        ptr[i] = ptr[i + 1];
    }

    // Return the new size of the array
    return (n - 1);
}

int main() {
    int* ptr;
    int n, i, item;

    printf("Enter the range: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    ptr = (int*)malloc(n * sizeof(int));

    // Input elements
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    printf("Enter the element to delete: ");
    scanf("%d", &item);

    // Perform deletion and get the new size of the array
    n = deletion(ptr, n, item);

    // Print the updated array
    printf("Updated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(ptr);

    return 0;
}
