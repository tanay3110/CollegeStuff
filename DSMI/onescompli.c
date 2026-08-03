#include <stdio.h>

int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1, remainder;
    while (binary > 0)
    {
        remainder = binary % 10;
        decimal += remainder * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}

void decimalToBinary(int decimal)
{
    int binary[64], i = 0;
    while (decimal > 0)
    {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    if (i == 0)
        printf("0");
}

void onesComplementSub(int A, int B)
{
    int decA = binaryToDecimal(A);
    int decB = binaryToDecimal(B);

    int onesCompB = ~decB;
    int result = decA + onesCompB + 1;

    printf("Result Binary: ");
    decimalToBinary(result);
    printf("\n");
    printf("Result Decima): %d\n", result);
    printf("\n");
}

int main()
{
    int num1, num2;
    printf("<<<< Enter in this format (A - B) >>>>\n");
    printf("Enter Binary no. A: ");
    scanf("%d", &num1);
    printf("Enter Binary no. B: ");
    scanf("%d", &num2);

    onesComplementSub(num1, num2);

    return 0;
}
