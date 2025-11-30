#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Функція, що рахує кількість слів, які містять символ ch
int countWordsWithChar(const string& str, char ch) {
    stringstream ss(str);
    string word;
    int count = 0;

    while (ss >> word) {        // зчитує слова, ігноруючи зайві пробіли
        if (word.find(ch) != string::npos)
            count++;
    }
    return count;
}

int main() {
    string input;
    char ch;

    cout << "Enter a string: ";
    getline(cin, input);

    cout << "Enter a character: ";
    cin >> ch;

    int result = countWordsWithChar(input, ch);

    cout << "Number of words containing '" << ch << "': " << result << endl;

    return 0;
}
