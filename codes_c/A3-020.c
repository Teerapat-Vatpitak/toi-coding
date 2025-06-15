#include <stdio.h>
#include <stdlib.h>

int main()
{
    int H1, H2, B1, B2, X, Y;
    if (scanf("%d %d %d %d", &H1, &H2, &B1, &B2) != 4)
        return 0;
    scanf("%d %d", &X, &Y);
    int best = 0;
    int maxWW = H1 < B1 ? H1 : B1;
    int maxBB = H2 < B2 ? H2 : B2;
    for (int w = 0; w <= maxWW && w <= X; w++)
    {
        for (int b = 0; b <= maxBB && w + b <= X; b++)
        {
            int same = w + b;
            int remH1 = H1 - w;
            int remB1 = B1 - w;
            int remH2 = H2 - b;
            int remB2 = B2 - b;
            int diff1 = remH1 < remB2 ? remH1 : remB2;
            int diff2 = remH2 < remB1 ? remH2 : remB1;
            int diff = diff1 + diff2;
            if (diff > Y)
                diff = Y;
            int total = same + diff;
            if (total > best)
                best = total;
        }
    }
    printf("%d\n", best);
    return 0;
}
