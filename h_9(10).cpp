#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "Введіть число N: ";
    cin >> N;
    cin.ignore(); // очистити буфер

    string filename = "delete_lines.txt";

    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Не вдалося відкрити файл для читання.\n";
        return 1;
    }

    vector<string> lines;
    string line;

    // Зчитуємо файл у пам'ять
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    vector<string> result;
    int real_number = 0;  // Нумерація непорожніх рядків

    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].length() == 0) {
            // порожній рядок не нумерується і не видаляється
            result.push_back(lines[i]);
            continue;
        }

        real_number++;

        // Якщо номер кратний N — пропускаємо (видаляємо)
        if (real_number % N == 0)
            continue;

        result.push_back(lines[i]);
    }

    // Якщо нічого не видалили — залишаємо без змін
    if (result.size() == lines.size()) {
        cout << "Рядків із номерами, кратними " << N << ", не знайдено. Файл не змінено.\n";
        return 0;
    }

    // Записуємо назад у файл
    ofstream fout(filename.c_str());
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису.\n";
        return 2;
    }

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i + 1 < result.size()) fout << "\n";
    }

    fout.close();

    cout << "Рядки з номерами, кратними " << N << ", видалено.\n";

    return 0;
}
