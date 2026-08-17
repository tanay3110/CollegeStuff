#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    
    // Allocate dynamic 2D arrays
    int **a = (int **)malloc(m * sizeof(int *));
    int **b = (int **)malloc(m * sizeof(int *));
    int **sum = (int **)malloc(m * sizeof(int *));
    int **product = (int **)malloc(m * sizeof(int *));
    
    for (int i = 0; i < m; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        sum[i] = (int *)malloc(n * sizeof(int));
        product[i] = (int *)malloc(n * sizeof(int));
    }
    // Input matrix A
    printf("\nEnter elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);}}
    printf("\nEnter elements of matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            product[i][j] = a[i][j] * b[i][j];
        }
    }

    printf("\nMatrix Addition Result:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix Multiplication Result (element-wise):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(a[i]);
        free(b[i]);
        free(sum[i]);
        free(product[i]);
    }
    free(a);
    free(b);
    free(sum);
    free(product);

    return 0;
}
