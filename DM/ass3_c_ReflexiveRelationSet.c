#include <stdio.h>

// Function to check reflexive property
int isReflexive(int A[], int n, int B[], int m) {
    if (n != m) return 0;

    for (int i = 0; i < n; i++) {
        int a = A[i];
        int found = 0;

        // Search for (a,a) in Cartesian product
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++) {
                if (A[p] == a && B[q] == a) {
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) return 0;
    }
    return 1;
}

int main() {
    int n, m;
    int A[10], B[10];
    int Exit = 0;
do
{
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

    if (isReflexive(A, n, B, m))
        printf("\nThe Cartesian product is Reflexive.\n");
    else
        printf("\nThe Cartesian product is NOT Reflexive.\n");
        printf("\nDo you want to exit? (1 for Yes): ");
        scanf("%d", &Exit);
} while (Exit != 1);

    return 0;
}
