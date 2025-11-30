#include "Car.h"
#include <iostream>

using namespace std;

void testCar() {
    cout << "ТЕСТУВАННЯ АВТОМОБІЛІВ\n\n";

    Personal car("Toyota Camry", 50, 60);
    cout << "Створено легковий автомобіль:\n";
    car.info();

    cout << "\nТестування з різною кількістю пасажирів:\n";

    cout << "\nБез пасажирів:\n";
    car.setPassengers(0);
    car.go(100);
    car.info();

    cout << "\nЗ 2 пасажирами:\n";
    car.setPassengers(2);
    car.refuel(30);
    car.go(100);
    car.info();

    cout << "\nЗ 4 пасажирами:\n";
    car.setPassengers(4);
    car.refuel(40);
    car.go(100);
    car.info();

    cout << "\nТестування вантажівки:\n";
    Truck truck("Volvo FH16", 200, 300);
    cout << "Створено вантажівку:\n";
    truck.info();

    cout << "\nБез вантажу:\n";
    truck.setCargo(0);
    truck.go(200);
    truck.info();

    cout << "\nЗ вантажем 5 тонн:\n";
    truck.setCargo(5);
    truck.refuel(100);
    truck.go(200);
    truck.info();

    cout << "\nТест на неможливість поїздки:\n";
    truck.setCargo(15);
    truck.refuel(10);
    truck.go(100);
    truck.info();
}

int main() {
    testCar();
    return 0;
}