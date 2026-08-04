#include <stdio.h>

int isSymmetric(int A[], int n, int B[], int m) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = A[i];
            int b = B[j];
            int found = 0;

  
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < m; q++) {
                    if (A[p] == b && B[q] == a) {
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    int A[10], B[10];

    printf("Enter size of set A: ");
    scanf("%d", &n);
    printf("Enter elements of set A:\n");
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    printf("Enter size of set B: ");
    scanf("%d", &m);
    printf("Enter elements of set B:\n");
    for (int j = 0; j < m; j++) scanf("%d", &B[j]);


    printf("\nCartesian Product A x B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("(%d,%d) ", A[i], B[j]);
        }
        printf("\n");
    }

    if (isSymmetric(A, n, B, m))
        printf("\nThe Cartesian product is Symmetric.\n");
    else
        printf("\nThe Cartesian product is NOT Symmetric.\n");

    return 0;
}
