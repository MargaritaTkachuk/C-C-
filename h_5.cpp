#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;

public:
    // Конструктор
    Array(int n = 0) : size(n) {
        if (n < 0) throw runtime_error("Invalid size");
        data = (n > 0) ? new T[n] : nullptr;
    }

    // Конструктор копіювання
    Array(const Array& other) : size(other.size) {
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Оператор доступу
    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw runtime_error("Index out of bounds");
        return data[index];
    }

    int getSize() const { return size; }


    // 1) Метод класу: сортує this->data
    void selectionSort() {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (data[j] < data[minIndex])
                    minIndex = j;
            }
            swap(data[i], data[minIndex]);
        }
    }

    // 2) Статичний метод (in-place)
    static void selectionSort(T* arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Метод для заповнення масиву
    void input() {
        cout << "Введіть " << size << " елементів:\n";
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }

    // Метод для виведення
    void print() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Array<int> arr(5);

    arr.input();

    cout << "\nМасив до сортування: ";
    arr.print();

    // Сортування методом класу
    arr.selectionSort();
    cout << "Після selectionSort(): ";
    arr.print();

    // Тест статичного сортування
    int a[6] = {5, -1, 12, 3, 2, 0};
    cout << "\nСтатичне сортування масиву a: ";
    Array<int>::selectionSort(a, 6);

    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
