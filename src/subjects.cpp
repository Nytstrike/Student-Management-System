#include<iostream>
#include "include/mylibrary.hpp"
#include "include/functions.hpp"
#include "include/subjects.hpp"
#include<sstream>

void Subject::updatemarks()
{
    std::cout << "Enter marks for 5 core subjects:\n";
    std::cin >> sub1 >> sub2 >> sub3 >> sub4 >> sub5;
    std::cout << "Enter marks for 2 elective subjects:\n";
    std::cin >> elect1 >> elect2;

    int marks[] = {sub1, sub2, sub3, sub4, sub5, elect1, elect2};
    for (int i = 0; i < 7; i++)
    {
        if (marks[i] >= 90)
            grade[i] = 'A';
        else if (marks[i] >= 80)
            grade[i] = 'B';
        else if (marks[i] >= 70)
            grade[i] = 'C';
        else if (marks[i] >= 60)
            grade[i] = 'D';
        else
            grade[i] = 'F';
    }
}
void Subject::calGPA()
{
    double gpa = 0.0;
    for (int i = 0; i < 7; i++)
    {
        switch (grade[i])
        {
        case 'A':
            gpa += 4.0;
            break;
        case 'B':
            gpa += 3.0;
            break;
        case 'C':
            gpa += 2.0;
            break;
        case 'D':
            gpa += 1.0;
            break;
        case 'F':
            gpa += 0.0;
            break;
        default:
            break;
        }
    }
    gpa = gpa / 7.0;
    std::cout << "Calculated GPA: " << gpa << std::endl;
}

std::string Subject::serialize() const
{
    std::string result = std::to_string(sub1) + ";" + std::to_string(sub2) + ";" +
                         std::to_string(sub3) + ";" + std::to_string(sub4) + ";" +
                         std::to_string(sub5) + ";" + std::to_string(elect1) + ";" +
                         std::to_string(elect2) + "|";
    for (int i = 0; i < 7; ++i)
    {
        result += grade[i];
    }
    return result;
}

// Deserialize from string (marks|grades)
Subject Subject::deserialize(const std::string &data)
{
    Subject s;
    std::string marksPart = data.substr(0, data.find('|'));
    std::string gradePart = data.substr(data.find('|') + 1);
    std::istringstream iss(marksPart);
    std::string mark;
    int *fields[] = {&s.sub1, &s.sub2, &s.sub3, &s.sub4, &s.sub5, &s.elect1, &s.elect2};
    for (int i = 0; i < 7; i++)
    {
        getline(iss, mark, ';');
        *fields[i] = std::stoi(mark);
    }
    for (int i = 0; i < 7 && i < gradePart.length(); i++)
    {
        s.grade[i] = gradePart[i];
    }
    return s;
}
void Subject::displaymessage() {
    const char* subjectNames[7] = {
        "Subject 1", "Subject 2", "Subject 3",
        "Subject 4", "Subject 5", "Elective 1", "Elective 2"
    };

    int marks[7] = { sub1, sub2, sub3, sub4, sub5, elect1, elect2 };

    std::cout << "\n+-------------+--------+--------+\n";
    std::cout << "| Subject     | Marks  | Grade  |\n";
    std::cout << "+-------------+--------+--------+\n";

    for (int i = 0; i < 7; i++) {
        std::cout << "| " << subjectNames[i]
                  << "\t| " << marks[i]
                  << "\t| " << grade[i]
                  << "\t|\n";
    }

    std::cout << "+-------------+--------+--------+\n";
}