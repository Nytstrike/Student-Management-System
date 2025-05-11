#pragma once
#include<iostream>
using std::string;

void printCentered(const std::string &text);
void moveCursorTo(int x, int y);
void getTerminalSize(int& width, int& height);
void printAtBottom(const std::string& text);
void preloginWindow();
void loginOptions();
