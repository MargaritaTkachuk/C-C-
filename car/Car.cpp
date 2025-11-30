#include "Car.h"

Car::Car(const string& m, double fuel, double capacity) 
    : model(m), totalDistance(0), fuelAmount(fuel), tankCapacity(capacity) {}

bool Car::go(double distance) {
    double requiredFuel = distance * fuelPerKm();
    
    if (requiredFuel <= fuelAmount) {
        fuelAmount -= requiredFuel;
        totalDistance += distance;
        cout << model << " проїхав " << distance << " км. Витрачено: " 
             << requiredFuel << " л. Залишок пального: " << fuelAmount << " л.\n";
        return true;
    } else {
        double maxDistance = fuelAmount / fuelPerKm();
        cout << model << " не може проїхати " << distance << " км. "
             << "Максимально можлива відстань: " << maxDistance << " км.\n";
        return false;
    }
}

void Car::refuel(double amount) {
    if (amount <= 0) {
        cout << "Помилка: Кількість пального має бути додатньою!\n";
        return;
    }
    
    if (fuelAmount + amount > tankCapacity) {
        double actualAmount = tankCapacity - fuelAmount;
        fuelAmount = tankCapacity;
        cout << "Заправлено " << actualAmount << " л (бак заповнений).\n";
    } else {
        fuelAmount += amount;
        cout << "Заправлено " << amount << " л. Тепер у баку: " << fuelAmount << " л.\n";
    }
}

void Car::info() const {
    cout << model << " | Пробіг: " << totalDistance 
         << " км | Пального: " << fuelAmount << " л\n";
}

Personal::Personal(const string& m, double fuel, double capacity, int pass)
    : Car(m, fuel, capacity), passengers(pass) {}

double Personal::fuelPerKm() const {
    double baseConsumption = 0.08;
    double multiplier = 1.0 + (passengers * 0.10);
    return baseConsumption * multiplier;
}

void Personal::setPassengers(int pass) {
    if (pass >= 0 && pass <= 4) {
        passengers = pass;
        cout << "Кількість пасажирів встановлено: " << passengers << "\n";
    } else {
        cout << "Помилка: Недійсна кількість пасажирів (0-4)!\n";
    }
}

void Personal::info() const {
    cout << model << " (легковий) | Пасажири: " << passengers 
         << " | Пробіг: " << totalDistance << " км | Пального: " << fuelAmount 
         << " л | Витрата: " << fuelPerKm() * 100 << " л/100км\n";
}

Truck::Truck(const string& m, double fuel, double capacity, double cargo)
    : Car(m, fuel, capacity), cargoWeight(cargo) {}

double Truck::fuelPerKm() const {
    double baseConsumption = 0.25;
    double multiplier = 1.0 + (cargoWeight * 0.25);
    return baseConsumption * multiplier;
}

void Truck::setCargo(double weight) {
    if (weight >= 0 && weight <= 20) {
        cargoWeight = weight;
        cout << "Вага вантажу встановлена: " << cargoWeight << " т\n";
    } else {
        cout << "Помилка: Недійсна вага вантажу (0-20 т)!\n";
    }
}

void Truck::info() const {
    cout << model << " (вантажівка) | Вантаж: " << cargoWeight 
         << " т | Пробіг: " << totalDistance << " км | Пального: " << fuelAmount 
         << " л | Витрата: " << fuelPerKm() * 100 << " л/100км\n";
}