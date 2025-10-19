#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_power_of(int num, int base) {
    if (num < 1) return false;
    while (num % base == 0) {
        num /= base;
    }
    return num == 1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    long* arr = (long*)malloc(n * sizeof(long));
    if (!arr) return 1;

    printf("Enter %d natural numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    int count2 = 0, count3 = 0;

    for (int i = 0; i < n; i++) {
        if (is_power_of(arr[i], 2)) count2++;
        if (is_power_of(arr[i], 3)) count3++;
    }

    printf("Number of powers of 2: %d\n", count2);
    printf("Number of powers of 3: %d\n", count3);

    free(arr);
    return 0;
}
