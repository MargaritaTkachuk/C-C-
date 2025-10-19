#include <stdio.h>

int main() {
    int matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int M, N;

    printf("Введіть натуральне число M (яке замінити): ");
    scanf("%d", &M);
    printf("Введіть число N (на яке замінити): ");
    scanf("%d", &N);


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }


    printf("\nОтримана матриця:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
