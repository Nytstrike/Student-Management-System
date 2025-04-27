#include <iostream>
#include "mylibrary.hpp"
#include <string>
#include <sstream>
#include <fstream>
//CRD for Moderator 
void Admin::createModerator() {
    std::string userID, passcode, firstName, lastName, email, phoneNumber, address;

    std::cout << "Enter Moderator Information:\n";
    std::cout << "User ID: "; std::cin >> userID;
    std::cout << "Passcode: "; std::cin >> passcode;
    std::cout << "First Name: "; std::cin >> firstName;
    std::cout << "Last Name: "; std::cin >> lastName;
    std::cout << "Email: "; std::cin >> email;
    std::cout << "Phone Number: "; std::cin >> phoneNumber;
    std::cout << "Address: "; std::cin.ignore(); std::getline(std::cin, address);

    std::ofstream out("moderators.txt", std::ios::app);
    if (out.is_open()) {
        out << userID << "," << passcode << "," << firstName << "," << lastName << ","
            << email << "," << phoneNumber << "," << address << "\n";
        out.close();
        std::cout << "Moderator created successfully.\n";
    } else {
        std::cerr << "Error: Unable to open moderators.txt\n";
    }
}

void Admin::displayModerator() {
    std::ifstream in("moderators.txt");
    std::string line;
    bool found = false;

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

        found = true;
        std::cout << "\nModerator ID: " << userID << "\n"
                  << "Name: " << firstName << " " << lastName << "\n"
                  << "Email: " << email << "\n"
                  << "Phone: " << phoneNumber << "\n"
                  << "Address: " << address << "\n"
                  << "----------------------------------\n";
    }

    if (!found) {
        std::cout << "No moderators found.\n";
    }
}

void Admin::deleteModerator() {
    std::string targetID;
    std::cout << "Enter Moderator User ID to delete: ";
    std::cin >> targetID;

    std::ifstream in("moderators.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp) {
        std::cerr << "Error opening file for deletion.\n";
        return;
    }

    std::string line;
    bool found = false;

    while (getline(in, line)) {
        std::istringstream iss(line);
        std::string userID;
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
        std::cout << "Moderator with ID '" << targetID << "' deleted successfully.\n";
    } else {
        std::cout << "Moderator with ID '" << targetID << "' not found.\n";
    }
}

//CRD for faculty 
void Admin::createFaculty() {
    std::string userID, passcode, firstName, lastName, email, phoneNumber, address;

    std::cout << "Enter Faculty Info:\n";
    std::cout << "User ID: "; std::cin >> userID;
    std::cout << "Passcode: "; std::cin >> passcode;
    std::cout << "First Name: "; std::cin >> firstName;
    std::cout << "Last Name: "; std::cin >> lastName;
    std::cout << "Email: "; std::cin >> email;
    std::cout << "Phone Number: "; std::cin >> phoneNumber;
    std::cout << "Address: "; std::cin.ignore(); std::getline(std::cin, address);

    std::ofstream out("faculty.txt", std::ios::app);
    if (out.is_open()) {
        out << userID << "," << passcode << "," << firstName << "," << lastName << ","
            << email << "," << phoneNumber << "," << address << "\n";
        out.close();
        std::cout << "Faculty member added successfully.\n";
    } else {
        std::cerr << "Error: Unable to open faculty.txt\n";
    }
}
void Admin::displayFaculty() {
    std::ifstream in("faculty.txt");
    std::string line;
    bool found = false;

    if (!in.is_open()) {
        std::cerr << "Error: Could not open faculty.txt\n";
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

        found = true;
        std::cout << "\nFaculty ID: " << userID << "\n"
                  << "Name: " << firstName << " " << lastName << "\n"
                  << "Email: " << email << "\n"
                  << "Phone: " << phoneNumber << "\n"
                  << "Address: " << address << "\n"
                  << "----------------------------------\n";
    }

    if (!found) {
        std::cout << "No faculty members found.\n";
    }
}
void Admin::deleteFaculty() {
    std::string targetID;
    std::cout << "Enter Faculty User ID to delete: ";
    std::cin >> targetID;

    std::ifstream in("faculty.txt");
    std::ofstream temp("temp.txt");

    if (!in || !temp) {
        std::cerr << "Error opening file for deletion.\n";
        return;
    }

    std::string line;
    bool found = false;

    while (getline(in, line)) {
        std::istringstream iss(line);
        std::string userID;
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
        std::cout << "Faculty with ID '" << targetID << "' deleted successfully.\n";
    } else {
        std::cout << "Faculty with ID '" << targetID << "' not found.\n";
    }
}
