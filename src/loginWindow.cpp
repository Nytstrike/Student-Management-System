#include <iostream>
#include "../include/mylibrary.hpp"
#include "../include/functions.hpp"
#include "../include/loginWindow.hpp"
#include <conio.h>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
void printCentered(const string &text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int terminalWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int padding = (terminalWidth - text.length()) / 2;
    cout << string(padding, ' ') << text << endl;
}
void getTerminalSize(int &width, int &height)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;  // Columns
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Rows
}
void moveCursorTo(int x, int y)
{
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printAtBottom(const string &text)
{
    int termWidth, termHeight;
    getTerminalSize(termWidth, termHeight);
    // Move cursor to the last row
    moveCursorTo(0, termHeight - 1); // (X=0, Y=bottom_row)
    cout << text;
}

void preloginWindow()
{
    loadingBar();
    system("cls");
    cout << "\n";
    printCentered("--|System Management System|--");
    printAtBottom("@ Muhammad Ali & Neeraj Khenami");
    Sleep(3500);
    system("cls");
}
string getPasscode()
{
    // Max_Length for passcode is 16;
    char pass[17];
    int i = 0;
    char ch;

    while (i < 17)
    {
        ch = _getch();

        if (ch == 13)
        {
            break;
        }
        else if (ch == 8 && i > 0)
        { // ASCII 8 = Backspace
            i--;
            cout << "\b \b"; // Erase the asterisk
        }
        else if (isprint(ch))
        {
            pass[i++] = ch;
            cout << '*';
        }
    }

    pass[i] = '\0';
    cout << endl;

    return string(pass);
}

void loginOptions()
{
    string tempID;
    string tempPasscode;

    while (true)
    {
        clearScreen();
        cout<<"\n\n";
        printCentered("--| Sign In |--");
        printCentered("--------------------");
        printCentered("|                  |");
        printCentered("| Select User Type |");
        printCentered("|                  |");
        printCentered("--------------------");
        cout << "\n\n";
        printCentered("| Press 1 to Sign in as Admin     |");
        printCentered("| Press 2 to Sign in as Moderator |");
        printCentered("| Press 3 to Sign in as Faculty   |");
        printCentered("| Press 4 to Sign in as Student   |");
        printCentered("| Press 'Esc' key to Exit         |");

        int ch = _getch();

        if (ch == 27) // ESC key ASCII
        {
            printCentered("Exiting Login...");
            break;
        }

        clearScreen();

        switch (ch)
        {
        case '1':
            printCentered("Signing in as Admin...");
            cout << "\nEnter User ID: ";
            cin >> tempID;
            cout << "Enter Password: ";
            tempPasscode = getPasscode();
            if (verifyPassword("admin", tempID, tempPasscode))
            {
                printCentered("Login Successful!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
                adminWindow();
            }
            else
            {
                printCentered("Invalid Admin credentials!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
            }
            break;

        case '2':
            printCentered("Signing in as Moderator...");
            cout << "\nEnter User ID: ";
            cin >> tempID;
            cout << "Enter Password: ";
            tempPasscode = getPasscode();
            if (verifyPassword("moderator", tempID, tempPasscode))
            {
                printCentered("Login Successful!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
                moderatorWindow();
            }
            else
            {
                printCentered("Invalid Moderator credentials!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
            }
            break;

        case '3':
            printCentered("Signing in as Faculty...");
            cout << "\nEnter User ID: ";
            cin >> tempID;
            cout << "Enter Password: ";
            tempPasscode = getPasscode();
            if (verifyPassword("faculty", tempID, tempPasscode))
            {
                printCentered("Login Successful!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
                facultyWindow();
            }
            else
            {
                printCentered("Invalid Faculty credentials!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
            }
            break;

        case '4':
            printCentered("Signing in as Student...");
            cout << "\nEnter User ID: ";
            cin >> tempID;
            cout << "Enter Password: ";
            tempPasscode = getPasscode();
            if (verifyPassword("student", tempID, tempPasscode))
            {
                printCentered("Login Successful!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
                studentWindow();
            }
            else
            {
                printCentered("Invalid Student credentials!");
                cout << "\n";
                printCentered("| Press any key to continue |");
                _getch();
            }
            break;

        default:
            printCentered("Invalid choice. Try again!");
            cout << "\n";
            printCentered("| Press any key to continue |");
            _getch();
            break;
        }
    }
}
