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
using std::cerr;
// CRD for Moderator
void Admin::createModerator()
{
    string userID, passcode, firstName, lastName, email, phoneNumber, address;

    // This loop ensures unique userID, full name, and email
    while (true) {
        bool isDuplicate = false;

        cout << "\nEnter Moderator Information:\n";
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

        // Check if the userID, full name, or email already exists in the file
        std::ifstream inFile("moderators.txt");
        string line;
        while (getline(inFile, line)) {
            std::stringstream ss(line);
            string storedUserID, storedPasscode, storedFirstName, storedLastName;
            string storedEmail, storedPhoneNumber, storedAddress;

            getline(ss, storedUserID, ',');
            getline(ss, storedPasscode, ',');
            getline(ss, storedFirstName, ',');
            getline(ss, storedLastName, ',');
            getline(ss, storedEmail, ',');
            getline(ss, storedPhoneNumber, ',');
            getline(ss, storedAddress);

            // Check for duplicate userID, full name or email
            if (userID == storedUserID || 
                (firstName == storedFirstName && lastName == storedLastName) || 
                email == storedEmail) {
                isDuplicate = true;
                break;
            }
        }
        inFile.close();

        if (isDuplicate) {
            cout << "\nError: User ID, Name, or Email already exists. Please try again.\n";
        } else {
            // No duplicates found, write the new moderator's data to file
            std::ofstream outFile("moderators.txt", ios::app);
            if (outFile.is_open()) {
                outFile << userID << "," << passcode << "," << firstName << "," << lastName << ","
                        << email << "," << phoneNumber << "," << address << "\n";
                outFile.close();
                cout << "\nModerator created successfully.\n";
            } else {
                std::cerr << "\nError: Unable to open moderators.txt\n";
            }
            break;  // Exit the loop after successful creation
        }
    }
}

void Admin::displayModerator(const std::string userIDPointer) {
    std::ifstream in("moderators.txt");
    std::string line;
    bool found = false;

    if (!in.is_open()) {
        std::cerr << "\nError: Could not open moderators.txt"<< endl;
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
    cout << "\nEnter Moderator User ID to delete: ";
    cin >> targetID;

    std::ifstream in("moderators.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp)
    {
        std::cerr << "Error opening file for deletion." << endl;
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
        cout << "Moderator with ID '" << targetID << "' deleted successfully."<< endl;
    }
    else
    {
        cout << "Moderator with ID '" << targetID << "' not found." <<endl;
    }
}

// CRD for faculty
void Admin::createFaculty()
{
    string userID, passcode, firstName, lastName, email, phoneNumber, address;

    // This loop ensures unique userID, full name, and email
    while (true) {
        bool isDuplicate = false;

        cout << "\nEnter Faculty Info:\n";
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
        cin.ignore(); 
        cout << "Address: ";
        getline(cin, address);

        // Check for the userID, full name, or email if it already exists in the faculty file
        std::ifstream inFile("faculty.txt");
        string line;
        while (getline(inFile, line)) {
            std::stringstream ss(line);
            string storedUserID, storedPasscode, storedFirstName, storedLastName;
            string storedEmail, storedPhoneNumber, storedAddress;

            getline(ss, storedUserID, ',');
            getline(ss, storedPasscode, ',');
            getline(ss, storedFirstName, ',');
            getline(ss, storedLastName, ',');
            getline(ss, storedEmail, ',');
            getline(ss, storedPhoneNumber, ',');
            getline(ss, storedAddress);

            // Check for duplicate userID, full name, or email
            if (userID == storedUserID || 
                (firstName == storedFirstName && lastName == storedLastName) || 
                email == storedEmail) {
                isDuplicate = true;
                break;
            }
        }
        inFile.close();

        if (isDuplicate) {
            cout << "\nError: User ID, Name, or Email already exists. Please try again.\n";
        } else {
            // No duplicates found, write the new faculty's data to file
            std::ofstream outFile("faculty.txt", ios::app);
            if (outFile.is_open()) {
                outFile << userID << "," << passcode << "," << firstName << "," << lastName << ","
                        << email << "," << phoneNumber << "," << address << "\n";
                outFile.close();
                cout << "Faculty member added successfully.\n";
            } else {
                std::cerr << "Error: Unable to open faculty.txt\n";
            }
            break;  // Exit the loop after successful creation
        }
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
