#include <stdio.h>
#include <math.h>


double sumGreaterThanE(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > M_E) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    double arr[10];
    int n = 10;

    printf("Введіть 10 чисел типу double:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
    }

    double result = sumGreaterThanE(arr, n);
    printf("Сума елементів більших за e = %.5f дорівнює: %.5f\n", M_E, result);

    return 0;
}
