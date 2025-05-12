#include <iostream>
#include "../include/mylibrary.hpp"
#include "../include/functions.hpp"
#include "../include/subjects.hpp"
#include <string>
#include <sstream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ios;
void Moderator::createStudent()
{
    string userID, passcode, firstName, lastName, email, phoneNumber, address;
    string degree, rollNumber;
    Subject subjectList;
    double cgpa;

    cout << "Enter Roll Number: ";
    cin >> rollNumber;

    cout << "Enter User ID: ";
    cin >> userID;

    cout << "Enter Passcode: ";
    cin >> passcode;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Phone Number: ";
    cin >> phoneNumber;

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cout<<"Degree (BS(CS), MS(AI), BBA(Fintech)"<<endl;
    getline(cin,degree);
    cout<<" Enter CGPA" <<endl;
    cin>>cgpa;
    std::ofstream out("student.txt", ios::app);
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
        cout << "Student record saved successfully.\n";
        Student::studentCount++;
    }
    else
    {
        std::cerr << "Failed to open student.txt!\n";
    }
}

void Moderator::deleteStudent()
{
    string targetRoll;
    cout << "Enter roll number of the student to delete: ";
    cin >> targetRoll;

    std::ifstream in("student.txt");
    std::ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(in, line))
    {
        std::istringstream iss(line);
        string roll;
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

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Student record deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

void Moderator::displayStudent(const string &roll)
{
    Student::displayFromFile(roll);
}
void Moderator::updateStudent(const string& roll)
{
    std::ifstream in("student.txt");
    std::ofstream temp("temp.txt");

    if (!in.is_open() || !temp.is_open()) {
        std::cerr << "Error opening files.\n";
        return;
    }

    string line;
    bool found = false;

    cout << "\t\t\t\t----- Choose any one -----" << endl;
    cout << "Enter 1 to Update Passcode Details" << endl;
    cout << "Enter 2 to Update Personal Details" << endl;
    cout << "Enter 3 to Update Academic Details" << endl;

    char choose;
    cin >> choose;
    cin.ignore();

    while (getline(in, line))
    {
        std::istringstream iss(line);
        string fields[8];
        for (int i = 0; i < 8; ++i) {
            if (!getline(iss, fields[i], ',')) break;
        }

        if (fields[0] == roll) {
            found = true;

            if (choose == '1') {
                cout << "Enter New Passcode: ";
                cin >> fields[1];
            }
            else if (choose == '2')
            {
                cout << "Enter New First Name: ";
                cin >> fields[2];

                cout << "Enter New Last Name: ";
                cin >> fields[3];

                cout << "Enter New Email: ";
                cin >> fields[4];

                cout << "Enter New Phone Number: ";
                cin >> fields[5];

                cout << "Enter New Address: ";
                cin.ignore();
                getline(cin, fields[6]);
            }
            
            else if (choose == '3') {
                // Update Academic Details
                cout << "Enter New Degree (BS/MS/PhD): ";
                cin >> fields[7];

                cout<<" Grades and Marks can only be changed by Faculty! " <<endl;
            }
            else {
                cout << "Invalid choice.\n";
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

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Student record updated successfully.\n";
    else
        cout << "Student with roll number " << roll << " not found.\n";
}

int Moderator::modCount = 0;
