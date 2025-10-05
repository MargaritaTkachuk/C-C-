#include <stdio.h>

unsigned long long funk(int n) {
    int counter = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = n * 3LL + 1;
        }
        counter++;
    }
    return counter;
}

int main() {
    int max = 0, num = 0;
    unsigned long long step;
    for (int i = 1; i < 1000; i++) {
        step = funk(i);
        if (step > max) {
            max = step;
            num = i;
        }
    }
    printf("%d", num);
}