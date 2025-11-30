#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool checkHTMLTags(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return false;
    }

    stack<string> tagStack;
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    size_t pos = 0;
    while (pos < content.length()) {
        // Шукаємо початок тегу
        size_t start = content.find('<', pos);
        if (start == string::npos) break;

        // Шукаємо кінець тегу
        size_t end = content.find('>', start);
        if (end == string::npos) break;

        string tag = content.substr(start, end - start + 1);

        // Перевіряємо тип тегу
        if (tag.find("</td>") != string::npos ||
            tag.find("</TD>") != string::npos) {
            // Закриваючий тег
            if (tagStack.empty()) {
                cout << "ПОМИЛКА: зайвий закриваючий тег на позиції " << start << endl;
                return false;
            }
            tagStack.pop();
            } else if (tag.find("<td") != string::npos ||
                       tag.find("<TD") != string::npos) {
                // Відкриваючий тег (може бути з атрибутами)
                tagStack.push(tag);
                       }

        pos = end + 1;
    }

    if (!tagStack.empty()) {
        cout << "ПОМИЛКА: " << tagStack.size() << " незакритих тегів <td>" << endl;
        return false;
    }

    cout << "Перевірка пройдена успішно!" << endl;
    return true;
}

int main() {
    string filename = "input_4.html";

    if (checkHTMLTags(filename)) {
        cout << "✓ Файл містить правильну структуру тегів <td>" << endl;
        return 0;
    } else {
        cout << "✗ Файл містить помилки в структурі тегів <td>" << endl;
        return 1;
    }
}