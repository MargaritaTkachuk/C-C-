#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Friend.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class PhoneBook {
private:
    vector<Friend> friends;
    string filename;
    static const int MAX_SIZE = 100;
    
public:
    PhoneBook(const string& fname = "contacts.txt");
    ~PhoneBook();
    
    void loadFromFile();
    void saveToFile();
    void addFriend();
    void findPhoneByName() const;
    void changePhone();
    void removeFriend();
    void showAll() const;
};

#endif