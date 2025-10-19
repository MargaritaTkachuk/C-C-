#include <stdio.h>

int main() {
    int n;
    printf("num of elements: ");
    scanf("%d", &n);

    double arr[n];
    printf("enter %d nums:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }

    printf("sum n^2 = %.2lf\n", sum);

    return 0;
}
