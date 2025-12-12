#include <iostream>
#include <limits>
#include "Person.h"
#include "Phonebook.h"
#include "FileManager.h"
#include "Colors.h"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

using namespace std;

class PhonebookApp {
private:
    Phonebook phonebook;
    FileManager fileManager;
    
    void clearScreen() {
        system(CLEAR_SCREEN);
    }
    
    void enableUTF8() {
        #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        #endif
    }
    
    void showWelcomeBanner() {
        clearScreen();
        cout << Colors::BOLD_CYAN << "\n";
        cout << "  +===============================================================+\n";
        cout << "  |                                                               |\n";
        cout << "  |              " << Colors::BOLD_YELLOW << "    PHONEBOOK PRO    " << Colors::BOLD_CYAN << "                            |\n";
        cout << "  |                                                               |\n";
        cout << "  |            " << Colors::BOLD_WHITE << "Universitas Gadjah Mada - 2025" << Colors::BOLD_CYAN << "                     |\n";
        cout << "  |          " << Colors::WHITE << "Teknik Elektro & Teknologi Informasi" << Colors::BOLD_CYAN << "                 |\n";
        cout << "  |                                                               |\n";
        cout << "  +===============================================================+\n";
        cout << Colors::RESET << "\n";
        
        // Loading animation
        Colors::print("  Loading", Colors::CYAN);
        for (int i = 0; i < 3; i++) {
            cout << "." << flush;
            for (int j = 0; j < 100000000; j++); // Simple delay
        }
        Colors::println(" Done!", Colors::BOLD_GREEN);
        cout << "\n";
    }
    
    void displayMenu() {
        cout << "\n" << string(75, '=') << endl;
        Colors::println("                        MAIN MENU", Colors::BOLD_CYAN);
        cout << string(75, '=') << endl;
        
        // Quick stats
        Colors::print("  [i] Contacts: ", Colors::WHITE);
        Colors::print(to_string(phonebook.getSize()), Colors::BOLD_YELLOW);
        Colors::print("  |  [*] Favorites: ", Colors::WHITE);
        Colors::print(to_string(phonebook.getFavoritesCount()), Colors::BOLD_YELLOW);
        cout << endl;
        
        cout << "\n" << string(75, '-') << endl;
        Colors::println("  CONTACT MANAGEMENT", Colors::BOLD_CYAN);
        cout << string(75, '-') << endl;
        
        Colors::print("  1. ", Colors::BOLD_GREEN);
        cout << "[+] Add New Contact" << endl;
        
        Colors::print("  2. ", Colors::BOLD_YELLOW);
        cout << "[~] Edit Contact" << endl;
        
        Colors::print("  3. ", Colors::BOLD_RED);
        cout << "[-] Delete Contact" << endl;
        
        Colors::print("  4. ", Colors::BOLD_BLUE);
        cout << "[=] View All Contacts" << endl;
        
        Colors::print("  5. ", Colors::BOLD_MAGENTA);
        cout << "[?] Quick Search" << endl;
        
        Colors::print("  6. ", Colors::BOLD_CYAN);
        cout << "[?] Advanced Search " << endl;
        
        cout << "\n" << string(75, '-') << endl;
        Colors::println("  ORGANIZATION & ANALYSIS ", Colors::BOLD_CYAN);
        cout << string(75, '-') << endl;
        
        Colors::print("  7. ", Colors::BOLD_MAGENTA);
        cout << "[#] View Statistics Dashboard" << endl;
        
        Colors::print("  8. ", Colors::BOLD_CYAN);
        cout << "[@] View by Category" << endl;
        
        Colors::print("  9. ", Colors::BOLD_YELLOW);
        cout << "[%] List All Categories" << endl;
        
        Colors::print(" 10. ", Colors::BOLD_GREEN);
        cout << "[!] Birthday Reminders" << endl;
        
        cout << "\n" << string(75, '-') << endl;
        Colors::println("  FILE OPERATIONS ", Colors::BOLD_CYAN);
        cout << string(75, '-') << endl;
        
        Colors::print(" 11. ", Colors::BOLD_GREEN);
        cout << "[<] Load from File" << endl;
        
        Colors::print(" 12. ", Colors::BOLD_BLUE);
        cout << "[>] Save to File" << endl;   
        
        Colors::print(" 13. ", Colors::BOLD_YELLOW);
        cout << "[*] View Favorites" << endl;
        
        Colors::print(" 14. ", Colors::BOLD_MAGENTA);
        cout << "[*] Toggle Favorite" << endl;
        
        Colors::print(" 15. ", Colors::BOLD_CYAN);
        cout << "[v] Sort Contacts" << endl;
        
        cout << "\n" << string(75, '-') << endl;
        Colors::print("  0. ", Colors::BOLD_RED);
        cout << "[X] Exit Application" << endl;
        
        cout << string(75, '=') << endl;
        Colors::print("\n  Select option [0-15]: ", Colors::BOLD_WHITE);
    }
    
    void handleAddContact() {
        clearScreen();
        cout << "\n" << string(70, '=') << endl;
        Colors::println("                  [+] ADD NEW CONTACT", Colors::BOLD_GREEN);
        cout << string(70, '=') << endl;
        
        string firstName, lastName, phone, address, city;
        string email, instagram, whatsapp, birthday, category;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Basic information
        Colors::print("\n[i] Basic Information:\n", Colors::BOLD_CYAN);
        cout << "  First Name     : ";
        getline(cin, firstName);
        cout << "  Last Name      : ";
        getline(cin, lastName);
        
        // Contact methods
        Colors::print("\n[#] Contact Methods:\n", Colors::BOLD_CYAN);
        cout << "  Phone Number   : ";
        getline(cin, phone);
        cout << "  WhatsApp       : ";
        getline(cin, whatsapp);
        if (whatsapp.empty()) whatsapp = phone;
        
        cout << "  Email          : ";
        getline(cin, email);
        
        cout << "  Instagram (@)  : ";
        getline(cin, instagram);
        
        // Location
        Colors::print("\n[@] Location:\n", Colors::BOLD_CYAN);
        cout << "  Address        : ";
        getline(cin, address);
        cout << "  City           : ";
        getline(cin, city);
        
        // Additional info
        Colors::print("\n[!] Additional Info:\n", Colors::BOLD_CYAN);
        cout << "  Birthday (DD/MM/YYYY): ";
        getline(cin, birthday);
        
        cout << "\n  Categories: Family, Friends, Work, School, General\n";
        cout << "  Category       : ";
        getline(cin, category);
        if (category.empty()) category = "General";
        
        // Create and add person
        Person newPerson(firstName, lastName, phone, address, city);
        newPerson.setEmail(email);
        newPerson.setInstagram(instagram);
        newPerson.setWhatsapp(whatsapp);
        newPerson.setBirthday(birthday);
        newPerson.setCategory(category);
        
        // Email validation warning
        if (!email.empty() && !newPerson.isValidEmail(email)) {
            Colors::println("\n[!] Warning: Email format may be invalid!", Colors::BOLD_YELLOW);
            cout << "Continue anyway? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm != 'y' && confirm != 'Y') {
                Colors::println("Contact not added.", Colors::YELLOW);
                return;
            }
        }
        
        phonebook.addContact(newPerson);
    }
    
    void handleEditContact() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        phonebook.viewAllContacts();
        
        cout << "\nEnter contact number to edit (1-" << phonebook.getSize() << "): ";
        int index;
        cin >> index;
        index--;
        
        if (index < 0 || index >= phonebook.getSize()) {
            Colors::println("\n[X] Invalid contact number!", Colors::BOLD_RED);
            return;
        }
        
        clearScreen();
        cout << "\n" << string(70, '=') << endl;
        Colors::println("                  [~] EDIT CONTACT", Colors::BOLD_YELLOW);
        cout << string(70, '=') << endl;
        Colors::println("Press Enter to keep current value", Colors::CYAN);
        
        Person current = phonebook.getContact(index);
        string firstName, lastName, phone, address, city;
        string email, instagram, whatsapp, birthday, category;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "\nFirst Name [" << current.getFirstName() << "]: ";
        getline(cin, firstName);
        if (firstName.empty()) firstName = current.getFirstName();
        
        cout << "Last Name [" << current.getLastName() << "]: ";
        getline(cin, lastName);
        if (lastName.empty()) lastName = current.getLastName();
        
        cout << "Phone [" << current.getPhoneNumber() << "]: ";
        getline(cin, phone);
        if (phone.empty()) phone = current.getPhoneNumber();
        
        cout << "WhatsApp [" << current.getWhatsapp() << "]: ";
        getline(cin, whatsapp);
        if (whatsapp.empty()) whatsapp = current.getWhatsapp();
        
        cout << "Email [" << current.getEmail() << "]: ";
        getline(cin, email);
        if (email.empty()) email = current.getEmail();
        
        cout << "Instagram [" << current.getInstagram() << "]: ";
        getline(cin, instagram);
        if (instagram.empty()) instagram = current.getInstagram();
        
        cout << "Address [" << current.getAddress() << "]: ";
        getline(cin, address);
        if (address.empty()) address = current.getAddress();
        
        cout << "City [" << current.getCity() << "]: ";
        getline(cin, city);
        if (city.empty()) city = current.getCity();
        
        cout << "Birthday [" << current.getBirthday() << "]: ";
        getline(cin, birthday);
        if (birthday.empty()) birthday = current.getBirthday();
        
        cout << "Category [" << current.getCategory() << "]: ";
        getline(cin, category);
        if (category.empty()) category = current.getCategory();
        
        Person updated(firstName, lastName, phone, address, city);
        updated.setEmail(email);
        updated.setInstagram(instagram);
        updated.setWhatsapp(whatsapp);
        updated.setBirthday(birthday);
        updated.setCategory(category);
        updated.setFavorite(current.getFavorite());
        
        phonebook.editContact(index, updated);
    }
    
    void handleDeleteContact() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        phonebook.viewAllContacts();
        
        cout << "\nEnter contact number to delete (1-" << phonebook.getSize() << "): ";
        int index;
        cin >> index;
        index--;
        
        if (index < 0 || index >= phonebook.getSize()) {
            Colors::println("\n[X] Invalid contact number!", Colors::BOLD_RED);
            return;
        }
        
        cout << "\n";
        Colors::print("[!] Are you sure you want to delete this contact? (y/n): ", Colors::BOLD_RED);
        char confirm;
        cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y') {
            phonebook.deleteContact(index);
        } else {
            Colors::println("\n[v] Delete operation cancelled.", Colors::YELLOW);
        }
    }
    
    void handleQuickSearch() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Colors::print("\n[?] Enter search keyword (name, phone, or email): ", Colors::BOLD_MAGENTA);
        string keyword;
        getline(cin, keyword);
        
        vector<Person> results = phonebook.searchContact(keyword);
        
        if (results.empty()) {
            Colors::println("\n[X] No contacts found matching '" + keyword + "'", Colors::BOLD_RED);
        } else {
            cout << "\n" << string(75, '=') << endl;
            Colors::print("  SEARCH RESULTS (", Colors::BOLD_GREEN);
            Colors::print(to_string(results.size()), Colors::BOLD_YELLOW);
            Colors::println(" found)", Colors::BOLD_GREEN);
            cout << string(75, '=') << endl;
            
            for (size_t i = 0; i < results.size(); i++) {
                Colors::print("\n[" + to_string(i + 1) + "] ", Colors::BOLD_WHITE);
                results[i].print();
                if (i < results.size() - 1) {
                    cout << string(75, '-') << endl;
                }
            }
            cout << string(75, '=') << endl;
        }
    }
    
    void handleAdvancedSearch() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        clearScreen();
        cout << "\n" << string(70, '=') << endl;
        Colors::println("                [?] ADVANCED SEARCH", Colors::BOLD_CYAN);
        cout << string(70, '=') << endl;
        Colors::println("Leave blank to skip a filter\n", Colors::YELLOW);
        
        SearchFilter filter;
        filter.minAge = 0;
        filter.maxAge = 0;
        filter.birthdayThisMonth = false;
        filter.favoritesOnly = false;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Name contains       : ";
        getline(cin, filter.name);
        
        cout << "Phone contains      : ";
        getline(cin, filter.phone);
        
        cout << "City contains       : ";
        getline(cin, filter.city);
        
        cout << "Category (exact)    : ";
        getline(cin, filter.category);
        
        cout << "Email contains      : ";
        getline(cin, filter.email);
        
        cout << "Minimum age (0=skip): ";
        string minAgeStr;
        getline(cin, minAgeStr);
        if (!minAgeStr.empty()) filter.minAge = stoi(minAgeStr);
        
        cout << "Maximum age (0=skip): ";
        string maxAgeStr;
        getline(cin, maxAgeStr);
        if (!maxAgeStr.empty()) filter.maxAge = stoi(maxAgeStr);
        
        cout << "Birthday this month? (y/n): ";
        char bdayChoice;
        cin >> bdayChoice;
        filter.birthdayThisMonth = (bdayChoice == 'y' || bdayChoice == 'Y');
        
        cout << "Favorites only? (y/n): ";
        char favChoice;
        cin >> favChoice;
        filter.favoritesOnly = (favChoice == 'y' || favChoice == 'Y');
        
        vector<Person> results = phonebook.advancedSearch(filter);
        
        if (results.empty()) {
            Colors::println("\n[X] No contacts match your search criteria", Colors::BOLD_RED);
        } else {
            cout << "\n" << string(75, '=') << endl;
            Colors::print("  ADVANCED SEARCH RESULTS (", Colors::BOLD_GREEN);
            Colors::print(to_string(results.size()), Colors::BOLD_YELLOW);
            Colors::println(" found)", Colors::BOLD_GREEN);
            cout << string(75, '=') << endl;
            
            for (size_t i = 0; i < results.size(); i++) {
                Colors::print("\n[" + to_string(i + 1) + "] ", Colors::BOLD_WHITE);
                results[i].print();
                if (i < results.size() - 1) {
                    cout << string(75, '-') << endl;
                }
            }
            cout << string(75, '=') << endl;
        }
    }
    
    void handleViewByCategory() {
        phonebook.listAllCategories();
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Colors::print("\nEnter category name to view: ", Colors::BOLD_CYAN);
        string category;
        getline(cin, category);
        
        phonebook.viewContactsByCategory(category);
    }
    
    void handleExport() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        clearScreen();
    
        
        Colors::print("  0. ", Colors::RED);
        cout << "Cancel" << endl;
        
        cout << string(70, '=') << endl;
        cout << "Select format [0-4]: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) return;
        
        Colors::print("\nEnter filename (without extension): ", Colors::BOLD_WHITE);
        string filename;
        getline(cin, filename);
        
    }
    
    void handleToggleFavorite() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        phonebook.viewAllContacts();
        
        cout << "\nEnter contact number to toggle favorite (1-" << phonebook.getSize() << "): ";
        int index;
        cin >> index;
        index--;
        
        phonebook.toggleFavorite(index);
    }
    
    void handleSortContacts() {
        if (phonebook.isEmpty()) {
            Colors::println("\n[X] Phonebook is empty!", Colors::BOLD_RED);
            return;
        }
        
        cout << "\n" << string(50, '=') << endl;
        Colors::println("         [v] SORT CONTACTS", Colors::BOLD_CYAN);
        cout << string(50, '=') << endl;
        cout << "  1. Sort by Name (A-Z)" << endl;
        cout << "  2. Sort by City" << endl;
        cout << "  3. Sort by Age (Oldest first)" << endl;
        cout << string(50, '=') << endl;
        cout << "Select [1-3]: ";
        
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1: phonebook.sortByName(); break;
            case 2: phonebook.sortByCity(); break;
            case 3: phonebook.sortByAge(); break;
            default: Colors::println("Invalid choice!", Colors::BOLD_RED);
        }
    }
    
public:
    PhonebookApp() {
        enableUTF8();
        fileManager = FileManager("input.txt", "output.txt");
    }
    
    void run() {
        showWelcomeBanner();
        
        // Check birthdays at startup
        phonebook.checkBirthdayReminders();
        
        int choice;
        bool running = true;
        
        while (running) {
            displayMenu();
            cin >> choice;
            
            switch (choice) {
                case 1: handleAddContact(); break;
                case 2: handleEditContact(); break;
                case 3: handleDeleteContact(); break;
                case 4: phonebook.viewAllContacts(); break;
                case 5: handleQuickSearch(); break;
                case 6: handleAdvancedSearch(); break;
                case 7: phonebook.displayStatistics(); break;
                case 8: handleViewByCategory(); break;
                case 9: phonebook.listAllCategories(); break;
                case 10: phonebook.checkBirthdayReminders(); break;
                case 11: 
                    cin.ignore();
                    Colors::print("\nEnter input filename [default: input.txt]: ", Colors::CYAN);
                    {string fname; getline(cin, fname);
                    if (!fname.empty()) fileManager.setInputFile(fname);}
                    fileManager.loadFromFile(phonebook);
                    break;
                case 12:
                    cin.ignore();
                    Colors::print("\nEnter output filename [default: output.txt]: ", Colors::CYAN);
                    {string fname; getline(cin, fname);
                    if (!fname.empty()) fileManager.setOutputFile(fname);}
                    fileManager.saveToFile(phonebook);
                    break;
                case 13: phonebook.viewFavorites(); break;
                case 14: handleToggleFavorite(); break;
                case 15: handleSortContacts(); break;
                case 0:
                    clearScreen();
                    cout << "\n";
                    Colors::println("+================================================+", Colors::BOLD_CYAN);
                    Colors::println("|                                                |", Colors::BOLD_CYAN);
                    Colors::println("|     Thank you for using Phonebook Pro!         |", Colors::BOLD_GREEN);
                    Colors::println("|                                                |", Colors::BOLD_CYAN);
                    Colors::println("|       Universitas Gadjah Mada - 2025           |", Colors::WHITE);
                    Colors::println("|                                                |", Colors::BOLD_CYAN);
                    Colors::println("+================================================+", Colors::BOLD_CYAN);
                    cout << "\n";
                    running = false;
                    break;
                default:
                    Colors::println("\n[X] Invalid choice! Please select 0-15.", Colors::BOLD_RED);
            }
            
            if (running && choice != 0) {
                Colors::print("\nPress Enter to continue...", Colors::YELLOW);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                clearScreen();
            }
        }
    }
};

int main() {
    PhonebookApp app;
    app.run();
    return 0;
}