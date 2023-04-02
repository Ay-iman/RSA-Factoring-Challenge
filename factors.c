#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize(unsigned long long n) {
    unsigned long long i, p, q;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            printf("%llu=%llu*%llu\n", n, p, q);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long long n;

    if (argc < 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        n = strtoull(line, NULL, 10);
        factorize(n);
    }
    if (line) {
        free(line);
    }
    fclose(fp);
    return 0;
}

