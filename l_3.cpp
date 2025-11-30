#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Функція для перевірки, чи символ є роздільником
bool isDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' || c == '\t' || c == '\n';
}

// Функція для розгортання слова
string reverseWord(const string& word) {
    string reversed = word;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Функція для обробки файлу
void processFile(const string& inputFile, const string& outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open()) {
        cerr << "Помилка: не вдалося відкрити вхідний файл " << inputFile << endl;
        return;
    }

    if (!output.is_open()) {
        cerr << "Помилка: не вдалося відкрити вихідний файл " << outputFile << endl;
        return;
    }

    string line;
    while (getline(input, line)) {
        string currentWord;
        string processedLine;

        for (size_t i = 0; i <= line.length(); ++i) {
            char c = (i < line.length()) ? line[i] : '\0';

            // Якщо символ не роздільник, додаємо його до поточного слова
            if (i < line.length() && !isDelimiter(c)) {
                currentWord += c;
            } else {
                // Якщо є слово для обробки - розгортаємо його
                if (!currentWord.empty()) {
                    processedLine += reverseWord(currentWord);
                    currentWord.clear();
                }

                // Додаємо роздільник (якщо він є)
                if (i < line.length() && isDelimiter(c)) {
                    processedLine += c;
                }
            }
        }

        output << processedLine << endl;
    }

    input.close();
    output.close();
    cout << "Розшифрування завершено успішно!" << endl;
}

int main() {
    processFile("input_3.txt", "output_3.txt");
    return 0;
}