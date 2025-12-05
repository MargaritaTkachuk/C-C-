#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    list<int> L;

    cout << "Введіть " << n << " цілих чисел:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        L.push_back(x);
    }

    // Вивід у прямому порядку
    cout << "Прямий порядок:\n";
    for (list<int>::iterator it = L.begin(); it != L.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Вивід у зворотному порядку
    cout << "Зворотний порядок:\n";
    for (list<int>::reverse_iterator rit = L.rbegin(); rit != L.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
