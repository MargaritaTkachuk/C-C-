#include <stdio.h>

#define MAX_SIZE 20


void inputVector(double vec[], int n) {
    printf("Введіть %d елементів вектора:\n", n);
    for (int i = 0; i < n; i++) {
        printf("vec[%d] = ", i);
        scanf("%lf", &vec[i]);
    }
}


void printVector(double vec[], int n) {
    printf("(");
    for (int i = 0; i < n; i++) {
        printf("%.2f", vec[i]);
        if (i < n - 1) printf(", ");
    }
    printf(")\n");
}


void sumVectors(double v1[], double v2[], double result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = v1[i] + v2[i];
    }
}


double dotProduct(double v1[], double v2[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main() {
    int n;
    double v1[MAX_SIZE], v2[MAX_SIZE], vSum[MAX_SIZE];

    printf("Введіть розмірність векторів (менше 20): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Некоректна розмірність!\n");
        return 1;
    }

    printf("\nВектор 1:\n");
    inputVector(v1, n);

    printf("\nВектор 2:\n");
    inputVector(v2, n);

    sumVectors(v1, v2, vSum, n);

    double scalar = dotProduct(v1, v2, n);

    printf("\nВектор 1: ");
    printVector(v1, n);

    printf("Вектор 2: ");
    printVector(v2, n);

    printf("Сума векторів: ");
    printVector(vSum, n);

    printf("Скалярний добуток: %.2f\n", scalar);

    return 0;
}
