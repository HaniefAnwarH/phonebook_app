#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string address;
    string city;

public:
    Person();
    Person(string first, string last, string phone, string addr, string city);
    
    void setFirstName(string first);
    void setLastName(string last);
    void setPhoneNumber(string phone);
    void setAddress(string addr);
    void setCity(string cityName);
    
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    string getAddress() const;
    string getCity() const;
    string getFullName() const;
    
    void print() const;
    string toString() const;
};

#endif