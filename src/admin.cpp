#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "../include/mylibrary.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ios;
using std::string;
// CRD for Moderator
void Admin::createModerator()
{
    string userID, passcode, firstName, lastName, email, phoneNumber, address;

    cout << "Enter Moderator Information:\n";
    cout << "User ID: ";
    cin >> userID;
    cout << "Passcode: ";
    cin >> passcode;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Email: ";
    cin >> email;
    cout << "Phone Number: ";
    cin >> phoneNumber;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);
    std::ofstream out("moderators.txt", ios::app);
    if (out.is_open())
    {
        out << userID << "," << passcode << "," << firstName << "," << lastName << ","
            << email << "," << phoneNumber << "," << address << "\n";
        out.close();
        cout << "Moderator created successfully.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open moderators.txt\n";
    }
}

void Admin::displayModerator(const std::string userIDPointer) {
    std::ifstream in("moderators.txt");
    std::string line;
    bool found = false;

    if (!in.is_open()) {
        std::cerr << "Error: Could not open moderators.txt\n";
        return;
    }

    while (getline(in, line)) {
        std::istringstream iss(line);
        std::string userID, passcode, firstName, lastName, email, phoneNumber, address;

        getline(iss, userID, ',');
        getline(iss, passcode, ',');
        getline(iss, firstName, ',');
        getline(iss, lastName, ',');
        getline(iss, email, ',');
        getline(iss, phoneNumber, ',');
        getline(iss, address);

        if (userID == userIDPointer) {
            found = true;
            std::cout << "\nModerator ID: " << userID << "\n"
                      << "Name: " << firstName << " " << lastName << "\n"
                      << "Email: " << email << "\n"
                      << "Phone: " << phoneNumber << "\n"
                      << "Address: " << address << "\n"
                      << "----------------------------------\n";
            break; // Stop searching after finding the moderator
        }
    }

    in.close();

    if (!found) {
        std::cout << "Moderator with ID '" << userIDPointer << "' not found.\n";
    }
}


void Admin::deleteModerator()
{
    string targetID;
    cout << "Enter Moderator User ID to delete: ";
    cin >> targetID;

    std::ifstream in("moderators.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp)
    {
        std::cerr << "Error opening file for deletion.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(in, line))
    {
        std::istringstream iss(line);
        string userID;
        getline(iss, userID, ',');

        if (userID == targetID)
        {
            found = true;
            continue; // Skip this line (i.e., delete it)
        }

        temp << line << '\n'; // Keep other lines
    }

    in.close();
    temp.close();

    remove("moderators.txt");
    rename("temp.txt", "moderators.txt");

    if (found)
    {
        cout << "Moderator with ID '" << targetID << "' deleted successfully.\n";
    }
    else
    {
        cout << "Moderator with ID '" << targetID << "' not found.\n";
    }
}

// CRD for faculty
void Admin::createFaculty()
{
    string userID, passcode, firstName, lastName, email, phoneNumber, address;

    cout << "Enter Faculty Info:\n";
    cout << "User ID: ";
    cin >> userID;
    cout << "Passcode: ";
    cin >> passcode;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Email: ";
    cin >> email;
    cout << "Phone Number: ";
    cin >> phoneNumber;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);

    std::ofstream out("faculty.txt", ios::app | ios::trunc);
    if (out.is_open())
    {
        out << userID << "," << passcode << "," << firstName << "," << lastName << ","
            << email << "," << phoneNumber << "," << address << "\n";
        out.close();
        cout << "Faculty member added successfully.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open faculty.txt\n";
    }
}
void Admin::displayFaculty(const std::string userIDPointer)
{
    std::ifstream in("faculty.txt");
    std::string line;
    bool found = false;

    if (!in.is_open())
    {
        std::cerr << "Error: Could not open faculty.txt\n";
        return;
    }

    while (getline(in, line))
    {
        std::istringstream iss(line);
        std::string userID, passcode, firstName, lastName, email, phoneNumber, address;

        getline(iss, userID, ',');
        getline(iss, passcode, ',');
        getline(iss, firstName, ',');
        getline(iss, lastName, ',');
        getline(iss, email, ',');
        getline(iss, phoneNumber, ',');
        getline(iss, address);

        if (userID == userIDPointer)
        {
            found = true;
            std::cout << "\nFaculty ID: " << userID << "\n"
                      << "Name: " << firstName << " " << lastName << "\n"
                      << "Email: " << email << "\n"
                      << "Phone: " << phoneNumber << "\n"
                      << "Address: " << address << "\n"
                      << "----------------------------------\n";
            break; // Stop after finding the matching faculty
        }
    }

    in.close();

    if (!found)
    {
        std::cout << "Faculty with ID '" << userIDPointer << "' not found.\n";
    }
}

void Admin::deleteFaculty()
{
    string targetID;
    cout << "Enter Faculty User ID to delete: ";
    cin >> targetID;

    std::ifstream in("faculty.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp)
    {
        std::cerr << "Error opening file for deletion.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(in, line))
    {
        std::istringstream iss(line);
        string userID;
        getline(iss, userID, ',');

        if (userID == targetID)
        {
            found = true;
            continue; // Skip (delete) this faculty member
        }

        temp << line << "\n";
    }

    in.close();
    temp.close();

    remove("faculty.txt");
    rename("temp.txt", "faculty.txt");

    if (found)
    {
        cout << "Faculty with ID '" << targetID << "' deleted successfully.\n";
    }
    else
    {
        cout << "Faculty with ID '" << targetID << "' not found.\n";
    }
}

int Admin::adminCount = 0;
