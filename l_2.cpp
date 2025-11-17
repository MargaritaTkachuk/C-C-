#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void createFileF(const char *filename, double *arr, int n) {
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


void processFiles(const char *fileF, const char *fileG, double a) {
    FILE *fIn = fopen(fileF, "r");
    FILE *fG = fopen(fileG, "w");

    if (fIn == NULL || fG == NULL) {
        printf("Помилка відкриття файлів!\n");
        if (fIn) fclose(fIn);
        if (fG) fclose(fG);
        return;
    }

    double num;
    int count = 0;


    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Помилка створення тимчасового файлу!\n");
        fclose(fIn);
        fclose(fG);
        return;
    }

    while (fscanf(fIn, "%lf", &num) == 1) {
        if (fabs(num) < a) {
            fprintf(fG, "%lf ", num);
        } else {
            fprintf(temp, "%lf ", num);
        }
        count++;
    }

    fclose(fIn);
    fclose(fG);
    fclose(temp);

    remove(fileF);
    rename("temp.txt", fileF);

    printf("Оброблено %d чисел.\n", count);
}

void printFile(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Не вдалося відкрити файл %s!\n", filename);
        return;
    }

    double num;
    int first = 1;
    while (fscanf(f, "%lf", &num) == 1) {
        if (!first) printf(", ");
        printf("%g", num);
        first = 0;
    }
    printf("\n");
    fclose(f);
}

int main() {
    char fileF[100] = "F.txt";
    char fileG[100] = "G.txt";

    int n;
    double a;

    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    double *arr = (double*)malloc(n * sizeof(double));
    if (!arr) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("Введіть елементи (дійсні числа):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    createFileF(fileF, arr, n);
    free(arr);

    printf("Введіть число a (> 0): ");
    scanf("%lf", &a);
    if (a <= 0) {
        printf("a повинно бути > 0!\n");
        return 1;
    }

    processFiles(fileF, fileG, a);

    printf("\nФайл F після обробки:\n");
    printFile(fileF);

    printf("\nФайл G (елементи з |x| < a):\n");
    printFile(fileG);

    return 0;
}
