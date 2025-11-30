#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    unsigned byear;
public:
    Person();
    Person(const string& n, unsigned y);
    virtual ~Person();
    
    virtual int input();
    virtual void show() const;
    
    string getName() const;
    unsigned getBirthYear() const;
    void setName(const string& n);
    void setBirthYear(unsigned y);
    
    friend ostream& operator<<(ostream& os, const Person& p);
    friend istream& operator>>(istream& is, Person& p);
};

#endif