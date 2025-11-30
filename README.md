# Phonebook Application - Compilation and Usage Guide

## Project Structure
```
Phonebook/
├── Person.h
├── Person.cpp
├── Phonebook.h
├── Phonebook.cpp
├── FileManager.h
├── FileManager.cpp
├── main.cpp
├── input.txt (sample data)
└── output.txt (will be created after saving)
```

## Compilation Instructions

### Using g++ (Command Line)
```bash
g++ -o phonebook main.cpp Person.cpp Phonebook.cpp FileManager.cpp
```

### Using Visual Studio
1. Create a new C++ Console Application project
2. Add all source files to the project
3. Build solution (Ctrl+Shift+B)
4. Run (F5)

## Running the Application

After compilation, run:
```bash
./phonebook        # Linux/Mac
phonebook.exe      # Windows
```

## Features (Functional Requirements)

| Req-ID | Feature | Description |
|--------|---------|-------------|
| F-01 | Add New Contact | Add person data with name, phone, address, city |
| F-02 | Edit Contact | Modify existing contact information |
| F-03 | Delete Contact | Remove contact from phonebook |
| F-04 | View All Contacts | Display all contacts in formatted list |
| F-05 | Search Contact | Find contacts by name or phone number |
| F-06 | Load from File | Read contact data from input.txt |
| F-07 | Save to File | Write contact data to output.txt |

## Input File Format

The input file uses pipe-delimited format:
```
FirstName|LastName|PhoneNumber|Address|City
```

Example:
```
John|Doe|08123456789|Jl. Kaliurang No. 123|Yogyakarta
Jane|Smith|08198765432|Jl. Gejayan No. 45|Sleman
```

## Usage Examples

### Menu Options
1. **Add New Contact**: Enter contact details when prompted
2. **Edit Contact**: Select contact number and update fields
3. **Delete Contact**: Select contact number to remove
4. **View All Contacts**: Display complete phonebook
5. **Search Contact**: Enter name or phone to search
6. **Load from File**: Import contacts from text file
7. **Save to File**: Export contacts to text file
0. **Exit**: Close application

## Sample Usage Flow

1. Start program
2. Select option 6 to load sample data from input.txt
3. Select option 4 to view all loaded contacts
4. Select option 1 to add a new contact
5. Select option 5 to search for a contact
6. Select option 7 to save all contacts to output.txt
7. Select option 0 to exit

## Testing Checklist

- ✅ Add new contact
- ✅ Edit existing contact
- ✅ Delete contact
- ✅ View all contacts
- ✅ Search by name
- ✅ Search by phone number
- ✅ Load from file
- ✅ Save to file
- ✅ Handle empty phonebook
- ✅ Handle invalid input

## Object-Oriented Design

**Classes:**
- `Person`: Represents individual contact data
- `Phonebook`: Manages collection of Person objects
- `FileManager`: Handles file I/O operations
- `PhonebookApp`: Main application controller

**OOP Principles Applied:**
- **Encapsulation**: Private data members with public methods
- **Abstraction**: Clean interface hiding implementation details
- **Modularity**: Separate classes for different responsibilities
- **Data Hiding**: Use of getters/setters

## Error Handling

The application handles:
- Empty phonebook operations
- Invalid menu selections
- Invalid contact indices
- File I/O errors
- Empty search results

## Notes for Report

This implementation demonstrates:
1. **UML to Code transformation**: Direct mapping from class diagram
2. **OOP concepts**: Encapsulation, classes, objects
3. **File I/O**: Reading and writing structured data
4. **Data structures**: Vector for dynamic storage
5. **User interface**: Console-based menu system
6. **Search functionality**: Case-insensitive keyword search

---
**Developed by:** Ikhwan, Hanief, Made  
**Department:** Teknik Elektro dan Teknologi Informasi  
**Faculty:** Teknik - Universitas Gadjah Mada  
**Year:** 2025
