#include "FileManager.h"
#include <iostream>
#include <sstream>

FileManager::FileManager() {
    inputFileName = "input.txt";
    outputFileName = "output.txt";
}

FileManager::FileManager(string inputFile, string outputFile) {
    inputFileName = inputFile;
    outputFileName = outputFile;
}

bool FileManager::loadFromFile(Phonebook& phonebook) {
    ifstream inFile(inputFileName);
    
    if (!inFile.is_open()) {
        cout << "\nError: Cannot open input file '" << inputFileName << "'" << endl;
        return false;
    }
    
    phonebook.clear();
    string line;
    int count = 0;
    
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string firstName, lastName, phone, address, city;
        
        getline(ss, firstName, '|');
        getline(ss, lastName, '|');
        getline(ss, phone, '|');
        getline(ss, address, '|');
        getline(ss, city, '|');
        
        Person person(firstName, lastName, phone, address, city);
        phonebook.addContact(person);
        count++;
    }
    
    inFile.close();
    cout << "\nSuccessfully loaded " << count << " contacts from '" << inputFileName << "'" << endl;
    return true;
}

bool FileManager::saveToFile(Phonebook& phonebook) {
    ofstream outFile(outputFileName);
    
    if (!outFile.is_open()) {
        cout << "\nError: Cannot create output file '" << outputFileName << "'" << endl;
        return false;
    }
    
    vector<Person>& contacts = phonebook.getContacts();
    
    for (const auto& contact : contacts) {
        outFile << contact.toString() << endl;
    }
    
    outFile.close();
    cout << "\nSuccessfully saved " << phonebook.getSize() << " contacts to '" << outputFileName << "'" << endl;
    return true;
}

void FileManager::setInputFile(string inputFile) {
    inputFileName = inputFile;
}

void FileManager::setOutputFile(string outputFile) {
    outputFileName = outputFile;
}

string FileManager::getInputFile() const {
    return inputFileName;
}

string FileManager::getOutputFile() const {
    return outputFileName;
}