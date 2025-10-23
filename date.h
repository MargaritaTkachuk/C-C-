#ifndef DATE_H
#define DATE_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeap(int year);
int daysInMonth(int month, int year);
Date tomorrow(Date d);
int dayOfWeek(Date d);

#endif
