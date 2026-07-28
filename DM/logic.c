#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool match;
    printf(" A  B  !(A || B) !A && !B  match \n");

    for (int A = 0; A <= 1; A++)
    {
        for (int B = 0; B <= 1; B++)
        {

            bool exp1 = !(A || B);
            bool exp2 = !A && !B;

            match = (exp1 == exp2);

            printf(" %d  %d      %d   \t  %d\t     %s\n",
                   A, B, exp1, exp2, match ? "Yes" : "No");
        }
    }
    printf("%s", match ? "There Is Logical Equivalance!" : "There is no logical Equivalnce!");
    return 0;
}