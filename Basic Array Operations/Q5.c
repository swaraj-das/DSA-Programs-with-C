// 5. Write a C program to add two matrix using pointers.
#include<stdio.h>

void addMatrix(int *a, int *b, int *c, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            *(c + i * n + j) = *(a + i * n + j) + *(b + i * n + j);
        }
    }
}

void printMatrix(int *matrix, int n) {
    printf("Resultant Matrix (A + B):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%3d ", *(matrix + i * n + j*n));
        }
        printf("\n");
    }
}

int main() {
    int n;
    int a[10][10], b[10][10], c[10][10];

    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of the 1st matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of the 2nd matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    addMatrix((int *)a, (int *)b, (int *)c, n);
    printMatrix((int *)c,n);

    return 0;
}
