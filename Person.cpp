#include "Person.h"
#include <iomanip>
#include <sstream>

Person::Person() {
    firstName = "";
    lastName = "";
    phoneNumber = "";
    address = "";
    city = "";
}

Person::Person(string first, string last, string phone, string addr, string cityName) {
    firstName = first;
    lastName = last;
    phoneNumber = phone;
    address = addr;
    city = cityName;
}

void Person::setFirstName(string first) {
    firstName = first;
}

void Person::setLastName(string last) {
    lastName = last;
}

void Person::setPhoneNumber(string phone) {
    phoneNumber = phone;
}

void Person::setAddress(string addr) {
    address = addr;
}

void Person::setCity(string cityName) {
    city = cityName;
}

string Person::getFirstName() const {
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

string Person::getPhoneNumber() const {
    return phoneNumber;
}

string Person::getAddress() const {
    return address;
}

string Person::getCity() const {
    return city;
}

string Person::getFullName() const {
    return firstName + " " + lastName;
}

void Person::print() const {
    cout << "Name        : " << getFullName() << endl;
    cout << "Phone       : " << phoneNumber << endl;
    cout << "Address     : " << address << endl;
    cout << "City        : " << city << endl;
}

string Person::toString() const {
    return firstName + "|" + lastName + "|" + phoneNumber + "|" + address + "|" + city;
}