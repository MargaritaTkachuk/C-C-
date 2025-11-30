#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string gender;
    int age;

public:
    Person();
    Person(const string& name, const string& gender, int age);

    virtual void input();
    virtual void print() const;

    virtual string getUniversity() const { return "Немає даних"; }

    virtual ~Person() {}
};

#endif