#pragma once
#include<iostream>
using std::string;
void loadingBar();
void ensureDataFileExists();
void clearInputBuffer();
void printCentered(const string& text);
int totalUserCount();
string getPasscode();
bool verifyPassword(string role,string userID,string password);
void clearScreen();
void adminWindow();
void moderatorWindow();
void facultyWindow();
void studentWindow();
