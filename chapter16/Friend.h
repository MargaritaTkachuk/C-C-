#ifndef FRIEND_H
#define FRIEND_H

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

class Friend : public Person {
private:
    string phone;
public:
    Friend();
    Friend(const string& n, unsigned y, const string& p);
    
    int input() override;
    void show() const override;
    
    string getPhone() const;
    void setPhone(const string& p);
    
    friend ostream& operator<<(ostream& os, const Friend& f);
    friend istream& operator>>(istream& is, Friend& f);
};

#endif