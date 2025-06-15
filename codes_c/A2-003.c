#include <stdio.h>

int main(){
    int N;
    if (scanf("%d", &N)!=1) return 0;
    int H[1005];
    for (int i = 0; i < N; i++) scanf("%d", &H[i]);
    int cnt = 0;
    for (int i = 0; i < N; i++){
        int ok = 1;
        if (i > 0   && H[i-1] > H[i]) ok = 0;
        if (i < N-1 && H[i+1] > H[i]) ok = 0;
        if (ok) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
