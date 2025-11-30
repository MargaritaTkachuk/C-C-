#include "Friend.h"

Friend::Friend() : Person(), phone("") {}

Friend::Friend(const string& n, unsigned y, const string& p) 
    : Person(n, y), phone(p) {}

int Friend::input() {
    Person::input();
    cout << "Введіть номер телефону: ";
    cin >> phone;
    return 1;
}

void Friend::show() const {
    Person::show();
    cout << ", Телефон: " << phone;
}

string Friend::getPhone() const {
    return phone;
}

void Friend::setPhone(const string& p) {
    phone = p;
}

ostream& operator<<(ostream& os, const Friend& f) {
    os << f.name << " " << f.byear << " " << f.phone;
    return os;
}

istream& operator>>(istream& is, Friend& f) {
    is >> f.name >> f.byear >> f.phone;
    return is;
}