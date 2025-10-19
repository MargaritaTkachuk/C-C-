#include <stdio.h>

int main() {
    int n;
    printf("Введіть кількість оцінок n (натуральне, n >= 3): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректне значення n.\n");
        return 1;
    }

    if (n < 3) {
        printf("Недостатньо оцінок для видалення мінімуму і максимуму (потрібно n >= 3).\n");
        return 1;
    }

    double a[n];
    printf("Введіть %d дійсних оцінок:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%lf", &a[i]);
    }

    double maxv = a[0], minv = a[0];
    int idx_max = 0, idx_min = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > maxv) {
            maxv = a[i];
            idx_max = i;
        }
        if (a[i] < minv) {
            minv = a[i];
            idx_min = i;
        }
    }


    if (idx_max == idx_min) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (i != idx_max && a[i] == minv) { // тут minv == maxv
                idx_min = i;
                found = 1;
                break;
            }
        }
        if (!found) {

            idx_min = (idx_max + 1) % n;
        }
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (i == idx_max || i == idx_min) continue;
        sum += a[i];
    }

    double average = sum / (n - 2);

    printf("\nВидалено одну максимальну оцінку a[%d] = %.6f\n", idx_max + 1, a[idx_max]);
    printf("Видалено одну мінімальну оцінку a[%d] = %.6f\n", idx_min + 1, a[idx_min]);
    printf("Середнє арифметичне від решти %d оцінок: %.6f\n", n - 2, average);

    return 0;
}
