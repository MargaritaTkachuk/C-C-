#include <stdio.h>
#include <string.h>
#include "mountain.h"
#define N 5


void inputMountains(Mountain m[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %lf", m[i].name, &m[i].height);
    }
}

void printMountains(Mountain m[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %.2lf\n", m[i].name, m[i].height);
    }
}

char* highestMountain(Mountain m[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (m[i].height > m[maxIndex].height)
            maxIndex = i;
    }
    return m[maxIndex].name;
}

void printHeightByName(Mountain m[], int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(m[i].name, name) == 0) {
            printf("%.2lf\n", m[i].height);
            return;
        }
    }
    printf("Вершину з такою назвою не знайдено\n");
}

int main() {
    Mountain arr[N];
    inputMountains(arr, N);
    printMountains(arr, N);
    printf("Найвища вершина: %s\n", highestMountain(arr, N));
    char search[50];
    scanf("%s", search);
    printHeightByName(arr, N, search);
    return 0;
}
