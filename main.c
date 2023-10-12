#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: sterling [n] [k]\n");
        return EXIT_FAILURE;
    }

    u64 n = atoi(argv[1]);
    u64 k = atoi(argv[2]);

    u64* prev = calloc(k + 1, sizeof(u64));
    u64* curr = calloc(k + 1, sizeof(u64));

    prev[1] = 1;

    for (u64 y = 1; y <= n; y++) {
        for (u64 x = 1; x <= k; x++) {
            curr[x] = prev[x - 1] + x * prev[x];
        }
        u64* t = prev;
        prev = curr;
        curr = t;
    }
    
    u64 res = curr[k];

    printf("%llu\n", res);

    free(curr);
    free(prev);

    return EXIT_SUCCESS;
}
