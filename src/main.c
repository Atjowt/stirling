#include <stdio.h>
#include <stdlib.h>

#include "sterling.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: sterling [n] [k]\n");
        return EXIT_FAILURE;
    }

    STERL_T n = atoi(argv[1]);
    STERL_T k = atoi(argv[2]);

    printf("%llu\n", sterl2(n, k));

    return EXIT_SUCCESS;
}
