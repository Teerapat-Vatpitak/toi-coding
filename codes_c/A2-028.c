#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    char *s1 = malloc(N + 1);
    char *s2 = malloc(N + 1);
    scanf("%s", s1);
    scanf("%s", s2);
    int bad = 0;
    for (int i = 0; i < N; i++)
    {
        if ((s1[i] - '0') + (s2[i] - '0') != 9)
            bad++;
    }
    if (bad == 0)
        printf("YES\n");
    else
        printf("NO %d\n", bad);
    return 0;
}
