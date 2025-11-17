#ifndef TIME_H
#define TIME_H

class Time {
    int h, m, s;
    int toSeconds() const;
public:
    Time(int h = 0, int m = 0, int s = 0);
    int difference(const Time& other) const;
};

#endif
