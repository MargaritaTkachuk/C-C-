#include <stdio.h>
#include <stdlib.h>

#define MAX 10

double determinant(double mat[MAX][MAX], int n) {
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    double det = 0.0;
    double sub[MAX][MAX];

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                sub[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * mat[0][x] * determinant(sub, n - 1);
    }

    return det;
}

int main() {
    int n;
    printf("Введіть розмір квадратної матриці n (до 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) return 1;

    double mat[MAX][MAX];

    printf("Введіть елементи матриці рядок за рядком:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat[i][j]);

    double det = determinant(mat, n);
    printf("Детермінант матриці: %.2f\n", det);

    return 0;
}

