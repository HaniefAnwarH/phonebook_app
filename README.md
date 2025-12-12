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



# Phonebook Pro

A phonebook app I made for my OOP class project at UGM. It's a console application written in C++ that lets you manage your contacts.

## What it does

This is basically a contact manager that runs in your terminal. You can:

- Add, edit, and delete contacts
- Search for people by name, phone, or email
- See statistics about your contacts
- Get birthday reminders
- Organize contacts into categories (Family, Friends, Work, School)
- Mark favorites
- Sort your contacts
- Save and load everything from a text file

The interface has colors too, which makes it easier to use than boring black and white text.

## What it looks like

When you run it, you'll see this:

```
+===============================================================+
|                                                               |
|                  PHONEBOOK PRO                                |
|                                                               |
|            Universitas Gadjah Mada - 2025                     |
|          Teknik Elektro & Teknologi Informasi                 |
|                                                               |
+===============================================================+
Loading... Done!

===========================================================================
                        MAIN MENU
===========================================================================
  [i] Contacts: 0  |  [*] Favorites: 0

---------------------------------------------------------------------------
  CONTACT MANAGEMENT
---------------------------------------------------------------------------
  1. [+] Add New Contact
  2. [~] Edit Contact
  3. [-] Delete Contact
  4. [=] View All Contacts
  5. [?] Quick Search
  6. [?] Advanced Search

---------------------------------------------------------------------------
  ORGANIZATION & ANALYSIS 
---------------------------------------------------------------------------
  7. [#] View Statistics Dashboard
  8. [@] View by Category
  9. [%] List All Categories
 10. [!] Birthday Reminders

---------------------------------------------------------------------------
  FILE OPERATIONS 
---------------------------------------------------------------------------
 11. [<] Load from File
 12. [>] Save to File
 13. [*] View Favorites
 14. [*] Toggle Favorite
 15. [v] Sort Contacts

---------------------------------------------------------------------------
  0. [X] Exit Application
===========================================================================

Select option [0-15]: 
```

A contact looks like this:

```
[1] [*] Name        : John Doe (Age: 26)
   Category    : Friends
   Phone       : 08123456789
   Email       : john.doe@email.com
   Instagram   : @johndoe
   Address     : Jl. Kaliurang No. 123
   City        : Yogyakarta
   Birthday    : 15/03/1998
```

## How to run it

You need a C++ compiler. If you're on:
- **Windows**: Install MinGW
- **Linux**: You probably already have g++
- **Mac**: Install Xcode command line tools

Then:

1. Download or clone this repo
2. Open terminal in the folder
3. Compile it:
     ### Using g++ (Command Line)
    ```bash
    g++ -o phonebook main.cpp Person.cpp Phonebook.cpp FileManager.cpp
    ```
    ### Using powershell
   ```bash
   g++ -std=c++11 -o phonebook main.cpp Person.cpp Phonebook.cpp FileManager.cpp
   ```
5. Run it:
   ```bash
   ./phonebook        # Mac/Linux
   phonebook.exe      # Windows
   ```

## Files in this project

```
Colors.h            - Makes the text colorful
Person.h/cpp        - The contact data stuff
Phonebook.h/cpp     - Manages all the contacts
FileManager.h/cpp   - Saves and loads files
main.cpp            - The main program
input.txt           - Sample contacts to test with
```

## How to use it

First time you run it:
1. Pick option 11 to load the sample data
2. Press enter (it uses input.txt by default)
3. Now you have 8 contacts to play with

The menu is pretty self-explanatory. Just type the number and hit enter.

Some useful options:
- **1** - Add a new contact
- **4** - See all your contacts
- **5** - Quick search
- **7** - See statistics (how many contacts per city, etc.)
- **10** - Check if anyone has a birthday today
- **12** - Save your changes
- **0** - Exit

## The data format

The app saves contacts in a text file with pipe symbols (|) between fields:

```
John|Doe|08123456789|Jl. Kaliurang 123|Yogyakarta|john@email.com|johndoe|08123456789|15/03/1998|Friends|1
```

The fields are:
- First name, Last name, Phone, Address, City, Email, Instagram, WhatsApp, Birthday (DD/MM/YYYY), Category, Favorite (1 or 0)

## Features

**Basic stuff:**
- Add/edit/delete contacts
- View all contacts
- Search (quick and advanced)
- Load and save to file

**Extra features:**
- Birthday tracking with age calculation
- Statistics dashboard
- Categories (Family, Friends, Work, School)
- Favorites system
- Sort by name, city, or age
- Email validation
- Colors for better UI

**Advanced search** lets you filter by multiple things at once like name, city, age range, category, etc.

## Project structure

This was a team project. We split it up like this:

- **Person class** (Ikhwan Teladan) - Handles individual contact data, birthday calculations, email validation
- **Phonebook class** (Hanief Anwar Hayat) - Manages the contact list, search, sort, statistics
- **UI and FileManager** (Made Abel Noelanza) - The interface, menus, file operations, and putting it all together

## Common problems

**Colors not showing?**
Your terminal might not support them. The app still works fine, just ignore the weird [31m codes.

**Can't compile?**
Make sure you use `-std=c++11` flag. Some older compilers need it.

**Can't find input.txt?**
Make sure input.txt is in the same folder as the program.

**Birthday shows age 0?**
Check the date format. It needs to be DD/MM/YYYY like 15/03/1998.

## About this project

Made for Object-Oriented Programming course at:
- Universitas Gadjah Mada
- Fakultas Teknik
- Departemen Teknik Elektro dan Teknologi Informasi
- 2024/2025

## Testing

We tested everything. All 27 test cases passed.

Tested:
- Adding, editing, deleting contacts
- Searching (both quick and advanced)
- File loading and saving
- Birthday reminders
- Statistics
- Categories
- Favorites
- Sorting

## What we learned

This project taught us:
- How to design classes properly
- Using STL containers (vector, map)
- File I/O in C++
- Making a decent console UI
- Working as a team
- Git and version control

## Future ideas

If we keep working on this, we might add:
- SQLite database instead of text files
- A GUI version using Qt
- Photo support for contacts
- Contact groups
- Duplicate detection

## Notes

The code is pretty well documented if you want to understand how it works. Each class has its own responsibility:
- **Person** = one contact's data
- **Phonebook** = collection of contacts + operations
- **FileManager** = reading/writing files
- **PhonebookApp** = the UI and menu system

We used OOP principles like encapsulation, abstraction, and modularity. The code is split into logical parts that work together.


Made by Ikhwan, Hanief, Noelanza for ProgDas class, UGM 2025

If you have questions or find bugs, open an issue on GitHub.
