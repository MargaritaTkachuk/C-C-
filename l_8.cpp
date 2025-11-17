#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    FILE *fIn, *fOut;
    char fInName[] = "F_8.txt";
    char fOutName[] = "G_8.txt";
    int n;

    printf("Введіть n (розмір групи): ");
    scanf("%d", &n);

    fIn = fopen(fInName, "r");
    if (!fIn) {
        printf("Не вдалося відкрити файл %s!\n", fInName);
        return 1;
    }

    fOut = fopen(fOutName, "w");
    if (!fOut) {
        printf("Не вдалося створити файл %s!\n", fOutName);
        fclose(fIn);
        return 1;
    }

    int num, count = 0, groupIndex = 1;
    int maxVal = INT_MIN;

    while (fscanf(fIn, "%d", &num) == 1) {

        if (num > maxVal) maxVal = num;
        count++;


        if (count % n == 0) {
            fprintf(fOut, "%d ", maxVal);
            printf("Група %d -> макс = %d\n", groupIndex, maxVal);
            groupIndex++;
            maxVal = INT_MIN;
        }
    }

    if (count % n != 0) {
        fprintf(fOut, "%d ", maxVal);
        printf("Група %d (неповна) -> макс = %d\n", groupIndex, maxVal);
    }

    fclose(fIn);
    fclose(fOut);

    printf("\nРезультат записано у файл %s\n", fOutName);
    return 0;
}
