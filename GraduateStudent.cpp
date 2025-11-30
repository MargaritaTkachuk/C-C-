#include "GraduateStudent.h"

GraduateStudent::GraduateStudent() : Person(), Student(), Teacher(), researchTopic("") {}

GraduateStudent::GraduateStudent(const string& name, const string& gender, int age, 
                               int course, const string& group, const string& university,
                               const string& position, double salary, const string& researchTopic)
    : Person(name, gender, age), 
      Student(name, gender, age, course, group, university),
      Teacher(name, gender, age, university, position, salary),
      researchTopic(researchTopic) {}

void GraduateStudent::input() {
    Person::input();
    
    // Ввід студентських даних
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
    getline(cin, Student::university); // Явно вказуємо поле Student
    Teacher::university = Student::university; // Синхронізуємо значення

    // Ввід викладацьких даних
    cout << "Введіть посаду: ";
    getline(cin, position);

    cout << "Введіть зарплату: ";
    while (!(cin >> salary) || salary < 0) {
        cout << "Помилка! Введіть коректну зарплату: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();

    cout << "Введіть тему дослідження: ";
    getline(cin, researchTopic);
}

void GraduateStudent::print() const {
    Person::print();
    cout << "Курс: " << course << "\nГрупа: " << group
         << "\nВУЗ: " << Student::university << "\nПосада: " << position
         << "\nЗарплата: " << salary << "\nТема дослідження: " << researchTopic << endl;
}