#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (n == 0)
    {
        printf("\nArray is empty.\n");
    }
    else if (n > 0)
    {
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
                printf("YouR entered Array is:\n");
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
    }

    printf("\nArray after removal:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
