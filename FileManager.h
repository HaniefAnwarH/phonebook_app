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
    FileManager();
    FileManager(string inputFile, string outputFile);
    
    bool loadFromFile(Phonebook& phonebook);
    bool saveToFile(Phonebook& phonebook);
    
    void setInputFile(string inputFile);
    void setOutputFile(string outputFile);
    
    string getInputFile() const;
    string getOutputFile() const;
};

#endif