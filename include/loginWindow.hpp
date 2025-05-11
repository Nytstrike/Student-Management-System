#pragma once
#include<iostream>
using std::string;

void printCentered(const string &text);
void moveCursorTo(int x, int y);
void getTerminalSize(int& width, int& height);
void printAtBottom(const string& text);
void preloginWindow();
void loginOptions();
