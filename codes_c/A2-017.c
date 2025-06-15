#include <stdio.h>

int main()
{
    char size, type;
    if (scanf(" %c %c", &size, &type) != 2)
        return 0;
    char topType;
    int topCount;
    if (scanf(" %c", &topType) != 1)
        return 0;
    if (topType == 'N')
    {
        topCount = 0;
    }
    else
    {
        scanf("%d", &topCount);
    }
    int price = 0;
    if (size == 'S' && type == 'R')
        price = 60;
    else if (size == 'S' && type == 'T')
        price = 80;
    else if (size == 'M' && type == 'R')
        price = 80;
    else if (size == 'M' && type == 'T')
        price = 100;
    else if (size == 'L' && type == 'R')
        price = 100;
    else if (size == 'L' && type == 'T')
        price = 120;
    if (topType == 'P')
        price += 15 * topCount;
    else if (topType == 'E')
        price += 10 * topCount;
    printf("%d\n", price);
    return 0;
}
