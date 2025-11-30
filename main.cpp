#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class MyString {
public:
    string s;

    MyString(const string &str = "") : s(str) {}

    /* --------------------------------------------------------
     * 1) Підрядок між першою двокрапкою та наступною комою
     * -------------------------------------------------------- */

    // Варіант 1: повертаємо новий рядок
    string task1_returnNew() const {
        size_t pos1 = s.find(':');
        if (pos1 == string::npos) return s;

        size_t pos2 = s.find(',', pos1 + 1);
        if (pos2 == string::npos) return s.substr(pos1);

        return s.substr(pos1 + 1, pos2 - pos1 - 1);
    }

    // Варіант 2: змінюємо поточний рядок
    void task1_modifyInPlace() {
        size_t pos1 = s.find(':');
        if (pos1 == string::npos) return;

        size_t pos2 = s.find(',', pos1 + 1);
        if (pos2 == string::npos) {
            s = s.substr(pos1);
        } else {
            s = s.substr(pos1 + 1, pos2 - pos1 - 1);
        }
    }

    /* --------------------------------------------------------
     * 2) Видалити підрядок між першою і останньою крапкою
     * -------------------------------------------------------- */

    // Варіант 1: повертаємо новий рядок
    string task2_returnNew() const {
        size_t first = s.find('.');
        size_t last = s.rfind('.');

        if (first == string::npos) {
            // немає жодної крапки → видалити пробіли на початку
            size_t i = s.find_first_not_of(' ');
            return (i == string::npos ? "" : s.substr(i));
        }

        if (first == last) {
            // лише одна крапка → видалити все до неї (включно ні)
            return s.substr(first + 1);
        }

        // дві крапки і більше
        return s.substr(0, first) + s.substr(last + 1);
    }

    // Варіант 2: змінюємо поточний рядок
    void task2_modifyInPlace() {
        size_t first = s.find('.');
        size_t last = s.rfind('.');

        if (first == string::npos) {
            size_t i = s.find_first_not_of(' ');
            s = (i == string::npos ? "" : s.substr(i));
            return;
        }

        if (first == last) {
            s = s.substr(first + 1);
            return;
        }

        s = s.substr(0, first) + s.substr(last + 1);
    }

    /* --------------------------------------------------------
     * 3) Видалити в кожному слові останню літеру.
     * -------------------------------------------------------- */

    // Варіант 1
    string task3_returnNew() const {
        string result = s;
        int n = result.size();

        for (int i = 0; i < n; ) {
            // пропускаємо пробіли
            if (result[i] == ' ') {
                i++;
                continue;
            }
            int start = i;
            while (i < n && result[i] != ' ') i++;

            // слово = [start, i)
            if (i - start >= 1)
                result.erase(i - 1, 1), i--; // видаляємо останню букву

            n = result.size();
        }
        return result;
    }

    // Варіант 2
    void task3_modifyInPlace() {
        *this = MyString(task3_returnNew());
    }

    /* --------------------------------------------------------
     * 6) Найкоротше слово в реченні
     * -------------------------------------------------------- */

    vector<string> splitWords() const {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word) words.push_back(word);
        return words;
    }

    // а) повернути перше найкоротше слово
    string shortest_first() const {
        auto words = splitWords();
        if (words.empty()) return "";

        string best = words[0];
        for (auto &w : words)
            if (w.length() < best.length()) best = w;

        return best;
    }

    // б) повернути останнє найкоротше слово
    string shortest_last() const {
        auto words = splitWords();
        if (words.empty()) return "";

        string best = words[0];
        for (auto &w : words)
            if (w.length() <= best.length()) best = w;

        return best;
    }

    // в) повернути всі найкоротші слова
    vector<string> shortest_all() const {
        auto words = splitWords();
        vector<string> result;
        if (words.empty()) return result;

        size_t minLen = words[0].length();
        for (auto &w : words)
            minLen = min(minLen, w.length());

        for (auto &w : words)
            if (w.length() == minLen) result.push_back(w);

        return result;
    }

};


/* ======================== DEMO ======================== */

int main() {
    MyString a("abc:hello,world");
    cout << "Task1 new: " << a.task1_returnNew() << endl;

    MyString b("Start...End");
    cout << "Task2 new: " << b.task2_returnNew() << endl;

    MyString c("Hello world abc");
    cout << "Task3 new: " << c.task3_returnNew() << endl;

    MyString d("this is an example of text");
    cout << "Shortest first: " << d.shortest_first() << endl;
    cout << "Shortest last: " << d.shortest_last() << endl;

    cout << "Shortest all: ";
    for (auto &w : d.shortest_all()) cout << w << " ";
    cout << endl;

    return 0;
}
