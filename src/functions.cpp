#include <fstream>
#include "include/mylibrary.hpp"
#include "include/functions.hpp"
#include "include/subjects.hpp"
#include <iostream>
#include <stdio.h> // to use printf function for loading bar
#include <windows.h> //for formatting
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