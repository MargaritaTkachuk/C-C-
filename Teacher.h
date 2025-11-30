#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher : virtual public Person {
protected:
    string university;
    string position;
    double salary;
public:
    Teacher();
    Teacher(const string& name, const string& gender, int age, const string& university, const string& position, double salary);

    void input() override;
    void print() const override;
    
    string getUniversity() const override { return university; }
};

#endif