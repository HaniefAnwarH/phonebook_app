#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <string>

using namespace std;

namespace Colors {
    // Reset
    const string RESET = "\033[0m";
    
    // Regular Colors
    const string BLACK = "\033[30m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string WHITE = "\033[37m";
    
    // Bold Colors
    const string BOLD_RED = "\033[1;31m";
    const string BOLD_GREEN = "\033[1;32m";
    const string BOLD_YELLOW = "\033[1;33m";
    const string BOLD_BLUE = "\033[1;34m";
    const string BOLD_MAGENTA = "\033[1;35m";
    const string BOLD_CYAN = "\033[1;36m";
    const string BOLD_WHITE = "\033[1;37m";
    
    // Background Colors
    const string BG_RED = "\033[41m";
    const string BG_GREEN = "\033[42m";
    const string BG_YELLOW = "\033[43m";
    const string BG_BLUE = "\033[44m";
    
    // Helper functions
    inline void print(const string& text, const string& color) {
        cout << color << text << RESET;
    }
    
    inline void println(const string& text, const string& color) {
        cout << color << text << RESET << endl;
    }
}

#endif