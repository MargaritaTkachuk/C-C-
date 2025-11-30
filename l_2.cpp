#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream input("input_2.txt");
    ofstream output("output_2.txt");

    if (!input || !output) {
        cerr << "Помилка відкриття файлів!" << endl;
        return 1;
    }

    string prev_word = "";
    string curr_word;

    while (input >> curr_word) {
        // Перевіряємо чи попереднє слово було артиклем
        if (prev_word == "die" || prev_word == "der" || prev_word == "das") {
            // Змінюємо першу літеру на велику
            if (!curr_word.empty()) {
                curr_word[0] = toupper(curr_word[0]);
            }
        }

        output << curr_word << " ";
        prev_word = curr_word;
    }

    input.close();
    output.close();
    cout << "Обробка завершена успішно!" << endl;

    return 0;
}