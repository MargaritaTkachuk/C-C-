#include <stdio.h>

void variant_a() {
    double b;
    int n;

    printf("Введіть значення b: ");
    scanf("%lf", &b);
    printf("Введіть значення n: ");
    scanf("%d", &n);

    double result = b;
    for (int i = 1; i < n; i++) {
        result = b + 1.0 / result;
    }

    printf("Результат варіанту а): %.10f\n", result);
}

void variant_b() {
    int n;

    printf("Введіть значення n: ");
    scanf("%d", &n);

    double b_k = 4 * n + 2;

    for (int k = 1; k <= n; k++) {
        b_k = 4 * (n - k) + 2 + 1.0 / b_k;
    }

    printf("Результат варіанту б): %.10f\n", b_k);
}

void variant_c() {
    int n;

    printf("Введіть значення n: ");
    scanf("%d", &n);

    double result = 2.0;

    for (int i = 2 * n - 1; i >= 1; i--) {
        if (i % 2 == 1) {
            result = 1.0 + 1.0 / result;
        } else {
            result = 2.0 + 1.0 / result;
        }
    }

    printf("Результат варіанту в): %.10f\n", result);
}

int main() {
    int choice;

    printf("Оберіть варіант:\n");
    printf("1 - варіант а)\n");
    printf("2 - варіант б)\n");
    printf("3 - варіант в)\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            variant_a();
            break;
        case 2:
            variant_b();
            break;
        case 3:
            variant_c();
            break;
        default:
            printf("Невірний вибір!\n");
            return 1;
    }

    return 0;
}