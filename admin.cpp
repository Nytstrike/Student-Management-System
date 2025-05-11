#include <iostream>
#include "mylibrary.hpp"
#include <string>
#include <sstream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ios;
//CRD for Moderator 
void AdmincreateModerator() {
    string userID, passcode, firstName, lastName, email, phoneNumber, address;

    cout << "Enter Moderator Information:\n";
    cout << "User ID: "; cin >> userID;
    cout << "Passcode: "; cin >> passcode;
   cout << "First Name: "; cin >> firstName;
   cout << "Last Name: "; cin >> lastName;
    cout << "Email: "; cin >> email;
    cout << "Phone Number: "; cin >> phoneNumber;
    cout << "Address: "; cin.ignore(); getline(cin, address);
    std::ofstream out("moderators.txt", ios::app);
    if (out.is_open()) {
        out << userID << "," << passcode << "," << firstName << "," << lastName << ","
            << email << "," << phoneNumber << "," << address << "\n";
        out.close();
        cout << "Moderator created successfully.\n";
    } else {
        std::cerr << "Error: Unable to open moderators.txt\n";
    }
}

void AdmindisplayModerator() {
    std::ifstream in("moderators.txt");
    string line;
    bool found = false;

    while (getline(in, line)) {
       std::istringstream iss(line);
        string userID, passcode, firstName, lastName, email, phoneNumber, address;
        getline(iss, userID, ',');
        getline(iss, passcode, ',');
        getline(iss, firstName, ',');
        getline(iss, lastName, ',');
        getline(iss, email, ',');
        getline(iss, phoneNumber, ',');
        getline(iss, address);

        found = true;
        cout << "\nModerator ID: " << userID << "\n"
                  << "Name: " << firstName << " " << lastName << "\n"
                  << "Email: " << email << "\n"
                  << "Phone: " << phoneNumber << "\n"
                  << "Address: " << address << "\n"
                  << "----------------------------------\n";
    }

    if (!found) {
        cout << "No moderators found.\n";
    }
}

void AdmindeleteModerator() {
    string targetID;
    cout << "Enter Moderator User ID to delete: ";
    cin >> targetID;

    std::ifstream in("moderators.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp) {
        std::cerr << "Error opening file for deletion.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(in, line)) {
        std::istringstream iss(line);
        string userID;
        getline(iss, userID, ',');

        if (userID == targetID) {
            found = true;
            continue;  // Skip this line (i.e., delete it)
        }

        temp << line << '\n';  // Keep other lines
    }

    in.close();
    temp.close();

    remove("moderators.txt");
    rename("temp.txt", "moderators.txt");

    if (found) {
        cout << "Moderator with ID '" << targetID << "' deleted successfully.\n";
    } else {
        cout << "Moderator with ID '" << targetID << "' not found.\n";
    }
}

//CRD for faculty 
void AdmincreateFaculty() {
    string userID, passcode, firstName, lastName, email, phoneNumber, address;

    cout << "Enter Faculty Info:\n";
    cout << "User ID: "; cin >> userID;
    cout << "Passcode: "; cin >> passcode;
    cout << "First Name: "; cin >> firstName;
    cout << "Last Name: "; cin >> lastName;
    cout << "Email: "; cin >> email;
    cout << "Phone Number: "; cin >> phoneNumber;
    cout << "Address: "; cin.ignore(); getline(cin, address);

    std::ofstream out("faculty.txt", ios::app | ios::trunc);
    if (out.is_open()) {
        out << userID << "," << passcode << "," << firstName << "," << lastName << ","
            << email << "," << phoneNumber << "," << address << "\n";
        out.close();
        cout << "Faculty member added successfully.\n";
    } else {
       std::cerr << "Error: Unable to open faculty.txt\n";
    }
}
void AdmindisplayFaculty() {
    std::ifstream in("faculty.txt");
    string line;
    bool found = false;

    if (!in.is_open()) {
        std::cerr << "Error: Could not open faculty.txt\n";
        return;
    }

    while (getline(in, line)) {
        std::istringstream iss(line);
        string userID, passcode, firstName, lastName, email, phoneNumber, address;

        getline(iss, userID, ',');
        getline(iss, passcode, ',');
        getline(iss, firstName, ',');
        getline(iss, lastName, ',');
        getline(iss, email, ',');
        getline(iss, phoneNumber, ',');
        getline(iss, address);

        found = true;
        cout << "\nFaculty ID: " << userID << "\n"
                  << "Name: " << firstName << " " << lastName << "\n"
                  << "Email: " << email << "\n"
                  << "Phone: " << phoneNumber << "\n"
                  << "Address: " << address << "\n"
                  << "----------------------------------\n";
    }

    if (!found) {
        cout << "No faculty members found.\n";
    }
}
void AdmindeleteFaculty() {
    string targetID;
    cout << "Enter Faculty User ID to delete: ";
    cin >> targetID;

    std::ifstream in("faculty.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp) {
        std::cerr << "Error opening file for deletion.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(in, line)) {
       std::istringstream iss(line);
        string userID;
        getline(iss, userID, ',');

        if (userID == targetID) {
            found = true;
            continue;  // Skip (delete) this faculty member
        }

        temp << line << "\n";
    }

    in.close();
    temp.close();

    remove("faculty.txt");
    rename("temp.txt", "faculty.txt");

    if (found) {
        cout << "Faculty with ID '" << targetID << "' deleted successfully.\n";
    } else {
        cout << "Faculty with ID '" << targetID << "' not found.\n";
    }
}
