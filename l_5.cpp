#include <stdio.h>


void countEvenOdd(int arr[], int n, int *evenCount, int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            (*evenCount)++;
        else
            (*oddCount)++;
    }
}

int main() {
    int arr[50];
    int n = 0;
    int num;

    printf("Вводьте натуральні числа (0 — завершення вводу):\n");

    while (n < 50) {
        printf("arr[%d] = ", n);
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num < 0) {
            printf("Введіть лише натуральні числа!\n");
            continue;
        }
        arr[n++] = num;
    }

    int evenCount, oddCount;
    countEvenOdd(arr, n, &evenCount, &oddCount);

    printf("\nКількість парних елементів: %d\n", evenCount);
    printf("Кількість непарних елементів: %d\n", oddCount);

    return 0;
}
