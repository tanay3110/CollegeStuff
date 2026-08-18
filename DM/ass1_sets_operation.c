#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter size of 1st set: ");
    scanf("%d", &n);
    int set1[n];
    printf("Enter 1st set elements: ");
    for (int i = 0; i < n; i++)
    {   scanf("%d", &set1[i]);  }
    printf("Enter size of 2nd set: ");
    scanf("%d", &m);
    int set2[m];
    printf("Enter 2nd set elements: ");
    for (int i = 0; i < m; i++)
    {   scanf("%d", &set2[i]);  }


    int z = 0;
    while (z != 4)
    {   printf("1 Union\n");
        printf("2 Intersection\n");
        printf("3 Difference\n");
        printf("4 Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &z);

        if (z == 1)
        {   int set3[100];
            int k = 0;

            for (int i = 0; i < n; i++)
            {   set3[k++] = set1[i];}

            for (int i = 0; i < m; i++)
            {   int f = 0;

                for (int j = 0; j < n; j++)
                {
                    if (set2[i] == set1[j])
                    {    f = 1;
                        break;}}

                if (!f)
                {
                    set3[k++] = set2[i];
                }
            }

            printf("Union of sets   \n");
            for (int i = 0; i < k; i++)
            {
                printf("%d ", set3[i]);
            }
            printf("\n");
        }

        else if (z == 2)
        {
            printf("Intersection\n");

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (set1[i] == set2[j])
                    {
                        printf("%d ", set1[i]);
                        break;
                    }
                }
            }
            printf("\n");
        }

        else if (z == 3)
        {
            printf("Difference\n");

            for (int i = 0; i < n; i++)
            {
                int f = 0;

                for (int j = 0; j < m; j++)
                {
                    if (set1[i] == set2[j])
                    {
                        f = 1;
                        break;
                    }
                }

                if (!f)
                {printf("%d ", set1[i]);}
            }
            printf("\n");}
        else if (z == 4)
        {printf("bye\n");}}
return 0;}
 