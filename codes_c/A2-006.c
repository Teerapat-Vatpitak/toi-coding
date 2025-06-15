#include <stdio.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    char a[31][31];
    for (int i = 0; i < N; i++)
        scanf("%s", a[i]);
    int dp[31][31] = {0};
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (a[i][j] == '.' && ((i == N - 1 && j == N - 1) || (i < N - 1 && dp[i + 1][j]) || (j < N - 1 && dp[i][j + 1])))
                dp[i][j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (dp[i][j])
                cnt++;
    printf("%d\n", cnt);
    return 0;
}
