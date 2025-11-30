#include "Student.h"

Student::Student() : Person(), course(1), group(""), university("") {}

Student::Student(const string& name, const string& gender, int age, int course, const string& group, const string& university)
    : Person(name, gender, age), course(course), group(group), university(university) {}

void Student::input() {
    Person::input();
    
    cout << "Введіть курс: ";
    while (!(cin >> course) || course < 1 || course > 6) {
        cout << "Помилка! Введіть коректний курс (1-6): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();
    
    cout << "Введіть групу: ";
    getline(cin, group);
    
    cout << "Введіть ВУЗ: ";
    getline(cin, university);
}

void Student::print() const {
    Person::print();
    cout << "Курс: " << course << "\nГрупа: " << group << "\nВУЗ: " << university << endl;
}