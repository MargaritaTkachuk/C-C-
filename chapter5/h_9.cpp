#include <stdio.h>

int main() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);

    unsigned v0 = 1, v1 = 1, v2 = 1;
    unsigned v = 1;

        for (unsigned i = 3; i <= n; i++) {
            v = (i + 4) * (v2 - 1) + (i + 5) * v0;
            v0 = v1;
            v1 = v2;
            v2 = v;
        }


    printf("v = %u\n", v);

}
