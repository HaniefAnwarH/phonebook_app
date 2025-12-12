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
    
    // Setters
    void setInputFile(string inputFile);
    void setOutputFile(string outputFile);
    
    // Getters
    string getInputFile() const;
    string getOutputFile() const;
};

#endif