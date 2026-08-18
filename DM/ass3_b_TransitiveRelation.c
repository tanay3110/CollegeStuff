#include <stdio.h>

int isTransitive(int A[], int n, int B[], int m) {
    // Transitive: if (a,b) and (b,c) exist, then (a,c) must exist
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = A[i];
            int b = B[j];

            // Look for (b,c)
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < m; q++) {
                    if (A[p] == b) {
                        int c = B[q];
                        int found = 0;

                        // Check if (a,c) exists
                        for (int x = 0; x < n; x++) {
                            for (int y = 0; y < m; y++) {
                                if (A[x] == a && B[y] == c) {
                                    found = 1;
                                    break;
                                }
                            }
                            if (found) break;
                        }

                        if (!found) return 0; // Missing (a,c)
                    }
                }
            }
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

    if (isTransitive(A, n, B, m))
        printf("\nThe Cartesian product is Transitive.\n");
    else
        printf("\nThe Cartesian product is NOT Transitive.\n");

    return 0;
}
