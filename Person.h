/**
 * Phonebook Pro Application - Enhanced Version
 * Person.h - Enhanced Person Class with Birthday, Email, Social Media, Categories
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    // Basic Information
    string firstName;
    string lastName;
    string phoneNumber;
    string address;
    string city;
    
    // Enhanced Features - Tier 2
    string email;
    string instagram;
    string whatsapp;
    string birthday;        // Format: DD/MM/YYYY
    string category;        // Family, Friends, Work, School, etc.
    
    // Bonus Features
    bool isFavorite;

public:
    // Constructors
    Person();
    Person(string first, string last, string phone, string addr, string city);
    
    // Basic Setters
    void setFirstName(string first);
    void setLastName(string last);
    void setPhoneNumber(string phone);
    void setAddress(string addr);
    void setCity(string cityName);
    
    // Enhanced Setters - Tier 2
    void setEmail(string mail);
    void setInstagram(string ig);
    void setWhatsapp(string wa);
    void setBirthday(string bday);
    void setCategory(string cat);
    
    // Bonus Setters
    void setFavorite(bool fav);
    
    // Basic Getters
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    string getAddress() const;
    string getCity() const;
    string getFullName() const;
    
    // Enhanced Getters - Tier 2
    string getEmail() const;
    string getInstagram() const;
    string getWhatsapp() const;
    string getBirthday() const;
    string getCategory() const;
    
    // Bonus Getters
    bool getFavorite() const;
    
    // Birthday Functions
    int getAge() const;
    bool isBirthdayToday() const;
    bool isBirthdayThisMonth() const;
    
    // Validation
    bool isValidEmail(const string& email) const;
    
    // Display methods
    void print() const;
    string toString() const;
    string toCSV() const;
    string toVCF() const;
};

#endif
