#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* cache;

int sterling(int n, int k) {

    if (k == 1) return 1;
    if (n == k) return 1;
    if (k > n) return 0;
    if (n == 0) return k == 0 ? 1 : 0;
    if (k == 0) return n == 0 ? 1 : 0;

    int i = (n - 1) + (n - 1) * (k - 1);
    if (cache[i] == -1) {
        cache[i] = sterling(n - 1, k - 1) + k * sterling(n - 1, k);
    }

    return cache[i];
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: sterling [n] [k]\n");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    int m = n * k;
    cache = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        cache[i] = -1;
    }
    
    printf("%d\n", sterling(n, k));

    free(cache);
    return EXIT_SUCCESS;
}
