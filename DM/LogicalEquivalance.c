#include <stdio.h>
#include <stdbool.h>

bool expression1(bool A, bool B)
{
    return !(A || B);
}

bool expression2(bool A, bool B)
{
    return !A && !B;
}

int main()
{
    bool is_equivalent = true;

    // Print table header
    printf(" A  B  !(A || B)  !A && !B  Match?\n");

    for (int A = 0; A <= 1; A++)
    {
        for (int B = 0; B <= 1; B++)
        {
            bool result1 = expression1(A, B);
            bool result2 = expression2(A, B);

            bool match = (result1 == result2);

            if (!match)
            {
                is_equivalent = false;
            }

            printf(" %d  %d      %d          %d       %s\n",
                   A, B, result1, result2, match ? "Yes" : "No ");
        }
    }

    if (is_equivalent)
    {
        printf("Verdict: The expressions are LOGICALLY EQUIVALENT.\n");
    }
    else
    {
        printf("Verdict: The expressions are NOT LOGICALLY EQUIVALENT.\n");
    }

    return 0;
}
