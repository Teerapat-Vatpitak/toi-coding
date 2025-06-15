#include <stdio.h>

int main()
{
    char b, t;
    int g, s, v;
    if (scanf(" %c %d", &b, &g) != 2)
        return 0;
    if (scanf(" %c %d %d", &t, &s, &v) != 3)
        return 0;
    int eb = 0, et = 0;
    if (b == 'H')
        eb = 5;
    else if (b == 'O')
        eb = 3;
    else if (b == 'J')
        eb = 2;
    if (t == 'R')
    {
        if (s == 1)
            et = 12;
        else if (s == 2)
            et = 18;
        else
            et = 25;
    }
    else if (t == 'T')
    {
        if (s == 1)
            et = 15;
        else if (s == 2)
            et = 20;
        else
            et = 30;
    }
    else if (t == 'M')
    {
        if (s == 1)
            et = 10;
        else if (s == 2)
            et = 15;
        else
            et = 20;
    }
    int total = eb * g + et * v;
    printf("%d\n", total);
    return 0;
}
