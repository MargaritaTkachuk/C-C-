#include <stdio.h>

int main() {
    int arr[5] = {3, -2, 7, 0, 5};
    double x;
    int count = 0;

    printf("Введіть дійсне число: ");
    scanf("%lf", &x);

    for (int i = 0; i < 5; i++) {
        if (arr[i] < x) {
            count++;
        }
    }

    printf("Кількість чисел у масиві, менших за %.2f: %d\n", x, count);

    return 0;
}
