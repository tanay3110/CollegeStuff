#include <stdio.h>

int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1, rem      ;

    while (binary > 0)
    {
        rem = binary % 10;
        decimal += rem * base;
        base *= 2;
        binary /= 10;
    }
    printf("%d", decimal);

    return decimal;
}
int main()
{
    int a;
    printf("Enter Your Binary number <<for e.g. 1010111>>:");
    scanf("%d", &a);
    binaryToDecimal(a);

    return 0;
}