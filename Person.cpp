#include "Person.h"

Person::Person() : name(""), gender(""), age(0) {}

Person::Person(const string& name, const string& gender, int age)
    : name(name), gender(gender), age(age) {}

void Person::input() {
    cout << "Введіть ПІБ: ";
    getline(cin, name);
    cout << "Введіть стать: ";
    getline(cin, gender);

    cout << "Введіть вік: ";
    while (!(cin >> age) || age < 0) {
        cout << "Помилка! Введіть коректний вік: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore(); // очистка буфера
}

void Person::print() const {
    cout << "ПІБ: " << name << "\nСтать: " << gender << "\nВік: " << age << endl;
}