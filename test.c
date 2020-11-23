#include <stdio.h>

#include "impl.h"

int main(int argc, char** argv) {
    uint64_t state[25] = {0};
    uint64_t statex2[50] = {0};

    f1600(state);

    for (int i = 0; i < 25; i++) {
        printf("%llX ", state[i]);
    }
    printf("\n");

    f1600x2(statex2, &RC[0]);

    for (int i = 0; i < 25; i++) {
        if (i % 5 == 0)
            printf("\n");
        printf("%llX ", statex2[2*i]);
    }
    printf("\n");

    return 0;
}

