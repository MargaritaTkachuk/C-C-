#include <stdio.h>
#include <string.h>
#include "product.h"

double priceInUAH(Product p) {
    return p.hryvnias + p.kopecks / 100.0;
}

void inputProducts(Product arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", arr[i].name, &arr[i].hryvnias, &arr[i].kopecks);
    }
}

void printProducts(Product arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %d грн %d коп\n", arr[i].name, arr[i].hryvnias, arr[i].kopecks);
    }
}

int findCheapest(Product arr[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        double cur = priceInUAH(arr[i]);
        double min = priceInUAH(arr[idx]);
        if (cur < min) idx = i;
    }
    return idx;
}

int findMostExpensive(Product arr[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        double cur = priceInUAH(arr[i]);
        double max = priceInUAH(arr[idx]);
        if (cur > max) idx = i;
    }
    return idx;
}

void findCloseToAverage(Product arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += priceInUAH(arr[i]);
    double avg = sum / n;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (priceInUAH(arr[i]) >= avg - 10 && priceInUAH(arr[i]) <= avg + 10) {
            printf("%s - %.2lf грн\n", arr[i].name, priceInUAH(arr[i]));
            found = 1;
        }
    }
    if (!found) printf("Немає товарів у межах 10 грн від середньої ціни\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Product arr[n];
    inputProducts(arr, n);
    printProducts(arr, n);

    int cheap = findCheapest(arr, n);
    int expensive = findMostExpensive(arr, n);

    printf("Найдешевший: %s - %.2lf грн\n", arr[cheap].name, priceInUAH(arr[cheap]));
    printf("Найдорожчий: %s - %.2lf грн\n", arr[expensive].name, priceInUAH(arr[expensive]));

    printf("Товари у межах ±10 грн від середньої вартості:\n");
    findCloseToAverage(arr, n);

    return 0;
}
