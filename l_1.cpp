#include <stdio.h>
#include <stdlib.h>


void writeArrayToFile(const char *filename, double *arr, int n) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Помилка відкриття файлу для запису!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%lf ", arr[i]);
    }

    fclose(f);
}


void printFileContent(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Помилка відкриття файлу для читання!\n");
        return;
    }

    double num;
    int first = 1;
    while (fscanf(f, "%lf", &num) == 1) {
        if (!first)
            printf(", ");
        printf("%g", num);
        first = 0;
    }

    fclose(f);
    printf("\n");
}

int main() {
    int n;
    char filename[100];

    printf("Введіть довжину масиву: ");
    scanf("%d", &n);

    double *arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    printf("Введіть ім'я файлу для запису: ");
    scanf("%s", filename);

    writeArrayToFile(filename, arr, n);

    printf("Вміст файлу '%s':\n", filename);
    printFileContent(filename);

    free(arr);
    return 0;
}
