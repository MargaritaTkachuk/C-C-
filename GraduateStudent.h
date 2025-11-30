#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H
#include "Student.h"
#include "Teacher.h"

class GraduateStudent : public Student, public Teacher {
private:
    string researchTopic;
public:
    GraduateStudent();
    GraduateStudent(const string& name, const string& gender, int age, 
                   int course, const string& group, const string& university,
                   const string& position, double salary, const string& researchTopic);

    void input() override;
    void print() const override;
    
    // Вирішення неоднозначності - явно вказуємо яке поле використовувати
    string getUniversity() const override { return Student::university; }
};

#endif