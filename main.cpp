#define NOMINMAX
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdio>
#include <limits>
#include "colors.cpp"

using namespace std;
namespace fileSys = std::filesystem;

int displayMenu();
void helpMenu();
void listFiles(const string &folderPath);
void newFile(const string &fileName, string &folderPath);
void deleteFile(const string &fileName, string &folderPath);
void renameFile(const string &fileName, string &folderPath, const string &newFileName);

int main() {

    while (true) {
        int result = displayMenu();

        if (result == 1) {
            break;
        }
    }

    return 0;
}

int displayMenu() {
    int option;
    string folderPath, fileName, newFileName;

    Color("--------------------------------\n\n", "yellow");
    Color("       File Management Menu\n", "bright_blue");
    Color("\n--------------------------------\n", "yellow");
    Color("\tChoose an option:\n\n", "bright_red");
    Color("[1] List files in a folder\n\n", "bright_green");
    Color("[2] Create a new file\n", "bright_magenta");
    Color("[3] Delete a file\n", "bright_magenta");
    Color("[4] Rename a file\n\n\n", "bright_magenta");
    Color("[9] Help\n\n", "red");
    Color("[0] Exit\n", "white");
    Color("--------------------------------\n> ", "yellow");

    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (option < 0 || (option > 4 && option < 9) || option > 9) {
        Color("Invalid option. Please try again.\n", "red");
        return displayMenu();
    }

    switch(option){
        case 0:
            Color("Exiting program.\n", "white");
            Color("Press ENTER to exit...\n", "white");
            cin.get(); // wait for user input before exiting
            return 1;

        case 9:
            helpMenu();
            return 0;
        case 1:
            Color("Enter folder path: ", "white");
            getline(cin, folderPath); // Read full line including spaces
            listFiles(folderPath);
            return 0;

        case 2:
            Color("Enter folder path (If you want to create the file in the same folder as this .exe file press ENTER): ", "white");
            getline(cin, folderPath); // Read full line including spaces
            Color("Enter new file name: ", "white");
            getline(cin, fileName); // Read full line including spaces
            newFile(fileName, folderPath);
            return 0;
        
        case 3:
            Color("Enter folder path to delete: ", "white");
            getline(cin, folderPath); // Read full line including spaces
            Color("Enter file name to delete: ", "white");
            getline(cin, fileName); // Read full line including spaces
            deleteFile(fileName, folderPath);
            return 0;

        case 4:
            Color("Enter folder path to rename: ", "white");
            getline(cin, folderPath); // Read full line including spaces
            Color("Enter file name to rename: ", "white");
            getline(cin, fileName); // Read full line including spaces
            Color("Enter new file name: ", "white");
            getline(cin, newFileName); // Read full line including spaces
            renameFile(fileName, folderPath, newFileName);
            return 0;
    }
    return 0;
}

void helpMenu() {
    Color("----------------------------------\n", "yellow");
    Color("            Help Menu", "bright_blue");
    Color("\n--------------------------------\n", "yellow");
    Color("This program allows you to manage files in a specified folder.\n", "white");
    Color("You can list files, create new files, delete and rename files.\n", "white");
    Color("Functions:\n", "white");
    Color("List files in a folder: Displays all files in the specified folder.\n", "white");
    Color("Create a new file: Creates a new file with the specified name in the given folder.\n", "white");
    Color("Delete a file: Deletes the specified file from the given folder.\n", "white");
    Color("Rename a file: Renames an existing file to a new name in the specified folder.\n", "white");
    Color("Help: Displays this help menu.\n", "white");
    Color("Exit: Exits the program.\n", "white");
}

void listFiles(const string &folderPath) {
    string localFolderPath = folderPath;
    if (localFolderPath.size() == 2 && isalpha(localFolderPath[0]) && localFolderPath[1] == ':') {
        localFolderPath += "\\";
    }

    try {
        fileSys::path path(localFolderPath);

        if (!fileSys::exists(path) || !fileSys::is_directory(path)) {
            Color("Invalid folder path.\n", "red", true);
            return;
        }

        Color("Files in '" + path.string() + "':\n", "white");

        for (const auto& entry : fileSys::directory_iterator(path)) {
            cout << "  " << entry.path().filename() << "\n";
        }
    } catch (const fileSys::filesystem_error& e) {
        Color("Filesystem error: " + string(e.what()) + "\n", "red", true);
    }
}

void newFile(const string &fileName, string &folderPath) {
    if (folderPath.empty()) {
        folderPath = fileSys::current_path().string(); // Use current directory if none provided
    }

    fileSys::path fullPath = fileSys::path(folderPath) / fileName;
    fstream newFile(fullPath, ios::out); // Open file for writing

    if (!newFile) {
        Color("Failed to create file: " + fullPath.string() + "\n", "red", true);
    } else {
        Color("File created: " + fullPath.string() + "\n", "green");
        newFile.close();
    }
}

void deleteFile(const string &fileName, string &folderPath){

    if (folderPath == ""){
        folderPath = fileSys::current_path().string(); // Use current directory if no path is provided
    }

    fileSys::path fullPath = fileSys::path(folderPath) / fileName;

    Color("Are you sure you want to delete the file '" + fullPath.string() + "'? (y/n): ", "white");
    char confirm;
    cin >> confirm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if (confirm == 'y' || confirm == 'Y') {
        if (remove(fullPath.string().c_str()) != 0) {
            Color("Error deleting file '" + fileName + "'.\n", "red", true);
        } else {
            Color("File '" + fileName + "' deleted successfully.\n", "green");
        }
    } else {
        Color("File deletion canceled.\n", "yellow");
    }
}

void renameFile(const string &fileName, string &folderPath, const string &newFileName){
    if (folderPath == ""){
        folderPath = fileSys::current_path().string(); // Use current directory if no path is provided
    }

    fileSys::path fullPath = fileSys::path(folderPath) / fileName;
    fileSys::path newFullPath = fileSys::path(folderPath) / newFileName;

    try {
        fileSys::rename(fullPath, newFullPath);
        Color("File '" + fileName + "' renamed to '" + newFileName + "' successfully.\n", "green");
    } catch (const fileSys::filesystem_error& e) {
        Color("Error renaming file: " + string(e.what()) + "\n", "red", true);
    }
}