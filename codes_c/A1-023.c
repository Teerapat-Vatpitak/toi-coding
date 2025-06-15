#include <stdio.h>
int main()
{
    int t;
    char u;
    scanf("%d %c", &t, &u);
    if (u == 'C' || u == 'c')
    {
        if (t <= 0)
            printf("solid\n");
        else if (t >= 100)
            printf("gas\n");
        else
            printf("liquid\n");
    }
    else
    {
        if (t <= 32)
            printf("solid\n");
        else if (t >= 212)
            printf("gas\n");
        else
            printf("liquid\n");
    }
    return 0;
}
