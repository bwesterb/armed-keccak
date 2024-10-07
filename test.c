#include <stdio.h>
#include <stdbool.h>

#include "impl.h"

int main(int argc, char** argv) {
    uint64_t state[25] = {0};
    uint64_t statex2[50] = {0};
    bool passed = true;

    printf("C impl:\n");
    f1600(state);

    for (int i = 0; i < 25; i++) {
        printf("%llX ", state[i]);
    }
    printf("\n");

    printf("\nasm impl:\n");
    f1600x2(statex2, &RC[0]);

    for (int i = 0; i < 25; i++) {
        if ((i % 5 == 0) && (i > 0))
            printf("\n");
        printf("%llX ", statex2[2*i]);
    }
    printf("\n");


    for (int i = 0; i < 25; i++) {
        if (state[i] != statex2[2*i]) {
            passed = false;
        }
    }
    printf("\nBoth equal? %s\n", passed ? "Pass" : "Fail");

    return 0;
}

