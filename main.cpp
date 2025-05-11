#include <iostream>
#include "mylibrary.hpp"
#include "functions.hpp"
#include "subjects.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include<conio.h>
#include <windows.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ios;
int main () {
    int choice;
    Admin("25A0001","1234","Muhammad", "Ali","ali.muhammad.naqvi.99@gmail.com","Nazimabad",42201125665959);
    Moderator("25M0001","9876","Neeraj", "Khemani", "neeraj.Khemani@hotmail.com","bolton market",42001123456);
    loadingBar() ;
    while(true) {
        std::cout<<"Select User type:\n";
        std::cout<<"1. Admin\n";
        std::cout<<"2. Moderator\n";
        std::cout<<"3. Exit";
        choice=_getch();
        switch (choice)
        {
        case 1:
            std::cout<<"Enter Passcode:\n";
            break;
        
        default:
            break;
        }
    }
}
