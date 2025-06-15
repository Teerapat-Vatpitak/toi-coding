#include <stdio.h>

int main()
{
    int L, P;
    if (scanf("%d %d", &L, &P) != 2)
        return 0;
    int j[3];
    scanf("%d %d %d", &j[0], &j[1], &j[2]);
    int pos[500], val[500];
    for (int i = 0; i < P; i++)
        scanf("%d %d", &pos[i], &val[i]);
    int score[3] = {0};
    for (int k = 0; k < 3; k++)
    {
        for (int p = 0; p < P; p++)
        {
            if (pos[p] % j[k] == 0)
                score[k] += val[p];
        }
    }
    int mx = score[0];
    if (score[1] > mx)
        mx = score[1];
    if (score[2] > mx)
        mx = score[2];
    const char *name[3] = {"Rabbit", "Monkey", "Frog"};
    for (int k = 0; k < 3; k++)
    {
        if (score[k] == mx)
            printf("%s %d\n", name[k], mx);
    }
    return 0;
}
