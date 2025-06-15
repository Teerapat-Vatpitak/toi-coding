#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpLL(const void *a, const void *b)
{
    long long x = *(long long *)a, y = *(long long *)b;
    return (x < y ? -1 : x > y);
}

int lower_bound_ll(long long *a, int n, long long x)
{
    int l = 0, r = n;
    while (l < r)
    {
        int m = (l + r) >> 1;
        if (a[m] < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int bsearch_ll(long long *a, int n, long long x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (a[m] == x)
            return m;
        else if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    long long *red = malloc(sizeof(long long) * N);
    long long *blue = malloc(sizeof(long long) * M);
    for (int i = 0; i < N; i++)
        scanf("%lld", &red[i]);
    for (int j = 0; j < M; j++)
        scanf("%lld", &blue[j]);
    long long endd = red[N - 1] < blue[M - 1] ? red[N - 1] : blue[M - 1];

    int maxE = N + M + 1;
    long long *ev = malloc(sizeof(long long) * maxE);
    int E = 0;
    ev[E++] = 0;
    int i = 0, j = 0;
    while ((i < N && red[i] <= endd) || (j < M && blue[j] <= endd))
    {
        long long v;
        if (i < N && red[i] <= endd && (j >= M || blue[j] > endd || red[i] < blue[j]))
        {
            v = red[i++];
        }
        else if (j < M && blue[j] <= endd && (i >= N || red[i] > endd || blue[j] < red[i]))
        {
            v = blue[j++];
        }
        else
        {
            v = red[i];
            i++;
            j++;
        }
        if (v > 0 && ev[E - 1] != v)
            ev[E++] = v;
    }

    int cnt = 0;
    if (ev[0] == 0)
        cnt++;
    for (int k = 1; k < E; k++)
    {
        int ir = bsearch_ll(red, N, ev[k]);
        int ib = bsearch_ll(blue, M, ev[k]);
        if (ir >= 0 && ib >= 0 && (ir % 2) == (ib % 2))
        {
            cnt++;
        }
    }

    int *sign = malloc(sizeof(int) * E);
    for (int k = 0; k < E; k++)
    {
        long long x = ev[k];
        double yr, yb;
        if (x == 0)
        {
            yr = 0.0;
        }
        else
        {
            int pos = lower_bound_ll(red, N, x);
            if (pos < N && red[pos] == x)
            {
                yr = (pos % 2 == 0 ? 1.0 : 0.0);
            }
            else if (pos < N)
            {
                long long x0 = (pos > 0 ? red[pos - 1] : 0);
                double y0 = (pos > 0 ? ((pos - 1) % 2 == 0 ? 1.0 : 0.0) : 0.0);
                long long x1 = red[pos];
                double y1 = ((pos) % 2 == 0 ? 1.0 : 0.0);
                yr = y0 + (x - (double)x0) * (y1 - y0) / ((double)x1 - x0);
            }
            else
            {
                sign[k] = 0;
                continue;
            }
        }

        {
            int pos = lower_bound_ll(blue, M, x);
            if (x == 0)
            {
                yb = 0.0;
            }
            else if (pos < M && blue[pos] == x)
            {
                yb = (pos % 2 == 0 ? 1.0 : 0.0);
            }
            else if (pos < M)
            {
                long long x0 = (pos > 0 ? blue[pos - 1] : 0);
                double y0 = (pos > 0 ? ((pos - 1) % 2 == 0 ? 1.0 : 0.0) : 0.0);
                long long x1 = blue[pos];
                double y1 = ((pos) % 2 == 0 ? 1.0 : 0.0);
                yb = y0 + (x - (double)x0) * (y1 - y0) / ((double)x1 - x0);
            }
            else
            {
                sign[k] = 0;
                continue;
            }
        }

        double d = yr - yb;
        if (fabs(d) < 1e-12)
            sign[k] = 0;
        else
            sign[k] = (d > 0 ? 1 : -1);
    }

    for (int k = 1; k < E; k++)
    {
        if (sign[k] != 0 && sign[k - 1] != 0 && sign[k] * sign[k - 1] < 0)
        {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
