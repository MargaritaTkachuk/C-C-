#include "PhoneBook.h"
#include <algorithm>
#include <iostream>

PhoneBook::PhoneBook(const string& fname) : filename(fname) {
    loadFromFile();
}

PhoneBook::~PhoneBook() {
    saveToFile();
}

void PhoneBook::loadFromFile() {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Файл не знайдено. Буде створено новий довідник." << endl;
        return;
    }
    
    friends.clear();
    Friend f;
    while (file >> f && friends.size() < MAX_SIZE) {
        friends.push_back(f);
    }
    file.close();
    cout << "Дані завантажено з файлу. Записів: " << friends.size() << endl;
}

void PhoneBook::saveToFile() {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    
    for (const auto& f : friends) {
        file << f << endl;
    }
    file.close();
    cout << "Дані збережено у файл. Записів: " << friends.size() << endl;
}

void PhoneBook::addFriend() {
    if (friends.size() >= MAX_SIZE) {
        cout << "Довідник заповнений! Максимальна кількість: " << MAX_SIZE << endl;
        return;
    }
    
    Friend newFriend;
    cout << "Додавання нового знайомого:" << endl;
    newFriend.input();
    friends.push_back(newFriend);
    saveToFile();
    cout << "Знайомого додано успішно!" << endl;
}

void PhoneBook::findPhoneByName() const {
    string searchName;
    cout << "Введіть прізвище для пошуку: ";
    cin >> searchName;
    
    bool found = false;
    for (const auto& f : friends) {
        if (f.getName() == searchName) {
            cout << "Знайдено: ";
            f.show();
            cout << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Знайомого з прізвищем '" << searchName << "' не знайдено." << endl;
    }
}

void PhoneBook::changePhone() {
    string searchName, newPhone;
    cout << "Введіть прізвище знайомого для зміни телефону: ";
    cin >> searchName;
    
    bool found = false;
    for (auto& f : friends) {
        if (f.getName() == searchName) {
            cout << "Поточні дані: ";
            f.show();
            cout << endl;
            cout << "Введіть новий номер телефону: ";
            cin >> newPhone;
            f.setPhone(newPhone);
            saveToFile();
            cout << "Номер телефону змінено успішно!" << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Знайомого з прізвищем '" << searchName << "' не знайдено." << endl;
    }
}

void PhoneBook::removeFriend() {
    string searchName;
    cout << "Введіть прізвище знайомого для видалення: ";
    cin >> searchName;
    
    auto it = remove_if(friends.begin(), friends.end(),
        [&searchName](const Friend& f) { return f.getName() == searchName; });
    
    if (it != friends.end()) {
        friends.erase(it, friends.end());
        saveToFile();
        cout << "Знайомого видалено успішно!" << endl;
    } else {
        cout << "Знайомого з прізвищем '" << searchName << "' не знайдено." << endl;
    }
}

void PhoneBook::showAll() const {
    if (friends.empty()) {
        cout << "Довідник порожній." << endl;
        return;
    }
    
    cout << "Телефонний довідник (" << friends.size() << " записів):" << endl;
    for (size_t i = 0; i < friends.size(); ++i) {
        cout << i + 1 << ". ";
        friends[i].show();
        cout << endl;
    }
}