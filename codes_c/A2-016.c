#include <stdio.h>
#include <string.h>

int main()
{
    char wl, ul;
    char wn[6], un[6];
    if (scanf(" %c %5s", &wl, wn) != 2)
        return 0;
    if (scanf(" %c %5s", &ul, un) != 2)
        return 0;
    int prize = 0;
    if (wl == ul && strcmp(wn, un) == 0)
        prize = 1000000;
    else if (strcmp(wn, un) == 0)
        prize = 100000;
    else if (wl == ul)
    {
        int len = strlen(wn);
        if (len >= 3 && strcmp(wn + len - 3, un + len - 3) == 0)
            prize = 2000;
        else if (len >= 2 && strcmp(wn + len - 2, un + len - 2) == 0)
            prize = 1000;
        else
            prize = 20;
    }
    else
    {
        int len = strlen(wn);
        if (len >= 3 && strcmp(wn + len - 3, un + len - 3) == 0)
            prize = 200;
        else if (len >= 2 && strcmp(wn + len - 2, un + len - 2) == 0)
            prize = 100;
        else
            prize = 0;
    }
    printf("%d\n", prize);
    return 0;
}
