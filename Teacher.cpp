#include "Teacher.h"

Teacher::Teacher() : Person(), university(""), position(""), salary(0) {}

Teacher::Teacher(const string& name, const string& gender, int age, const string& university, const string& position, double salary)
    : Person(name, gender, age), university(university), position(position), salary(salary) {}

void Teacher::input() {
    Person::input();

    cout << "Введіть ВУЗ: ";
    getline(cin, university);

    cout << "Введіть посаду: ";
    getline(cin, position);

    cout << "Введіть зарплату: ";
    while (!(cin >> salary) || salary < 0) {
        cout << "Помилка! Введіть коректну зарплату: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();
}

void Teacher::print() const {
    Person::print();
    cout << "ВУЗ: " << university << "\nПосада: " << position << "\nЗарплата: " << salary << endl;
}