#include <stdio.h>
int main()
{
    int y, cc, tax;
    scanf("%d%d", &y, &cc);
    if (y <= 1990)
    {
        if (cc <= 1500)
            tax = 1250;
        else if (cc <= 2000)
            tax = 1400;
        else
            tax = 2000;
    }
    else if (y <= 1999)
    {
        if (cc <= 1500)
            tax = 1100;
        else if (cc <= 2000)
            tax = 1300;
        else
            tax = 1700;
    }
    else
    {
        if (cc <= 1500)
            tax = 1000;
        else if (cc <= 2000)
            tax = 1200;
        else
            tax = 1500;
    }
    printf("%d\n", tax);
    return 0;
}
