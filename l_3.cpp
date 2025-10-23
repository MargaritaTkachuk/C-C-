#include <stdio.h>
#include "date.h"


int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int dim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeap(year)) return 29;
    return dim[month];
}

Date tomorrow(Date d) {
    d.day++;
    if (d.day > daysInMonth(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

int dayOfWeek(Date d) {
    int y = d.year;
    int m = d.month;
    if (m < 3) { m += 12; y--; }
    int k = y % 100;
    int j = y / 100;
    int f = d.day + 13*(m+1)/5 + k + k/4 + j/4 + 5*j;
    return f % 7;
}

int main() {
    Date d;
    scanf("%d %d %d", &d.day, &d.month, &d.year);
    Date t = tomorrow(d);
    printf("%02d.%02d.%04d\n", t.day, t.month, t.year);
    int dow = dayOfWeek(d);
    printf("%d\n", dow);
    return 0;
}
