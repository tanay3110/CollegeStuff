#include <stdio.h>

void Sub(int n,int m)
{
    int binarya[64],binaryb[64],binaryc[64];
    int i = 0,k=0,j=0;

    while (n > 0)
    {
        binarya[i] = n % 2;
        n = n / 2;
        i++;
    }
    while (m > 0)
    {
        binaryb[k] = m % 2;
        m = m / 2;
        k++;}


    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binarya[j]);
    }
}

int main()
{
    int num1;
    printf("<<<<Enter in this format (A-B)>>>>\n");
    printf("Enter Binary no. A: ");
    scanf("%d", &num1);

    int num2;
    printf("Enter Binary no. B: ");
    scanf("%d", &num2);

    Subtraction(num1,num2);

    return 0;
}