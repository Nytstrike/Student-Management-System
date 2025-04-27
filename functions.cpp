#include <fstream>
#include "mylibrary.hpp"
#include <iostream>
#include <stdio.h>
#include <windows.h>

void PrintCentered(const std::string &text)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int textWidth = text.length();
    int posX = (consoleWidth - textWidth) / 2;

    COORD cursorPos;
    cursorPos.X = posX;
    cursorPos.Y = csbi.dwCursorPosition.Y;
    SetConsoleCursorPosition(hConsole, cursorPos);

    std::cout << text;
}
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void ensureDataFileExists() {
    const char* filenames[] = {
        "studentdata.txt",
        "moderators.txt",
        "faculty.txt",
        "admins.txt"
    };

    for (int i = 0; i < 4; ++i) {
        std::ifstream file(filenames[i]);
        if (!file) {
            std::ofstream createFile(filenames[i]);
            createFile.close();
            std::cout << "[INFO] Created " << filenames[i] << "\n";
        }
    }
}

void loadingBar()
{   using namespace std;
    system("cls");
    printf("\e[?25l");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    system("COLOR 0e");
    int a = 177, b = 219;
    cout<<"\n\n\n";
    cout<<"\n\t\t\t\t\t\t Loading ...";
    cout<<"\n\n\t\t\t\t\t";
    for (int i = 0; i <25; i++)
    cout<<(char)a;
    cout<<"\r";
    cout<<"\t\t\t\t\t";
    for (int i = 0; i <25; i++) {
        cout<<(char)b;
        Sleep(150);
    }
    system("cls");
}

