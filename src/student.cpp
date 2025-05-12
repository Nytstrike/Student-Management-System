#include<iostream>
#include "../include/mylibrary.hpp"
#include "../include/functions.hpp"
#include "../include/subjects.hpp"
#include<string>
#include<sstream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void Student::displayFromFile(const string &rollNumberToFind) {
    std::ifstream in("student.txt");
    string line;
    bool found = false;

    if (!in.is_open()) {
        std::cerr << "Unable to open student.txt\n";
        return;
    }

    while (getline(in, line)) {
        std::istringstream iss(line);
        string fields[11];
        for (int i = 0; i < 11; ++i) {
            if (!getline(iss, fields[i], ',')) break;
        }

        if (fields[0] == rollNumberToFind) {
            found = true;
            cout << "\n--- Student Record ---\n";
            cout << "Roll Number: " << fields[0] << "\n";
            cout << "User ID: " << fields[1] << "\n";
            cout << "Name: " << fields[2] << " " << fields[3] << "\n";
            cout << "Email: " << fields[4] << "\n";
            cout << "Phone: " << fields[5] << "\n";
            cout << "Address: " << fields[6] << "\n";
            cout<<"CNIC Number: " << fields[7] <<"\n";
            cout<< "Degree: " << fields[8] << "\n";
            cout<< "CPGA: " <<fields[9] <<"\n";
        }
    }

    in.close();

    if (!found) {
        cout << "No student found with roll number: " << rollNumberToFind << "\n";
    }
}

int Student::studentCount = 0;
