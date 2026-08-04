#include <stdio.h>

#define SIZE 10

// Function to check reflexive property
int isReflexive(int relation[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        if (relation[i][i] == 0) return 0;
    }
    return 1;
}

// Function to check symmetric property
int isSymmetric(int relation[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][j] != relation[j][i]) return 0;
        }
    }
    return 1;
}

// Function to check transitive property
int isTransitive(int relation[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (relation[j][k] && !relation[i][k]) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int n;
    int relation[SIZE][SIZE];

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of relation (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &relation[i][j]);
        }
    }

    printf("\nChecking properties of the relation...\n");

    if (isReflexive(relation, n))
        printf("✔ Reflexive\n");
    else
        printf("✘ Not Reflexive\n");

    if (isSymmetric(relation, n))
        printf("✔ Symmetric\n");
    else
        printf("✘ Not Symmetric\n");

    if (isTransitive(relation, n))
        printf("✔ Transitive\n");
    else
        printf("✘ Not Transitive\n");

    return 0;
}
