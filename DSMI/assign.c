#include <stdio.h>

// decimal to binary convertion
void decimalToBinary(int n)
{
    int binary[64];
    int i = 0;

    while (n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}
// for decimal to octal
void decimaltoOctal(int n)
{
    int binary[64];
    int i = 0;

    while (n > 0)
    {
        binary[i] = n % 8;
        n = n / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}

int main()
{
    int a;
    printf("Enter Your no :");
    scanf("%d", &a);
    decimalToBinary(a);
    printf("\n");
    decimaltoOctal(a);
}