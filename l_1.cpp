#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <vector>
#include <iomanip>

int main() {
    std::string filename = "input_1.txt";
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Не вдалось відкрити файл: " << filename << '\n';
        return 1;
    }

    // Зчитуємо весь файл в рядок
    std::string content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();

    // Знаходимо '='
    auto eqpos = content.find('=');
    if (eqpos == std::string::npos) {
        std::cerr << "У файлі не знайдено знак '='\n";
        return 2;
    }

    // Вирізаємо частину до '=' і прибираємо пробіли
    std::string expr = content.substr(0, eqpos);
    std::string s;
    s.reserve(expr.size());
    for (char ch : expr) {
        if (!std::isspace(static_cast<unsigned char>(ch))) {
            // Замінюємо десяткову кому на крапку (опціонально)
            if (ch == ',') s.push_back('.');
            else s.push_back(ch);
        }
    }

    if (s.empty()) {
        std::cerr << "Вираз порожній перед '='\n";
        return 3;
    }

    // Створимо модифікований нуль-термінований буфер (strtod вимагає modifiable char*)
    std::vector<char> buf(s.begin(), s.end());
    buf.push_back('\0'); // термінатор
    char* p = buf.data();
    char* endptr = nullptr;

    errno = 0;
    double result = std::strtod(p, &endptr);
    if (endptr == p) {
        std::cerr << "Помилка парсингу першого числа\n";
        return 4;
    }
    if (errno == ERANGE) {
        std::cerr << "Число поза діапазоном (перший операнд)\n";
        return 5;
    }

    // Проходимо по рядку: очікуємо послідовність (op number)...
    while (*endptr != '\0') {
        char op = *endptr;
        if (op != '+' && op != '-') {
            std::cerr << "Очікував '+' або '-' в позиції, знайдено '" << op << "'\n";
            return 6;
        }
        // рухаємося далі і парсимо наступне число
        char* nextStart = endptr + 1;
        if (*nextStart == '\0') {
            std::cerr << "Після оператора немає числа\n";
            return 7;
        }

        errno = 0;
        char* nextEnd = nullptr;
        double val = std::strtod(nextStart, &nextEnd);
        if (nextEnd == nextStart) {
            std::cerr << "Помилка парсингу числа після оператора '" << op << "'\n";
            return 8;
        }
        if (errno == ERANGE) {
            std::cerr << "Число поза діапазоном після оператора '" << op << "'\n";
            return 9;
        }

        if (op == '+') result += val;
        else result -= val;

        endptr = nextEnd;
    }

    // Вивід з розумною точністю
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(6) << "Результат: " << result << '\n';

    // Запис в output_1.txt (чисто число)
    std::ofstream fout("output_1.txt");
    if (fout) {
        fout.setf(std::ios::fixed);
        fout << std::setprecision(6) << result << '\n';
    } else {
        std::cerr << "Не вдалось відкрити output_1.txt для запису\n";
    }

    return 0;
}
