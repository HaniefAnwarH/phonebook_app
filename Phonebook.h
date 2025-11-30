#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class Phonebook {
private:
    vector<Person> contacts;
    int currentSize;

public:
    Phonebook();
    
    void addContact(const Person& person);
    bool editContact(int index, const Person& person);
    bool deleteContact(int index);
    void viewAllContacts() const;
    
    vector<Person> searchContact(const string& keyword) const;
    Person getContact(int index) const;
    
    int getSize() const;
    bool isEmpty() const;
    void clear();
    
    vector<Person>& getContacts();
};

#endif