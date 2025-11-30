#include "PhoneBook.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "\n=== ТЕЛЕФОННИЙ ДОВІДНИК ===\n";
    cout << "1. Показати всіх\n";
    cout << "2. Додати знайомого\n";
    cout << "3. Знайти телефон\n";
    cout << "4. Змінити номер\n";
    cout << "5. Видалити знайомого\n";
    cout << "6. Зберегти\n";
    cout << "7. Завантажити\n";
    cout << "0. Вихід\n";
    cout << "Виберіть: ";
}

int main() {
    // Вказуємо конкретний файл
    PhoneBook phoneBook("contacts.txt");
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: phoneBook.showAll(); break;
            case 2: phoneBook.addFriend(); break;
            case 3: phoneBook.findPhoneByName(); break;
            case 4: phoneBook.changePhone(); break;
            case 5: phoneBook.removeFriend(); break;
            case 6: phoneBook.saveToFile(); break;
            case 7: phoneBook.loadFromFile(); break;
            case 0: cout << "Вихід...\n"; break;
            default: cout << "Невірний вибір!\n";
        }
    } while (choice != 0);

    return 0;
}