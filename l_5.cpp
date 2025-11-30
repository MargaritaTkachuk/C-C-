#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    string surname;
    int course;
    string group;
    double avg;
};

// Функція обчислення середнього
double average_from_string(const string &marks_str) {
    stringstream ss(marks_str);
    string token;
    double sum = 0;
    int count = 0;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += atoi(token.c_str());
            count++;
        }
    }

    if (count == 0) return 0;
    return sum / count;
}

int main() {
    int N;
    cout << "Введіть кількість студентів N: ";
    cin >> N;
    cin.ignore(); // очистити буфер

    ofstream fout("students.txt");
    if (!fout) {
        cout << "Помилка відкриття файла!" << endl;
        return 1;
    }

    // === Створення файла ===
    cout << "\nВводьте рядки у форматі:\n";
    cout << "Прізвище Курс Група Оцінки_через_коми\n";
    cout << "Напр.: Petrenko 2 KN-24 12,10,8,9\n\n";

    for (int i = 0; i < N; i++) {
        string line;
        cout << "Рядок " << (i + 1) << ": ";
        getline(cin, line);
        fout << line << "\n";
    }

    fout.close();

    // === Обробка файла ===
    ifstream fin("students.txt");
    if (!fin) {
        cout << "Помилка читання файла!" << endl;
        return 2;
    }

    string line;
    Student worst;
    worst.avg = 1e9; // дуже велике число

    while (getline(fin, line)) {
        stringstream ss(line);
        Student st;
        string marks;

        ss >> st.surname >> st.course >> st.group >> marks;
        st.avg = average_from_string(marks);

        if (st.avg < worst.avg) {
            worst = st;
        }
    }

    fin.close();

    cout << "\nСтудент з найгіршою середньою оцінкою:\n";
    cout << worst.surname << "  (середня = " << worst.avg << ")\n";

    return 0;
}
