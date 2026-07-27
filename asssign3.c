#include <stdio.h>

int octalToDecimal(int octal)
{
    int decimal = 0;
    int base = 1;
    int rem;

    while (octal > 0)
    {
        rem = octal % 10;
        decimal += rem* base;
        base *= 8;
        octal /= 10;
    }
    printf("%d", decimal);
    return decimal;
}
int main()
{
    int a;
    printf("Enter Your Octal Number>>");
    scanf("%d", &a);
    octalToDecimal(a);

    return 0;
}