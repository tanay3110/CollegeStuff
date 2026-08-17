#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("\nArray size must be positive.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));  // Dynamic allocation
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        int p;
        printf("\nChoose from 1, 2, 3\n");
        printf("Enter 1 for printing the array\n");
        printf("Enter 2 for removing element from array\n");
        printf("Enter 3 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &p);
        printf("you have choosed %d\n", p);

        if (p == 1)
        {
            printf("Your entered Array is:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (p == 2)
        {
            int i;
            printf("Enter index of element to remove: ");
            scanf("%d", &i);

            if (i >= 0 && i < n)
            {
                for (int w = i; w < n - 1; w++)
                {
                    arr[w] = arr[w + 1];
                }
                n--;
            }
            else
            {
                printf("Invalid index!\n");
            }
        }
        else if (p == 3)
        {
            break;
        }
    }

    printf("\nArray after removal:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // Free allocated memory
    return 0;
}