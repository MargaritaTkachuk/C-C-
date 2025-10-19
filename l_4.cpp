#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

void inputIntMatrix(int mat[][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Введіть рядок %d (%d цілих чисел через пробіл): ", i + 1, n);
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &mat[i][j]) != 1) {
                printf("Некоректне введення!\n");
                exit(1);
            }
        }
    }
}

void inputDoubleMatrix(double mat[][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Введіть рядок %d (%d дійсних чисел через пробіл): ", i + 1, n);
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &mat[i][j]) != 1) {
                printf("Некоректне введення!\n");
                exit(1);
            }
        }
    }
}

int main() {
    int m, n;
    printf("Введіть кількість рядків m (менше 25): ");
    scanf("%d", &m);
    if (m <= 0 || m >= MAX_SIZE) return 1;

    printf("Введіть кількість стовпців n (менше 25): ");
    scanf("%d", &n);
    if (n <= 0 || n >= MAX_SIZE) return 1;

    int intMatrix[MAX_SIZE][MAX_SIZE];
    inputIntMatrix(intMatrix, m, n);

    printf("\nВведена ціла матриця:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%d ", intMatrix[i][j]);
        printf("\n");
    }

    double doubleMatrix[MAX_SIZE][MAX_SIZE];
    inputDoubleMatrix(doubleMatrix, m, n);

    printf("\nВведена дійсна матриця:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%.2f ", doubleMatrix[i][j]);
        printf("\n");
    }

    return 0;
}
