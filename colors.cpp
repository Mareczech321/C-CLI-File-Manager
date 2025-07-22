#include <iostream>
#include <string>
#include <unordered_map>
#include <windows.h>
using namespace std;

// Enable ANSI color support on Windows CMD
void enableVirtualTerminal() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

// Print text in a specified color
void Color(const string& text, const string& color, bool warning = false) {
    static unordered_map<string, string> colorMap = {
        {"black",   "\033[30m"},
        {"red",     "\033[31m"},
        {"green",   "\033[32m"},
        {"yellow",  "\033[33m"},
        {"blue",    "\033[34m"},
        {"magenta", "\033[35m"},
        {"cyan",    "\033[36m"},
        {"white",   "\033[37m"},
        {"bright_red",    "\033[91m"},
        {"bright_green",  "\033[92m"},
        {"bright_yellow", "\033[93m"},
        {"bright_blue",   "\033[94m"},
        {"bright_magenta","\033[95m"},
        {"bright_cyan",   "\033[96m"},
        {"bright_white",  "\033[97m"}
    };

    string colorCode = "\033[0m"; // default/reset

    if (colorMap.count(color)) {
        colorCode = colorMap[color];
    } else {
        cerr << "[Warning] Unknown color '" << color << "', using default." << endl;
    }

    if (warning) {
        cerr << colorCode << text << "\033[0m"; // reset color at the end
    } else {
        cout << colorCode << text << "\033[0m"; // reset color at the end
    }
    cout << colorMap["white"];
}