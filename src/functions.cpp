#include <fstream>
#include "../include/mylibrary.hpp"
#include "../include/functions.hpp"
#include "../include/subjects.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <stdio.h> // to use printf function for loading bar
#include <windows.h> //for formatting
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;


void clearInputBuffer()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

void ensureDataFileExists()
{
    const char *filenames[] = {
        "studentdata.txt",
        "moderators.txt",
        "faculty.txt",
        "admins.txt"};

    for (int i = 0; i < 4; ++i)
    {
        std::ifstream file(filenames[i]);
        if (!file)
        {
            std::ofstream createFile(filenames[i]);
            createFile.close();
            cout << "[INFO] Created " << filenames[i] << "\n";
        }
    }
}

void loadingBar()
{
    using namespace std;
    system("cls");
    printf("\e[?25l");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    system("COLOR 0e");
    int a = 177, b = 219;
    cout << "\n\n\n";
    cout << "\n\t\t\t\t\t\t Loading ...";
    cout << "\n\n\t\t\t\t\t";
    for (int i = 0; i < 25; i++)
        cout << (char)a;
    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)b;
        Sleep(150);
    }
    system("cls");
}
int totalUserCount()
{
    return Admin::adminCount + Moderator::modCount + Faculty::facultyCount + Student::studentCount;
}

bool verifyPassword(string role,string userID,string password){
    std::string filename;

    // Map role to corresponding file
    if (role == "admin") filename = "admins.txt";
    else if (role == "moderator") filename = "moderators.txt";
    else if (role == "faculty") filename = "faculty.txt";
    else if (role == "student") filename = "student.txt";
    else {
        std::cerr << "Invalid role specified.\n";
        return false;
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, pass;

        // extract userID and password from the line
        std::getline(ss, id, ',');
        std::getline(ss, pass, ',');

        if (id == userID && pass == password) {
            return true;  
        }
    }

    return false;  
}

void clearScreen() {
    system("cls");  
}
void adminWindow() {
    Admin admin;
    while (true) {
        system("cls");
        printCentered("== Admin Window ==");
        cout << "\n1. Create Moderator";
        cout << "\n2. Display Moderators";
        cout << "\n3. Delete Moderator";
        cout << "\n4. Create Faculty";
        cout << "\n5. Display Faculties";
        cout << "\n6. Delete Faculty";
        cout << "\n0. Logout\n";
        cout << "Enter choice: ";
        char choice = _getch();
        switch (choice) {
            case '1': admin.createModerator(); break;
            case '2': admin.displayModerator(); break;
            case '3': admin.deleteModerator(); break;
            case '4': admin.createFaculty(); break;
            case '5': admin.displayFaculty(); break;
            case '6': admin.deleteFaculty(); break;
            case '0': return;
            default: cout << "\nInvalid choice!"; _getch(); break;
        }
    }
}

void moderatorWindow() {
    Moderator mod;
    while (true) {
        system("cls");
        printCentered("== Moderator Window ==");
        cout << "\n1. Create Student";
        cout << "\n2. Display Student";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n0. Logout\n";
        cout << "Enter choice: ";
        char choice = _getch();
        string roll;
        switch (choice) {
            case '1': mod.createStudent(); break;
            case '2': cout << "\nEnter Roll Number: "; cin >> roll; Moderator::displayStudent(roll); break;
            case '3': cout << "\nEnter Roll Number: "; cin >> roll; mod.updateStudent(roll); break;
            case '4': mod.deleteStudent(); break;
            case '0': return;
            default: cout << "\nInvalid choice!"; _getch(); break;
        }
    }
}

void facultyWindow() {
    Faculty faculty;
    while (true) {
        system("cls");
        printCentered("== Faculty Window ==");
        cout << "\n1. Update Student Subjects";
        cout << "\n0. Logout\n";
        cout << "Enter choice: ";
        char choice = _getch();
        switch (choice) {
            case '1': faculty.updateStudentSubjects(); break;
            case '0': return;
            default: cout << "\nInvalid choice!"; _getch(); break;
        }
    }
}

void studentWindow() {
    string roll;
    while (true) {
        system("cls");
        printCentered("== Student Window ==");
        cout << "\n1. View Result";
        cout << "\n0. Logout\n";
        cout << "Enter choice: ";
        char choice = _getch();
        switch (choice) {
            case '1': cout << "\nEnter Roll Number: "; cin >> roll; Student::displayFromFile(roll); break;
            case '0': return;
            default: cout << "\nInvalid choice!"; _getch(); break;
        }
    }
}
