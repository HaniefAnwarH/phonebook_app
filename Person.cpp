/**
 * Phonebook Pro Application - Enhanced Version
 * Person.cpp - Complete Implementation with All Features
 */

#include "Person.h"
#include "Colors.h"
#include <iomanip>
#include <sstream>
#include <ctime>
#include <algorithm>

// Constructors
Person::Person() {
    firstName = "";
    lastName = "";
    phoneNumber = "";
    address = "";
    city = "";
    email = "";
    instagram = "";
    whatsapp = "";
    birthday = "";
    category = "General";
    isFavorite = false;
}

Person::Person(string first, string last, string phone, string addr, string cityName) {
    firstName = first;
    lastName = last;
    phoneNumber = phone;
    address = addr;
    city = cityName;
    email = "";
    instagram = "";
    whatsapp = phone; // Default WhatsApp to phone number
    birthday = "";
    category = "General";
    isFavorite = false;
}

// Basic Setters
void Person::setFirstName(string first) { firstName = first; }
void Person::setLastName(string last) { lastName = last; }
void Person::setPhoneNumber(string phone) { phoneNumber = phone; }
void Person::setAddress(string addr) { address = addr; }
void Person::setCity(string cityName) { city = cityName; }

// Enhanced Setters
void Person::setEmail(string mail) { email = mail; }
void Person::setInstagram(string ig) { instagram = ig; }
void Person::setWhatsapp(string wa) { whatsapp = wa; }
void Person::setBirthday(string bday) { birthday = bday; }
void Person::setCategory(string cat) { category = cat; }

// Bonus Setters
void Person::setFavorite(bool fav) { isFavorite = fav; }

// Basic Getters
string Person::getFirstName() const { return firstName; }
string Person::getLastName() const { return lastName; }
string Person::getPhoneNumber() const { return phoneNumber; }
string Person::getAddress() const { return address; }
string Person::getCity() const { return city; }
string Person::getFullName() const { return firstName + " " + lastName; }

// Enhanced Getters
string Person::getEmail() const { return email; }
string Person::getInstagram() const { return instagram; }
string Person::getWhatsapp() const { return whatsapp.empty() ? phoneNumber : whatsapp; }
string Person::getBirthday() const { return birthday; }
string Person::getCategory() const { return category.empty() ? "General" : category; }

// Bonus Getters
bool Person::getFavorite() const { return isFavorite; }

// Birthday Functions
int Person::getAge() const {
    if (birthday.empty()) return 0;
    
    int day, month, year;
    char delimiter;
    stringstream ss(birthday);
    ss >> day >> delimiter >> month >> delimiter >> year;
    
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    
    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--;
    }
    
    return age;
}

bool Person::isBirthdayToday() const {
    if (birthday.empty()) return false;
    
    int day, month, year;
    char delimiter;
    stringstream ss(birthday);
    ss >> day >> delimiter >> month >> delimiter >> year;
    
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    
    return (day == currentDay && month == currentMonth);
}

bool Person::isBirthdayThisMonth() const {
    if (birthday.empty()) return false;
    
    int day, month, year;
    char delimiter;
    stringstream ss(birthday);
    ss >> day >> delimiter >> month >> delimiter >> year;
    
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentMonth = 1 + ltm->tm_mon;
    
    return (month == currentMonth);
}

// Email Validation
bool Person::isValidEmail(const string& email) const {
    if (email.empty()) return true;
    
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);
    
    return (atPos != string::npos && 
            dotPos != string::npos && 
            atPos > 0 && 
            dotPos > atPos + 1 && 
            dotPos < email.length() - 1);
}

// Enhanced Print with Colors
void Person::print() const {
    // Name with favorite star
    if (isFavorite) {
        Colors::print("⭐ ", Colors::BOLD_YELLOW);
    } else {
        cout << "   ";
    }
    
    Colors::print("Name        : ", Colors::BOLD_CYAN);
    cout << getFullName();
    
    if (!birthday.empty()) {
        Colors::print(" (Age: ", Colors::YELLOW);
        cout << getAge();
        Colors::print(")", Colors::YELLOW);
        
        if (isBirthdayToday()) {
            Colors::print(" 🎂 BIRTHDAY TODAY!", Colors::BOLD_RED);
        }
    }
    cout << endl;
    
    // Category with color coding
    Colors::print("   Category    : ", Colors::BOLD_MAGENTA);
    string cat = getCategory();
    if (cat == "Family") Colors::print("👨‍👩‍👧 " + cat, Colors::BOLD_RED);
    else if (cat == "Friends") Colors::print("👥 " + cat, Colors::BOLD_GREEN);
    else if (cat == "Work") Colors::print("💼 " + cat, Colors::BOLD_BLUE);
    else if (cat == "School") Colors::print("🎓 " + cat, Colors::BOLD_YELLOW);
    else Colors::print("📋 " + cat, Colors::WHITE);
    cout << endl;
    
    // Phone
    Colors::print("   Phone       : ", Colors::GREEN);
    cout << phoneNumber << endl;
    
    // WhatsApp
    if (!whatsapp.empty() && whatsapp != phoneNumber) {
        Colors::print("   WhatsApp    : ", Colors::GREEN);
        cout << whatsapp << " 💬" << endl;
    }
    
    // Email with validation indicator
    if (!email.empty()) {
        Colors::print("   Email       : ", Colors::CYAN);
        cout << email;
        if (isValidEmail(email)) {
            Colors::print(" ✓", Colors::BOLD_GREEN);
        } else {
            Colors::print(" ⚠️ Invalid", Colors::BOLD_RED);
        }
        cout << endl;
    }
    
    // Instagram
    if (!instagram.empty()) {
        Colors::print("   Instagram   : ", Colors::MAGENTA);
        cout << "@" << instagram << " 📷" << endl;
    }
    
    // Address & City
    Colors::print("   Address     : ", Colors::YELLOW);
    cout << address << endl;
    
    Colors::print("   City        : ", Colors::MAGENTA);
    cout << city << endl;
    
    // Birthday
    if (!birthday.empty()) {
        Colors::print("   Birthday    : ", Colors::BOLD_YELLOW);
        cout << birthday << endl;
    }
}

// File format conversions
string Person::toString() const {
    return firstName + "|" + lastName + "|" + phoneNumber + "|" + 
           address + "|" + city + "|" + email + "|" + instagram + "|" + 
           whatsapp + "|" + birthday + "|" + category + "|" + 
           (isFavorite ? "1" : "0");
}

string Person::toCSV() const {
    return "\"" + firstName + "\",\"" + lastName + "\",\"" + phoneNumber + "\",\"" +
           whatsapp + "\",\"" + email + "\",\"" + instagram + "\",\"" +
           address + "\",\"" + city + "\",\"" + birthday + "\"," +
           to_string(getAge()) + ",\"" + category + "\"," +
           (isFavorite ? "Yes" : "No");
}

string Person::toVCF() const {
    stringstream vcf;
    vcf << "BEGIN:VCARD\n";
    vcf << "VERSION:3.0\n";
    vcf << "FN:" << getFullName() << "\n";
    vcf << "N:" << lastName << ";" << firstName << ";;;\n";
    vcf << "TEL;TYPE=CELL:" << phoneNumber << "\n";
    
    if (!email.empty()) {
        vcf << "EMAIL:" << email << "\n";
    }
    
    if (!address.empty()) {
        vcf << "ADR:;;" << address << ";" << city << ";;;;\n";
    }
    
    if (!birthday.empty()) {
        string bday = birthday;
        string year = bday.substr(6, 4);
        string month = bday.substr(3, 2);
        string day = bday.substr(0, 2);
        vcf << "BDAY:" << year << "-" << month << "-" << day << "\n";
    }
    
    if (!category.empty()) {
        vcf << "CATEGORIES:" << category << "\n";
    }
    
    vcf << "END:VCARD\n";
    return vcf.str();
}
