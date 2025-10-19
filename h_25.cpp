#include <stdio.h>

#define MAX 10

int main() {
    int n;
    printf("Введіть розмір квадратної матриці n (до 10): ");
    scanf("%d", &n);

    double mat[MAX][MAX];

    printf("Введіть елементи матриці рядок за рядком:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat[i][j]);

    int min_i = -1, min_j = -1;
    double min_val = 1e9;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] > 0 && mat[i][j] < min_val) {
                min_val = mat[i][j];
                min_i = i;
                min_j = j;
            }

    if (min_i != -1) {
        for (int k = 0; k < n; k++) {
            double temp = mat[min_i][k];
            mat[min_i][k] = mat[k][min_j];
            mat[k][min_j] = temp;
        }
    }

    printf("\nМатриця після обміну:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2f ", mat[i][j]);
        printf("\n");
    }

    return 0;
}
