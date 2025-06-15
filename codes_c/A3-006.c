#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) { return *(int*)b - *(int*)a; }

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *d = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
    qsort(d, n, sizeof(int), cmp_desc);

    long long sum = 0;
    int odd = 1, idx = 0;
    while (idx < n) {
        sum += 1LL * odd * d[idx++];
        if (idx == n) break;
        int even = odd + 1;
        for (int j = 0; j < 10 && idx < n; ++j, ++idx)
            sum += 1LL * even * d[idx];
        odd += 2;
    }

    printf("%lld\n", sum);
    free(d);
    return 0;
}
