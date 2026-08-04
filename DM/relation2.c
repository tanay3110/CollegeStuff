#include <stdio.h>

int Symmetric(int relation[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (relation[i][j] != relation[j][i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n, relation[10][10];
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter matrix of relation %d x %d:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &relation[i][j]);
        }
    }
    if (Symmetric(relation, n))
        printf("Symmetric\n");
    else
        printf("Not Symmetric\n");

    return 0;
}