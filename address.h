#ifndef ADDRESS_H
#define ADDRESS_H

typedef struct {
    char city[50];
    char street[50];
    int building;
    int apartment;
} Address;

void inputAddress(Address *a);
void printAddress(Address a);

#endif
