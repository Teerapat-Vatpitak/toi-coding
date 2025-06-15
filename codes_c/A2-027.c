#include <stdio.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int score;
    int maxScore = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &score);
        if (score > maxScore)
        {
            maxScore = score;
            count = 1;
        }
        else if (score == maxScore)
        {
            count++;
        }
    }
    printf("%d\n%d\n", maxScore, count);
    return 0;
}
