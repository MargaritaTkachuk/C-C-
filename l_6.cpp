#include <stdio.h>
#define MAX 100

int main() {
    int N, M;
    printf("Введіть кількість рядків N (<100): ");
    scanf("%d", &N);
    printf("Введіть кількість стовпців M (<100): ");
    scanf("%d", &M);

    if (N <= 0 || N >= MAX || M <= 0 || M >= MAX) return 1;

    double A[MAX][MAX];

    printf("Введіть елементи матриці рядок за рядком:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%lf", &A[i][j]);

    int k;
    printf("Введіть число k: ");
    scanf("%d", &k);

    double sum = 0.0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (i - j == k)
                sum += A[i][j];

    printf("Сума елементів, де i - j = %d: %.2f\n", k, sum);

    return 0;
}
