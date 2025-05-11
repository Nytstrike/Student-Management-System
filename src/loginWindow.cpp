#include<iostream>
#include"include/functions.hpp"
#include"include/loginWindow.hpp"
#include<conio.h>
#include<windows.h>
using std::cout;
using std::string;
using std::endl;
using std::cin;
void printCentered(const std::string &text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int terminalWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int padding = (terminalWidth - text.length()) / 2;
    std::cout << std::string(padding, ' ') << text << std::endl;
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

void printAtBottom(const std::string &text)
{
    int termWidth, termHeight;
    getTerminalSize(termWidth, termHeight);
    // Move cursor to the last row
    moveCursorTo(0, termHeight - 1); // (X=0, Y=bottom_row)
    std::cout << text;
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
string getPasscode() {
    //Max_Length for passcode is 16;
    char pass[17];
    int i = 0;
    char ch;
    
    while (i < 17) {
        ch = _getch();
        
        if (ch == 13) {
            break;
        }
        else if (ch == 8 && i > 0) { // ASCII 8 = Backspace
            i--;
            std::cout << "\b \b"; // Erase the asterisk
        }
        else if (isprint(ch)) { 
            pass[i++] = ch;
            std::cout << '*';
        }
    }
    
    pass[i] = '\0';
    std::cout << std::endl;
    
    return string(pass);
}

void loginOptions()
{
    string tempID;
    string tempPasscode;   
    printCentered("--|Sign in|--");
    while (1)
    {
        printCentered("------------------");
        printCentered("|                |");
        printCentered("|Select User type|");
        printCentered("|                |");
        printCentered(" ------------------");
        cout<<"\n";
        printCentered("|Press 1 to Sign in as Admin|");
        printCentered("|Press 2 to Sign in as Moderator|");
        printCentered("|Press 3 to Sign in as Faculty|");
        printCentered("|Press 4 to Sign in as Student|");
        printCentered("|Press 'Esc key' to Exit|");
        int ch=_getch();
        switch (ch)
        {
        case 1:
            printCentered("Signing in as Admin ....");
            cout<<"Enter User Id";
            cin>>tempID;
            cout<<"\n";
            cout<<"Enter Password";
            tempPasscode=getPasscode();
            if(1) {}
            break;
        
        default:
            break;
        }
    }
}