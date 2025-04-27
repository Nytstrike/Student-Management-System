#include<iostream>
#include"mylibrary.hpp"
#include<string>
#include<sstream>
#include<fstream>
void Student::displayFromFile(const std::string &rollNumberToFind) {
    std::ifstream in("studentdata.txt");
    std::string line;
    bool found = false;

    if (!in.is_open()) {
        std::cerr << "Unable to open studentdata.txt\n";
        return;
    }

    while (getline(in, line)) {
        std::istringstream iss(line);
        std::string fields[11];
        for (int i = 0; i < 11; ++i) {
            if (!getline(iss, fields[i], ',')) break;
        }

        if (fields[0] == rollNumberToFind) {
            found = true;
            std::cout << "\n--- Student Record ---\n";
            std::cout << "Roll Number: " << fields[0] << "\n";
            std::cout << "User ID: " << fields[1] << "\n";
            std::cout << "Name: " << fields[2] << " " << fields[3] << "\n";
            std::cout << "Email: " << fields[4] << "\n";
            std::cout << "Phone: " << fields[5] << "\n";
            std::cout << "Address: " << fields[6] << "\n";
            std::cout<<"CNIC Number: " << fields[7] <<"\n";
            std::cout<< "Degree: " << fields[8] << "\n";
            std::cout<< "CPGA: " <<fields[9] <<"\n";
        }
    }

    in.close();

    if (!found) {
        std::cout << "No student found with roll number: " << rollNumberToFind << "\n";
    }
}


