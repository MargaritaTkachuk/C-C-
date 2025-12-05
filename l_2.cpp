#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

    void expand() {
        int newCap = capacity * 2;
        T* newArr = new T[newCap];
        for (int i = 0; i < capacity; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCap;
    }

public:
    Stack(int cap = 10) : capacity(cap), topIndex(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& value) {
        if (topIndex + 1 == capacity)
            expand();
        arr[++topIndex] = value;
    }

    T pop() {
        if (topIndex < 0) throw runtime_error("Stack empty");
        return arr[topIndex--];
    }

    bool empty() const {
        return topIndex < 0;
    }
};


int readArray(int*& outArr) {
    Stack<int> tmp;
    int x;

    cout << "Вводьте числа (0 — кінець): ";
    while (true) {
        cin >> x;
        if (x == 0) break;
        tmp.push(x);
    }

    // Переносимо стек у масив у правильному порядку
    int size = 0;

    // Спочатку переносимо в інший стек щоб розвернути
    Stack<int> reverseStack;
    while (!tmp.empty())
        reverseStack.push(tmp.pop());

    // Створюємо динамічний масив
    outArr = new int[1000];

    while (!reverseStack.empty())
        outArr[size++] = reverseStack.pop();

    return size;
}

int main() {
    int* arr;
    int n = readArray(arr);

    cout << "\nВведений масив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";


    cout << "Перевірка std::stack<int>: ";
    stack<int> st1;
    for (int i = 0; i < n; i++)
        st1.push(arr[i]);

    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << "\n\n";


    cout << "Перевірка власного Stack<int>: ";
    Stack<int> st2;
    for (int i = 0; i < n; i++)
        st2.push(arr[i]);

    while (!st2.empty()) {
        cout << st2.pop() << " ";
    }
    cout << "\n\n";


    cout << "Перевірка Stack<double>: ";
    Stack<double> st3;
    st3.push(1.5);
    st3.push(3.14);
    st3.push(-0.5);

    while (!st3.empty()) {
        cout << st3.pop() << " ";
    }
    cout << "\n";

    delete[] arr;
    return 0;
}
