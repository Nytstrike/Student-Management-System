#pragma once
#include<iostream>
struct Subject
{
    char grade[7]; // for all subjects
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;
    int elect1;
    int elect2;

    void updatemarks();
    void calGPA();
    void displaymessage(int i);
    std::string serialize() const;
    static Subject deserialize(const std::string &data);
    void displaymessage();
};
