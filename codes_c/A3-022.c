#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    bool cover[720] = {false};
    for (int i = 0; i < N; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        if (A < B)
        {
            for (int a = A; a < B; a++)
                cover[a] = true;
        }
        else
        {
            for (int a = A; a < 360; a++)
                cover[a] = true;
            for (int a = 0; a < B; a++)
                cover[a] = true;
        }
    }

    for (int i = 0; i < 360; i++)
        cover[i + 360] = cover[i];
    int best = 0, curr = 0;
    for (int i = 0; i < 720; i++)
    {
        if (cover[i])
        {
            curr++;
            if (curr > best)
                best = curr;
        }
        else
        {
            curr = 0;
        }
    }
    if (best > 360)
        best = 360;
    printf("%d\n", best);
    return 0;
}
