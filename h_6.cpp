#include <stdio.h>
#include "address.h"

void inputAddress(Address *a) {
    scanf("%s %s %d %d", a->city, a->street, &a->building, &a->apartment);
}

void printAddress(Address a) {
    printf("%s, %s, буд. %d, кв. %d\n", a.city, a.street, a.building, a.apartment);
}

int main() {
    Address addr;
    inputAddress(&addr);
    printAddress(addr);
    return 0;
}
