#include <iostream>
#include "mylibrary.hpp"
#include <string>
#include <sstream>
#include <fstream>
void Moderator::createStudent()
{
    std::string userID, passcode, firstName, lastName, email, phoneNumber, address;
    std::string degree, rollNumber;
    Subject subjectList;
    double cgpa;

    std::cout << "Enter Roll Number: ";
    std::cin >> rollNumber;

    std::cout << "Enter User ID: ";
    std::cin >> userID;

    std::cout << "Enter Passcode: ";
    std::cin >> passcode;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;

    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    std::cout << "Enter Email: ";
    std::cin >> email;

    std::cout << "Enter Phone Number: ";
    std::cin >> phoneNumber;

    std::cout << "Enter Address: ";
    std::cin.ignore(); // To clear newline character
    std::getline(std::cin, address);
    std::cout<<"Degree (BS(CS), MS(AI), BBA(Fintech)"<<std::endl;
    std::cout<<" Enter CGPA" <<std::endl;
    std::cin>>cgpa;
    std::ofstream out("studentdata.txt", std::ios::app);
    if (out.is_open())
    {
        out << rollNumber << ","
            << userID << ","
            << passcode << ","
            << firstName << ","
            << lastName << ","
            << email << ","
            << phoneNumber << ","
            << address << ","
            << degree << ","
            << cgpa << ","
            << subjectList.serialize() << ","
            << "\n";

        out.close();
        std::cout << "Student record saved successfully.\n";
    }
    else
    {
        std::cerr << "Failed to open studentdata.txt!\n";
    }
}

void Moderator::deleteStudent()
{
    std::string targetRoll;
    std::cout << "Enter roll number of the student to delete: ";
    std::cin >> targetRoll;

    std::ifstream in("studentdata.txt");
    std::ofstream temp("temp.txt");

    std::string line;
    bool found = false;

    while (getline(in, line))
    {
        std::istringstream iss(line);
        std::string roll;
        getline(iss, roll, ','); // first field is roll number

        if (roll != targetRoll)
        {
            temp << line << '\n'; // keep the line
        }
        else
        {
            found = true;
        }
    }

    in.close();
    temp.close();

    remove("studentdata.txt");
    rename("temp.txt", "studentdata.txt");

    if (found)
        std::cout << "Student record deleted successfully.\n";
    else
        std::cout << "Student not found.\n";
}

void Moderator::displayStudent(const std::string &roll)
{
    Student::displayFromFile(roll);
}
void Moderator::updateStudent(const std::string& roll)
{
    std::ifstream in("studentdata.txt");
    std::ofstream temp("temp.txt");

    if (!in.is_open() || !temp.is_open()) {
        std::cerr << "Error opening files.\n";
        return;
    }

    std::string line;
    bool found = false;

    std::cout << "\t\t\t\t----- Choose any one -----" << std::endl;
    std::cout << "Enter 1 to Update Passcode Details" << std::endl;
    std::cout << "Enter 2 to Update Personal Details" << std::endl;
    std::cout << "Enter 3 to Update Academic Details" << std::endl;

    char choose;
    std::cin >> choose;
    std::cin.ignore();

    while (getline(in, line))
    {
        std::istringstream iss(line);
        std::string fields[8];
        for (int i = 0; i < 8; ++i) {
            if (!getline(iss, fields[i], ',')) break;
        }

        if (fields[0] == roll) {
            found = true;

            if (choose == '1') {
                std::cout << "Enter New Passcode: ";
                std::cin >> fields[1];
            }
            else if (choose == '2')
            {
                std::cout << "Enter New First Name: ";
                std::cin >> fields[2];

                std::cout << "Enter New Last Name: ";
                std::cin >> fields[3];

                std::cout << "Enter New Email: ";
                std::cin >> fields[4];

                std::cout << "Enter New Phone Number: ";
                std::cin >> fields[5];

                std::cout << "Enter New Address: ";
                std::cin.ignore();
                std::getline(std::cin, fields[6]);
            }
            
            else if (choose == '3') {
                // Update Academic Details
                std::cout << "Enter New Degree (BS/MS/PhD): ";
                std::cin >> fields[7];

                std::cout<<" Grades and Marks can only be changed by Faculty! " <<std::endl;
            }
            else {
                std::cout << "Invalid choice.\n";
            }

            // Save updated record
            for (int i = 0; i < 8; ++i) {
                temp << fields[i] << ",";
            }
            temp << fields[8] << "\n";
        }
        else {
            temp << line << "\n"; // Write unchanged record
        }
    }

    in.close();
    temp.close();

    remove("studentdata.txt");
    rename("temp.txt", "studentdata.txt");

    if (found)
        std::cout << "Student record updated successfully.\n";
    else
        std::cout << "Student with roll number " << roll << " not found.\n";
}
