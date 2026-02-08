#include <stdio.h>

long power(long a, int b) {
    if (b == 0) return 1;
    long half = power(a, b / 2);
    if (b % 2 == 0) return half * half;
    return half * half * a;
}

int main() {
    long a;
    int b;
    scanf("%ld %d", &a, &b);
    printf("%ld\n", power(a, b));
    return 0;
}

