#include <stdio.h>


void find_first_positive() {
    int a = -99, b = -99, c = -99;
    int x = 0;
    int n = 3;

    while (x <= 0) {
        n++;
        x = c + a + 100;

        a = b;
        b = c;
        c = x;
    }

    printf("Перший додатній член: x[%d] = %d\n", n, x);
}

int main() {
    find_first_positive();
    return 0;
}