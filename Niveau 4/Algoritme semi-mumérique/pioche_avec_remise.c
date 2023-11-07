#include <stdio.h>
#include <math.h>

// FONCTIONNEL

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    long long total_lists = pow(N, P);

    printf("%lld\n", total_lists);

    return 0;
}
