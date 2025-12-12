#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Person.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

// Search Filter Structure
struct SearchFilter {
    string name;
    string phone;
    string city;
    string category;
    string email;
    int minAge;
    int maxAge;
    bool birthdayThisMonth;
    bool favoritesOnly;
};

class Phonebook {
private:
    vector<Person> contacts;
    int currentSize;

public:
    // Constructor
    Phonebook();
    
    // Basic CRUD operations
    void addContact(const Person& person);
    bool editContact(int index, const Person& person);
    bool deleteContact(int index);
    void viewAllContacts() const;
    
    // Search operations
    vector<Person> searchContact(const string& keyword) const;
    vector<Person> advancedSearch(const SearchFilter& filter) const;
    Person getContact(int index) const;
    
    // Tier 2 Features - Statistics
    void displayStatistics() const;
    map<string, int> getContactsByCity() const;
    map<string, int> getContactsByCategory() const;
    
    // Tier 2 Features - Birthday
    void checkBirthdayReminders() const;
    vector<Person> getBirthdaysThisMonth() const;
    
    // Tier 2 Features - Categories
    void viewContactsByCategory(const string& category) const;
    void listAllCategories() const;
    
    // Bonus Features - Favorites
    void toggleFavorite(int index);
    void viewFavorites() const;
    int getFavoritesCount() const;
    
    // Utility methods
    int getSize() const;
    bool isEmpty() const;
    void clear();
    vector<Person>& getContacts();
    
    // Sorting
    void sortByName();
    void sortByCity();
    void sortByAge();
};

#endif
