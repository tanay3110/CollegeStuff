#include <stdio.h>

struct Mobile
{
    int prize;
    char Name[30];
};

void UpdatePrize(struct Mobile *m)
{
    m->prize = 20000;
};

int main()
{
    struct Mobile m1 = {22000, "IQOO Z9S\n"};
    UpdatePrize(&m1);
    struct Mobile m2 = {17000, "SAMSUNG"};
    printf("%d %s", m1.prize, m1.Name);
    printf("%d %s", m2.prize, m2.Name);
    return 0;
}