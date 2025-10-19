#include <stdio.h>

#define MAX_SIZE 10

void transposeMatrix(int n, int mat[][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main() {
    int n;
    printf("Введіть розмір квадратної матриці n (до 10): ");
    scanf("%d", &n);

    int mat[MAX_SIZE][MAX_SIZE];

    printf("Введіть елементи матриці рядок за рядком:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    transposeMatrix(n, mat);

    printf("\nТранспонована матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}
