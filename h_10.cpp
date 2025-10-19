#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n має бути натуральним числом!\n");
        return 1;
    }

    int a[n];
    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%d", &a[i]);
    }

    int k = (int)sqrt(n);
    int countEven = 0;

    printf("\nПеревіряємо елементи з індексами квадратів чисел:\n");

    for (int i = 1; i <= k; i++) {
        int index = i * i;
        int value = a[index - 1];
        printf("a[%d] = %d\n", index, value);
        if (value % 2 == 0)
            countEven++;
    }

    printf("\nКількість парних серед a(1^2), a(2^2), ..., a(%d^2): %d\n", k, countEven);

    return 0;
}
