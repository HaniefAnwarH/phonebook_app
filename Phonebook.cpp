#include "Phonebook.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Phonebook::Phonebook() {
    currentSize = 0;
}

void Phonebook::addContact(const Person& person) {
    contacts.push_back(person);
    currentSize++;
    cout << "\nContact added successfully!" << endl;
}

bool Phonebook::editContact(int index, const Person& person) {
    if (index < 0 || index >= currentSize) {
        cout << "\nInvalid contact index!" << endl;
        return false;
    }
    contacts[index] = person;
    cout << "\nContact updated successfully!" << endl;
    return true;
}

bool Phonebook::deleteContact(int index) {
    if (index < 0 || index >= currentSize) {
        cout << "\nInvalid contact index!" << endl;
        return false;
    }
    contacts.erase(contacts.begin() + index);
    currentSize--;
    cout << "\nContact deleted successfully!" << endl;
    return true;
}

void Phonebook::viewAllContacts() const {
    if (isEmpty()) {
        cout << "\nPhonebook is empty!" << endl;
        return;
    }
    
    cout << "\n" << string(80, '=') << endl;
    cout << "                         ALL CONTACTS                           " << endl;
    cout << string(80, '=') << endl;
    
    for (int i = 0; i < currentSize; i++) {
        cout << "\n[" << (i + 1) << "] ";
        contacts[i].print();
        if (i < currentSize - 1) {
            cout << string(80, '-') << endl;
        }
    }
    cout << string(80, '=') << endl;
}

vector<Person> Phonebook::searchContact(const string& keyword) const {
    vector<Person> results;
    string lowerKeyword = keyword;
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);
    
    for (const auto& contact : contacts) {
        string fullName = contact.getFullName();
        string phone = contact.getPhoneNumber();
        
        transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);
        
        if (fullName.find(lowerKeyword) != string::npos || 
            phone.find(keyword) != string::npos) {
            results.push_back(contact);
        }
    }
    
    return results;
}

Person Phonebook::getContact(int index) const {
    if (index >= 0 && index < currentSize) {
        return contacts[index];
    }
    return Person();
}

int Phonebook::getSize() const {
    return currentSize;
}

bool Phonebook::isEmpty() const {
    return currentSize == 0;
}

void Phonebook::clear() {
    contacts.clear();
    currentSize = 0;
}

vector<Person>& Phonebook::getContacts() {
    return contacts;
}