#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

using namespace std;

class Car {
protected:
    string model;
    double totalDistance;  // загальний пробіг
    double fuelAmount;     // поточна кількість пального
    double tankCapacity;   // місткість бака

public:
    Car(const string& m, double fuel, double capacity);
    virtual ~Car() = default;
    
    // Віртуальний метод, який буде перевизначено в похідних класах
    virtual double fuelPerKm() const = 0;
    
    // Метод для поїздки
    bool go(double distance);
    
    // Допоміжні методи
    void refuel(double amount);
    double getFuel() const { return fuelAmount; }
    double getDistance() const { return totalDistance; }
    string getModel() const { return model; }
    
    virtual void info() const;
};

class Personal : public Car {
private:
    int passengers;  // кількість пасажирів

public:
    Personal(const string& m, double fuel, double capacity, int pass = 0);
    
    // Перевизначення віртуального методу
    double fuelPerKm() const override;
    
    void setPassengers(int pass);
    int getPassengers() const { return passengers; }
    
    void info() const override;
};

class Truck : public Car {
private:
    double cargoWeight;  // вага вантажу в тонах

public:
    Truck(const string& m, double fuel, double capacity, double cargo = 0);
    
    // Перевизначення віртуального методу
    double fuelPerKm() const override;
    
    void setCargo(double weight);
    double getCargo() const { return cargoWeight; }
    
    void info() const override;
};

#endif