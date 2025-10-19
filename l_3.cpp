#include <stdio.h>

#define MAX_SIZE 20


void inputMatrix(double mat[][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Введіть елемент матриці [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &mat[i][j]);
        }
    }
}

int main() {
    int m, n;
    double matrix[MAX_SIZE][MAX_SIZE];


    printf("Введіть кількість рядків m (менше 20): ");
    scanf("%d", &m);
    if (m <= 0 || m >= MAX_SIZE) {
        printf("Некоректна кількість рядків!\n");
        return 1;
    }

    printf("Введіть кількість стовпців n (менше 20): ");
    scanf("%d", &n);
    if (n <= 0 || n >= MAX_SIZE) {
        printf("Некоректна кількість стовпців!\n");
        return 1;
    }


    inputMatrix(matrix, m, n);


    printf("\nВведена матриця:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
