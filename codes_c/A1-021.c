#include <stdio.h>
int main()
{
    int y;
    scanf("%d", &y);
    if (y < 1582)
    {
        if (y % 4 == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    else
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
