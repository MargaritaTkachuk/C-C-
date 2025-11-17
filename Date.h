#ifndef DATE_H
#define DATE_H

class Date {
    int y, m, d;

    static Date* instance;

public:
    Date(int y, int m, int d);
    static Date* getInstance(int y, int m, int d);
    int difference(const Date& other) const;

private:
    int daysFromStart() const;
};

#endif
