#include <iostream>
#include <limits>
#include "Person.h"
#include "Phonebook.h"
#include "FileManager.h"

using namespace std;

class PhonebookApp {
private:
    Phonebook phonebook;
    FileManager fileManager;
    
    void displayMenu() {
        cout << "\n" << string(60, '=') << endl;
        cout << "           PHONEBOOK APPLICATION MENU" << endl;
        cout << string(60, '=') << endl;
        cout << "  1. Add New Contact" << endl;
        cout << "  2. Edit Contact" << endl;
        cout << "  3. Delete Contact" << endl;
        cout << "  4. View All Contacts" << endl;
        cout << "  5. Search Contact" << endl;
        cout << "  6. Load from File" << endl;
        cout << "  7. Save to File" << endl;
        cout << "  0. Exit" << endl;
        cout << string(60, '=') << endl;
        cout << "Select menu [0-7]: ";
    }
    
    void handleAddContact() {
        cout << "\n" << string(60, '-') << endl;
        cout << "           ADD NEW CONTACT" << endl;
        cout << string(60, '-') << endl;
        
        string firstName, lastName, phone, address, city;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "First Name  : ";
        getline(cin, firstName);
        cout << "Last Name   : ";
        getline(cin, lastName);
        cout << "Phone Number: ";
        getline(cin, phone);
        cout << "Address     : ";
        getline(cin, address);
        cout << "City        : ";
        getline(cin, city);
        
        Person newPerson(firstName, lastName, phone, address, city);
        phonebook.addContact(newPerson);
    }
    
    void handleEditContact() {
        if (phonebook.isEmpty()) {
            cout << "\nPhonebook is empty!" << endl;
            return;
        }
        
        phonebook.viewAllContacts();
        
        cout << "\nEnter contact number to edit (1-" << phonebook.getSize() << "): ";
        int index;
        cin >> index;
        index--;
        
        if (index < 0 || index >= phonebook.getSize()) {
            cout << "\nInvalid contact number!" << endl;
            return;
        }
        
        cout << "\n" << string(60, '-') << endl;
        cout << "           EDIT CONTACT" << endl;
        cout << string(60, '-') << endl;
        cout << "Enter new data (press Enter to keep current value)" << endl;
        
        Person currentPerson = phonebook.getContact(index);
        string firstName, lastName, phone, address, city;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "First Name [" << currentPerson.getFirstName() << "]: ";
        getline(cin, firstName);
        if (firstName.empty()) firstName = currentPerson.getFirstName();
        
        cout << "Last Name [" << currentPerson.getLastName() << "]: ";
        getline(cin, lastName);
        if (lastName.empty()) lastName = currentPerson.getLastName();
        
        cout << "Phone [" << currentPerson.getPhoneNumber() << "]: ";
        getline(cin, phone);
        if (phone.empty()) phone = currentPerson.getPhoneNumber();
        
        cout << "Address [" << currentPerson.getAddress() << "]: ";
        getline(cin, address);
        if (address.empty()) address = currentPerson.getAddress();
        
        cout << "City [" << currentPerson.getCity() << "]: ";
        getline(cin, city);
        if (city.empty()) city = currentPerson.getCity();
        
        Person updatedPerson(firstName, lastName, phone, address, city);
        phonebook.editContact(index, updatedPerson);
    }
    
    void handleDeleteContact() {
        if (phonebook.isEmpty()) {
            cout << "\nPhonebook is empty!" << endl;
            return;
        }
        
        phonebook.viewAllContacts();
        
        cout << "\nEnter contact number to delete (1-" << phonebook.getSize() << "): ";
        int index;
        cin >> index;
        index--;
        
        if (index < 0 || index >= phonebook.getSize()) {
            cout << "\nInvalid contact number!" << endl;
            return;
        }
        
        cout << "\nAre you sure you want to delete this contact? (y/n): ";
        char confirm;
        cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y') {
            phonebook.deleteContact(index);
        } else {
            cout << "\nDelete operation cancelled." << endl;
        }
    }
    
    void handleViewContacts() {
        phonebook.viewAllContacts();
    }
    
    void handleSearchContact() {
        if (phonebook.isEmpty()) {
            cout << "\nPhonebook is empty!" << endl;
            return;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter search keyword (name or phone): ";
        string keyword;
        getline(cin, keyword);
        
        vector<Person> results = phonebook.searchContact(keyword);
        
        if (results.empty()) {
            cout << "\nNo contacts found matching '" << keyword << "'" << endl;
        } else {
            cout << "\n" << string(60, '=') << endl;
            cout << "  SEARCH RESULTS (" << results.size() << " found)" << endl;
            cout << string(60, '=') << endl;
            
            for (size_t i = 0; i < results.size(); i++) {
                cout << "\n[" << (i + 1) << "] ";
                results[i].print();
                if (i < results.size() - 1) {
                    cout << string(60, '-') << endl;
                }
            }
            cout << string(60, '=') << endl;
        }
    }
    
    void handleLoadFile() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter input filename [default: input.txt]: ";
        string filename;
        getline(cin, filename);
        
        if (!filename.empty()) {
            fileManager.setInputFile(filename);
        }
        
        fileManager.loadFromFile(phonebook);
    }
    
    void handleSaveFile() {
        if (phonebook.isEmpty()) {
            cout << "\nPhonebook is empty! Nothing to save." << endl;
            return;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter output filename [default: output.txt]: ";
        string filename;
        getline(cin, filename);
        
        if (!filename.empty()) {
            fileManager.setOutputFile(filename);
        }
        
        fileManager.saveToFile(phonebook);
    }
    
public:
    PhonebookApp() {
        fileManager = FileManager("input.txt", "output.txt");
    }
    
    void run() {
        cout << "\n" << string(60, '=') << endl;
        cout << "      WELCOME TO PHONEBOOK APPLICATION" << endl;
        cout << "  Universitas Gadjah Mada - 2025" << endl;
        cout << string(60, '=') << endl;
        
        int choice;
        bool running = true;
        
        while (running) {
            displayMenu();
            cin >> choice;
            
            switch (choice) {
                case 1:
                    handleAddContact();
                    break;
                case 2:
                    handleEditContact();
                    break;
                case 3:
                    handleDeleteContact();
                    break;
                case 4:
                    handleViewContacts();
                    break;
                case 5:
                    handleSearchContact();
                    break;
                case 6:
                    handleLoadFile();
                    break;
                case 7:
                    handleSaveFile();
                    break;
                case 0:
                    cout << "\nThank you for using Phonebook Application!" << endl;
                    cout << "Goodbye!\n" << endl;
                    running = false;
                    break;
                default:
                    cout << "\nInvalid choice! Please select 0-7." << endl;
            }
            
            if (running && choice != 0) {
                cout << "\nPress Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        }
    }
};

int main() {
    PhonebookApp app;
    app.run();
    return 0;
}