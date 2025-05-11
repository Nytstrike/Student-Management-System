#include <iostream>
#include <string>
#include <windows.h>
using std::cout;
void printCenteredWin(const std::string &text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int terminalWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int padding = (terminalWidth - text.length()) / 2;
    std::cout << std::string(padding, ' ') << text << std::endl;
}
void moveCursorTo(int x, int y)
{
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void getTerminalSize(int &width, int &height)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;  // Columns
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Rows
}
void printAtBottom(const std::string &text)
{
    int termWidth, termHeight;
    getTerminalSize(termWidth, termHeight);
    // Move cursor to the last row
    moveCursorTo(0, termHeight - 1); // (X=0, Y=bottom_row)
    std::cout << text;
}

int main()
{
    system("cls");
    Sleep(1000);
    cout << "\n";
    printCenteredWin("What is this");
    printCenteredWin("------------------");
    printCenteredWin("|                |");

    printCenteredWin("|Select User type|");

    printCenteredWin("|                |");

    printCenteredWin(" ------------------");

    // cout << " ------------------ \n";
    // cout << " |                | \n";
    // cout << "|Select User type|";
    // cout << "|                |";
    // cout << " ------------------ \n";
    printAtBottom("@Muhammad Ali | Neeraj Khemani");
    // std::cout<<"Code did ran ps"<<std::endl;
    return 0;
}

// int choice;
//     Admin("25A0001","1234","Muhammad", "Ali","ali.muhammad.naqvi.99@gmail.com","Nazimabad",42201125665959);
//     Moderator("25M0001","9876","Neeraj", "Khemani", "neeraj.Khemani@hotmail.com","bolton market",42001123456);
//     loadingBar() ;
//     while(true) {
//         std::cout<<"Select User type:\n";
//         std::cout<<"1. Admin\n";
//         std::cout<<"2. Moderator\n";
//         std::cout<<"3. Exit";
//         choice=_getch();
//         switch (choice)
//         {
//         case 1:
//             std::cout<<"Enter Passcode:\n";
//             break;

//         default:
//             break;
//         }
//     }
// }