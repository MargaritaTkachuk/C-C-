#include <stdio.h>


void inputArray(int arr[], int n) {
    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}


int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[5];
    int n = 5;

    inputArray(arr, n);
    int maxVal = findMax(arr, n);

    printf("Максимальне значення у масиві: %d\n", maxVal);

    return 0;
}
