/**
 * Phonebook Pro Application - Enhanced Version
 * FileManager.cpp - Complete Implementation
 */

#include "FileManager.h"
#include "Colors.h"
#include <iostream>
#include <sstream>
#include <ctime>

// Constructors
FileManager::FileManager() {
    inputFileName = "input.txt";
    outputFileName = "output.txt";
}

FileManager::FileManager(string inputFile, string outputFile) {
    inputFileName = inputFile;
    outputFileName = outputFile;
}

// Load from file (enhanced format)
bool FileManager::loadFromFile(Phonebook& phonebook) {
    ifstream inFile(inputFileName);
    
    if (!inFile.is_open()) {
        Colors::println("\n✗ Error: Cannot open input file '" + inputFileName + "'", Colors::BOLD_RED);
        return false;
    }
    
    phonebook.clear();
    string line;
    int count = 0;
    
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string firstName, lastName, phone, address, city;
        string email, instagram, whatsapp, birthday, category, favStr;
        
        // Parse with delimiter '|'
        getline(ss, firstName, '|');
        getline(ss, lastName, '|');
        getline(ss, phone, '|');
        getline(ss, address, '|');
        getline(ss, city, '|');
        getline(ss, email, '|');
        getline(ss, instagram, '|');
        getline(ss, whatsapp, '|');
        getline(ss, birthday, '|');
        getline(ss, category, '|');
        getline(ss, favStr, '|');
        
        Person person(firstName, lastName, phone, address, city);
        person.setEmail(email);
        person.setInstagram(instagram);
        person.setWhatsapp(whatsapp);
        person.setBirthday(birthday);
        person.setCategory(category);
        person.setFavorite(favStr == "1");
        
        phonebook.addContact(person);
        count++;
    }
    
    inFile.close();
    Colors::print("\n✓ Successfully loaded ", Colors::BOLD_GREEN);
    Colors::print(to_string(count), Colors::BOLD_YELLOW);
    Colors::println(" contacts from '" + inputFileName + "'", Colors::BOLD_GREEN);
    return true;
}

// Save to file
bool FileManager::saveToFile(Phonebook& phonebook) {
    ofstream outFile(outputFileName);
    
    if (!outFile.is_open()) {
        Colors::println("\n✗ Error: Cannot create output file '" + outputFileName + "'", Colors::BOLD_RED);
        return false;
    }
    
    vector<Person>& contacts = phonebook.getContacts();
    
    for (const auto& contact : contacts) {
        outFile << contact.toString() << endl;
    }
    
    outFile.close();
    Colors::print("\n✓ Successfully saved ", Colors::BOLD_GREEN);
    Colors::print(to_string(phonebook.getSize()), Colors::BOLD_YELLOW);
    Colors::println(" contacts to '" + outputFileName + "'", Colors::BOLD_GREEN);
    return true;
}

// Setters
void FileManager::setInputFile(string inputFile) {
    inputFileName = inputFile;
}

void FileManager::setOutputFile(string outputFile) {
    outputFileName = outputFile;
}

// Getters
string FileManager::getInputFile() const {
    return inputFileName;
}

string FileManager::getOutputFile() const {
    return outputFileName;
}
