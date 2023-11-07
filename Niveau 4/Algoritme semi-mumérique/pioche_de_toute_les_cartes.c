#include <stdio.h>

// FONCTIONELLE

unsigned long long factorial(int n) 
{    
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() 
{
    int n;
    scanf("%d", &n);
    printf("%llu", factorial(n));

    return 0;
}
