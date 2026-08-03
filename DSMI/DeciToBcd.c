#include <stdio.h>

void decimalToBCD(int num)
{
    printf("BCD: ");
    while (num > 0)
    {
        int digit = num % 10;
        printf("%04d ", digit);
        num /= 10;
    }
    printf("\n");
}

void decimalToExcess3(int num)
{
    printf("Excess-3: ");
    while (num > 0)
    {
        int digit = num % 10;
        int excess3 = digit + 331;
        printf("%04d ", excess3);
        num /= 10;
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    decimalToBCD(num);
    decimalToExcess3(num);

    return 0;
}
