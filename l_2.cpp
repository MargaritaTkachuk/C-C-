#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int input_array(int* arr, int max_size) {
    int count = 0;
    int x;
    printf("Введіть цілі числа (0 для завершення):\n");
    while (count < max_size) {
        if (scanf("%d", &x) != 1) break;
        if (x == 0) break;
        arr[count++] = x;
    }
    return count;
}

bool is_perfect_square(int n) {
    if (n < 0) return false;
    int root = (int)(sqrt(n) + 0.5);
    return root * root == n;
}

bool is_perfect_cube(int n) {
    int root = (int)(round(pow(n, 1.0/3.0)));
    return root * root * root == n;
}

int main() {
    int arr[100];
    int n = input_array(arr, 100);
    int count_squares = 0;
    int count_cubes = 0;

    for (int i = 0; i < n; i++) {
        if (is_perfect_square(arr[i])) count_squares++;
        if (is_perfect_cube(arr[i])) count_cubes++;
    }

    printf("Кількість повних квадратів: %d\n", count_squares);
    printf("Кількість повних кубів: %d\n", count_cubes);

    return 0;
}
