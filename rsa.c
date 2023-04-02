#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long pollard_rho(long long n) {
    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long c = rand() % (n - 1) + 1;
    long long d = 1;

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = gcd(abs(x - y), n);
    }

    if (d == n) {
        return pollard_rho(n);
    }

    return d;
}

void factor(long long n) {
    if (n == 1) {
        return;
    }

    long long factor1 = pollard_rho(n);
    factor(n / factor1);

    printf("%lld*", factor1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    long long n = atoll(argv[1]);

    srand(time(NULL));

    factor(n);

    printf("\b \n");

    return 0;
}

