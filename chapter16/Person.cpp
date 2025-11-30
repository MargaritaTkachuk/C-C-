#include "Person.h"

Person::Person() : name(""), byear(0) {}

Person::Person(const string& n, unsigned y) : name(n), byear(y) {}

Person::~Person() {}

int Person::input() {
    cout << "Введіть прізвище: ";
    cin >> name;
    cout << "Введіть рік народження: ";
    cin >> byear;
    return 1;
}

void Person::show() const {
    cout << "Прізвище: " << name << ", Рік народження: " << byear;
}

string Person::getName() const {
    return name;
}

unsigned Person::getBirthYear() const {
    return byear;
}

void Person::setName(const string& n) {
    name = n;
}

void Person::setBirthYear(unsigned y) {
    byear = y;
}

ostream& operator<<(ostream& os, const Person& p) {
    p.show();
    return os;
}

istream& operator>>(istream& is, Person& p) {
    p.input();
    return is;
}