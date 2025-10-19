#include <stdio.h>

int main() {
    double matrix[3][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
    int i, j;
    double a;

    printf("Введіть індекс рядка i (1..3): ");
    scanf("%d", &i);
    printf("Введіть індекс стовпця j (1..3): ");
    scanf("%d", &j);

    if (i < 1 || i > 3 || j < 1 || j > 3) {
        printf("Некоректні індекси! Вони мають бути від 1 до 3.\n");
        return 1;
    }

    printf("Введіть дійсне число a: ");
    scanf("%lf", &a);


    matrix[i-1][j-1] = a;

    printf("\nОтримана матриця:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            printf("%.2f ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}
