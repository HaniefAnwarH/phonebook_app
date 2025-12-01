/**
 * Phonebook Pro Application - Enhanced Version
 * FileManager.h - Multi-format File Operations
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Phonebook.h"
#include <string>
#include <fstream>

using namespace std;

class FileManager {
private:
    string inputFileName;
    string outputFileName;

public:
    // Constructors
    FileManager();
    FileManager(string inputFile, string outputFile);
    
    // Basic file operations
    bool loadFromFile(Phonebook& phonebook);
    bool saveToFile(Phonebook& phonebook);
    
    // TIER 2 - Multiple Export Formats
    bool exportToCSV(Phonebook& phonebook, const string& filename);
    bool exportToVCF(Phonebook& phonebook, const string& filename);
    bool exportToHTML(Phonebook& phonebook, const string& filename);
    bool exportToJSON(Phonebook& phonebook, const string& filename);
    
    // Setters
    void setInputFile(string inputFile);
    void setOutputFile(string outputFile);
    
    // Getters
    string getInputFile() const;
    string getOutputFile() const;
};

#endif
