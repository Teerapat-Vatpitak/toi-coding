#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;

    char name[256], maxName[256];
    int weight;
    int countOver = 0;
    int maxWeight = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        scanf("%s %d", name, &weight);
        if (weight > 15)
        {
            countOver++;
        }
        if (weight > maxWeight)
        {
            maxWeight = weight;
            strcpy(maxName, name);
        }
    }

    printf("%d\n", countOver);
    printf("%s %d\n", maxName, maxWeight);
    return 0;
}
