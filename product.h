#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct {
    char name[50];
    int hryvnias;
    int kopecks;
} Product;

void inputProducts(Product arr[], int n);
void printProducts(Product arr[], int n);
int findCheapest(Product arr[], int n);
int findMostExpensive(Product arr[], int n);
void findCloseToAverage(Product arr[], int n);

#endif
