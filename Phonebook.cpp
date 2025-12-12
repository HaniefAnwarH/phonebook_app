/**
 * Phonebook Pro Application - Enhanced Version
 * Phonebook.cpp - Complete Implementation
 */

#include "Phonebook.h"
#include "Colors.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Constructor
Phonebook::Phonebook() {
    currentSize = 0;
}

// Basic CRUD Operations
void Phonebook::addContact(const Person& person) {
    contacts.push_back(person);
    currentSize++;
    Colors::println("\n✓ Contact added successfully!", Colors::BOLD_GREEN);
}

bool Phonebook::editContact(int index, const Person& person) {
    if (index < 0 || index >= currentSize) {
        Colors::println("\n✗ Invalid contact index!", Colors::BOLD_RED);
        return false;
    }
    contacts[index] = person;
    Colors::println("\n✓ Contact updated successfully!", Colors::BOLD_GREEN);
    return true;
}

bool Phonebook::deleteContact(int index) {
    if (index < 0 || index >= currentSize) {
        Colors::println("\n✗ Invalid contact index!", Colors::BOLD_RED);
        return false;
    }
    contacts.erase(contacts.begin() + index);
    currentSize--;
    Colors::println("\n✓ Contact deleted successfully!", Colors::BOLD_GREEN);
    return true;
}

void Phonebook::viewAllContacts() const {
    if (isEmpty()) {
        Colors::println("\n✗ Phonebook is empty!", Colors::BOLD_RED);
        return;
    }
    
    cout << "\n" << string(85, '=') << endl;
    Colors::println("                         ALL CONTACTS                           ", Colors::BOLD_CYAN);
    cout << string(85, '=') << endl;
    
    for (int i = 0; i < currentSize; i++) {
        Colors::print("\n[" + to_string(i + 1) + "] ", Colors::BOLD_WHITE);
        contacts[i].print();
        if (i < currentSize - 1) {
            cout << string(85, '-') << endl;
        }
    }
    cout << string(85, '=') << endl;
    Colors::print("Total: ", Colors::BOLD_CYAN);
    Colors::println(to_string(currentSize) + " contacts", Colors::BOLD_YELLOW);
}

// Search Operations
vector<Person> Phonebook::searchContact(const string& keyword) const {
    vector<Person> results;
    string lowerKeyword = keyword;
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);
    
    for (const auto& contact : contacts) {
        string fullName = contact.getFullName();
        string phone = contact.getPhoneNumber();
        string email = contact.getEmail();
        
        transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);
        transform(email.begin(), email.end(), email.begin(), ::tolower);
        
        if (fullName.find(lowerKeyword) != string::npos || 
            phone.find(keyword) != string::npos ||
            email.find(lowerKeyword) != string::npos) {
            results.push_back(contact);
        }
    }
    
    return results;
}

vector<Person> Phonebook::advancedSearch(const SearchFilter& filter) const {
    vector<Person> results;
    
    for (const auto& contact : contacts) {
        bool match = true;
        
        // Name filter
        if (!filter.name.empty()) {
            string fullName = contact.getFullName();
            transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);
            string searchName = filter.name;
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
            if (fullName.find(searchName) == string::npos) match = false;
        }
        
        // Phone filter
        if (!filter.phone.empty()) {
            if (contact.getPhoneNumber().find(filter.phone) == string::npos) match = false;
        }
        
        // City filter
        if (!filter.city.empty()) {
            string contactCity = contact.getCity();
            transform(contactCity.begin(), contactCity.end(), contactCity.begin(), ::tolower);
            string searchCity = filter.city;
            transform(searchCity.begin(), searchCity.end(), searchCity.begin(), ::tolower);
            if (contactCity.find(searchCity) == string::npos) match = false;
        }
        
        // Category filter
        if (!filter.category.empty()) {
            if (contact.getCategory() != filter.category) match = false;
        }
        
        // Email filter
        if (!filter.email.empty()) {
            string contactEmail = contact.getEmail();
            transform(contactEmail.begin(), contactEmail.end(), contactEmail.begin(), ::tolower);
            string searchEmail = filter.email;
            transform(searchEmail.begin(), searchEmail.end(), searchEmail.begin(), ::tolower);
            if (contactEmail.find(searchEmail) == string::npos) match = false;
        }
        
        // Age filters
        if (filter.minAge > 0 && contact.getAge() < filter.minAge) match = false;
        if (filter.maxAge > 0 && contact.getAge() > filter.maxAge) match = false;
        
        // Birthday this month
        if (filter.birthdayThisMonth && !contact.isBirthdayThisMonth()) match = false;
        
        // Favorites only
        if (filter.favoritesOnly && !contact.getFavorite()) match = false;
        
        if (match) results.push_back(contact);
    }
    
    return results;
}

Person Phonebook::getContact(int index) const {
    if (index >= 0 && index < currentSize) {
        return contacts[index];
    }
    return Person();
}

// TIER 2 - Statistics Dashboard
void Phonebook::displayStatistics() const {
    if (isEmpty()) {
        Colors::println("\nPhonebook is empty!", Colors::BOLD_RED);
        return;
    }
    
    cout << "\n" << string(75, '=') << endl;
    Colors::println("                    📊 PHONEBOOK STATISTICS", Colors::BOLD_CYAN);
    cout << string(75, '=') << endl;
    
    // Total contacts
    Colors::print("\n📱 Total Contacts: ", Colors::BOLD_WHITE);
    Colors::println(to_string(currentSize), Colors::BOLD_YELLOW);
    
    // Favorites
    int favCount = getFavoritesCount();
    Colors::print("⭐ Favorite Contacts: ", Colors::BOLD_WHITE);
    Colors::println(to_string(favCount), Colors::BOLD_YELLOW);
    
    // Contacts by city
    map<string, int> cityCount = getContactsByCity();
    cout << "\n📍 Contacts by City:" << endl;
    for (const auto& pair : cityCount) {
        Colors::print("   • ", Colors::CYAN);
        cout << pair.first << ": ";
        Colors::println(to_string(pair.second) + " contact(s)", Colors::YELLOW);
    }
    
    // Contacts by category
    map<string, int> catCount = getContactsByCategory();
    cout << "\n🏷️  Contacts by Category:" << endl;
    for (const auto& pair : catCount) {
        Colors::print("   • ", Colors::MAGENTA);
        cout << pair.first << ": ";
        Colors::println(to_string(pair.second) + " contact(s)", Colors::YELLOW);
    }
    
    // Phone analysis
    int has08 = 0, has62 = 0, hasEmail = 0, hasInstagram = 0;
    for (const auto& contact : contacts) {
        string phone = contact.getPhoneNumber();
        if (!phone.empty()) {
            if (phone.substr(0, 2) == "08") has08++;
            if (phone.substr(0, 2) == "62") has62++;
        }
        if (!contact.getEmail().empty()) hasEmail++;
        if (!contact.getInstagram().empty()) hasInstagram++;
    }
    
    cout << "\n📞 Contact Information:" << endl;
    Colors::print("   • ", Colors::GREEN);
    cout << "Local numbers (08xx): ";
    Colors::println(to_string(has08), Colors::YELLOW);
    
    Colors::print("   • ", Colors::GREEN);
    cout << "International (+62): ";
    Colors::println(to_string(has62), Colors::YELLOW);
    
    Colors::print("   • ", Colors::CYAN);
    cout << "With Email: ";
    Colors::println(to_string(hasEmail), Colors::YELLOW);
    
    Colors::print("   • ", Colors::MAGENTA);
    cout << "With Instagram: ";
    Colors::println(to_string(hasInstagram), Colors::YELLOW);
    
    // Birthday stats
    vector<Person> bdayMonth = getBirthdaysThisMonth();
    if (!bdayMonth.empty()) {
        Colors::print("\n🎂 Birthdays This Month: ", Colors::BOLD_YELLOW);
        Colors::println(to_string(bdayMonth.size()), Colors::BOLD_RED);
    }
    
    cout << string(75, '=') << endl;
}

map<string, int> Phonebook::getContactsByCity() const {
    map<string, int> cityCount;
    for (const auto& contact : contacts) {
        cityCount[contact.getCity()]++;
    }
    return cityCount;
}

map<string, int> Phonebook::getContactsByCategory() const {
    map<string, int> catCount;
    for (const auto& contact : contacts) {
        catCount[contact.getCategory()]++;
    }
    return catCount;
}

// TIER 2 - Birthday Features
void Phonebook::checkBirthdayReminders() const {
    vector<Person> todayBirthdays;
    vector<Person> thisMonthBirthdays;
    
    for (const auto& contact : contacts) {
        if (contact.isBirthdayToday()) {
            todayBirthdays.push_back(contact);
        } else if (contact.isBirthdayThisMonth()) {
            thisMonthBirthdays.push_back(contact);
        }
    }
    
    if (!todayBirthdays.empty()) {
        cout << "\n" << string(60, '=') << endl;
        Colors::println("🎉🎉🎉 BIRTHDAY ALERT! 🎉🎉🎉", Colors::BOLD_RED);
        cout << string(60, '=') << endl;
        Colors::println("Today's birthdays:", Colors::BOLD_YELLOW);
        for (const auto& person : todayBirthdays) {
            Colors::print("  🎂 ", Colors::BOLD_RED);
            cout << person.getFullName() << " turns " << person.getAge() << " today!" << endl;
        }
        cout << string(60, '=') << endl;
    }
    
    if (!thisMonthBirthdays.empty()) {
        cout << "\n📅 Upcoming birthdays this month:" << endl;
        for (const auto& person : thisMonthBirthdays) {
            Colors::print("  • ", Colors::YELLOW);
            cout << person.getFullName() << " - " << person.getBirthday();
            cout << " (" << person.getAge() + 1 << " years)" << endl;
        }
        cout << endl;
    }
}

vector<Person> Phonebook::getBirthdaysThisMonth() const {
    vector<Person> results;
    for (const auto& contact : contacts) {
        if (contact.isBirthdayThisMonth()) {
            results.push_back(contact);
        }
    }
    return results;
}

// TIER 2 - Category Features
void Phonebook::viewContactsByCategory(const string& category) const {
    vector<Person> filtered;
    
    for (const auto& contact : contacts) {
        if (contact.getCategory() == category) {
            filtered.push_back(contact);
        }
    }
    
    if (filtered.empty()) {
        Colors::println("\n✗ No contacts found in category: " + category, Colors::BOLD_RED);
        return;
    }
    
    cout << "\n" << string(85, '=') << endl;
    Colors::println("           CONTACTS IN CATEGORY: " + category, Colors::BOLD_CYAN);
    cout << string(85, '=') << endl;
    
    for (size_t i = 0; i < filtered.size(); i++) {
        Colors::print("\n[" + to_string(i + 1) + "] ", Colors::BOLD_WHITE);
        filtered[i].print();
        if (i < filtered.size() - 1) {
            cout << string(85, '-') << endl;
        }
    }
    cout << string(85, '=') << endl;
}

void Phonebook::listAllCategories() const {
    map<string, int> categoryCount = getContactsByCategory();
    
    cout << "\n" << string(60, '=') << endl;
    Colors::println("              🏷️  CONTACT CATEGORIES", Colors::BOLD_CYAN);
    cout << string(60, '=') << endl;
    
    for (const auto& pair : categoryCount) {
        Colors::print("  ", Colors::WHITE);
        
        string cat = pair.first;
        if (cat == "Family") Colors::print("👨‍👩‍👧 ", Colors::BOLD_RED);
        else if (cat == "Friends") Colors::print("👥 ", Colors::BOLD_GREEN);
        else if (cat == "Work") Colors::print("💼 ", Colors::BOLD_BLUE);
        else if (cat == "School") Colors::print("🎓 ", Colors::BOLD_YELLOW);
        else Colors::print("📋 ", Colors::WHITE);
        
        cout << cat << ": ";
        Colors::println(to_string(pair.second) + " contact(s)", Colors::BOLD_YELLOW);
    }
    cout << string(60, '=') << endl;
}

// BONUS - Favorites
void Phonebook::toggleFavorite(int index) {
    if (index >= 0 && index < currentSize) {
        bool currentStatus = contacts[index].getFavorite();
        contacts[index].setFavorite(!currentStatus);
        
        if (!currentStatus) {
            Colors::println("\n⭐ Contact added to favorites!", Colors::BOLD_YELLOW);
        } else {
            Colors::println("\n✓ Contact removed from favorites.", Colors::BOLD_GREEN);
        }
    }
}

void Phonebook::viewFavorites() const {
    vector<Person> favorites;
    
    for (const auto& contact : contacts) {
        if (contact.getFavorite()) {
            favorites.push_back(contact);
        }
    }
    
    if (favorites.empty()) {
        Colors::println("\n✗ No favorite contacts yet!", Colors::BOLD_YELLOW);
        cout << "Tip: Use 'Toggle Favorite' to mark contacts as favorites." << endl;
        return;
    }
    
    cout << "\n" << string(85, '=') << endl;
    Colors::println("                    ⭐ FAVORITE CONTACTS", Colors::BOLD_YELLOW);
    cout << string(85, '=') << endl;
    
    for (size_t i = 0; i < favorites.size(); i++) {
        Colors::print("\n[" + to_string(i + 1) + "] ", Colors::BOLD_WHITE);
        favorites[i].print();
        if (i < favorites.size() - 1) {
            cout << string(85, '-') << endl;
        }
    }
    cout << string(85, '=') << endl;
}

int Phonebook::getFavoritesCount() const {
    int count = 0;
    for (const auto& contact : contacts) {
        if (contact.getFavorite()) count++;
    }
    return count;
}

// Utility Methods
int Phonebook::getSize() const { return currentSize; }
bool Phonebook::isEmpty() const { return currentSize == 0; }

void Phonebook::clear() {
    contacts.clear();
    currentSize = 0;
}

vector<Person>& Phonebook::getContacts() {
    return contacts;
}

// Sorting Methods
void Phonebook::sortByName() {
    sort(contacts.begin(), contacts.end(), [](const Person& a, const Person& b) {
        return a.getFullName() < b.getFullName();
    });
    Colors::println("\n✓ Contacts sorted by name!", Colors::BOLD_GREEN);
}

void Phonebook::sortByCity() {
    sort(contacts.begin(), contacts.end(), [](const Person& a, const Person& b) {
        return a.getCity() < b.getCity();
    });
    Colors::println("\n✓ Contacts sorted by city!", Colors::BOLD_GREEN);
}

void Phonebook::sortByAge() {
    sort(contacts.begin(), contacts.end(), [](const Person& a, const Person& b) {
        return a.getAge() > b.getAge();
    });
    Colors::println("\n✓ Contacts sorted by age!", Colors::BOLD_GREEN);
}
