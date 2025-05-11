// C code to illustrate working of
// getch() to accept hidden inputs

#include <conio.h>
#include<iostream>
#include <stdio.h>
#include<windows.h>
using namespace std;

char** displayPasscode();
int main()
{

    // Taking the password of 8 characters
    char pwd[9];
    int i;
    system("cls");

    printf("Enter Password: ");
    for (i = 0; i < 8; i++) {

        // Get the hidden input
        // using getch() method
        pwd[i] = getch();

        // Print * to show that
        // a character is entered
        printf("*");
    }
    pwd[i] = '\0';
    printf("\n");

    // Now the hidden input is stored in pwd[]
    // So any operation can be done on it

    // Here we are just printing
    printf("Entered password: ");
    for (i = 0; pwd[i] != '\0'; i++)
        printf("%c", pwd[i]);

    // Now the console will wait
    // for a key to be pressed
    getch();
}

string getPasscode() {
    char pass[17]; // +1 for null terminator
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