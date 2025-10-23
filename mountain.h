#ifndef MOUNTAIN_H
#define MOUNTAIN_H

typedef struct {
    char name[50];
    double height;
} Mountain;

void inputMountains(Mountain m[], int n);
void printMountains(Mountain m[], int n);
char* highestMountain(Mountain m[], int n);
void printHeightByName(Mountain m[], int n, const char *name);

#endif
