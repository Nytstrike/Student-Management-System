#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "../include/mylibrary.hpp"
#include "../include/functions.hpp"
#include "../include/subjects.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ios;
void Faculty::updateStudentSubjects() {
    string roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;

    std::ifstream in("student.txt");
    std::ofstream temp("temp.txt");

    string line;
    bool found = false;

    if (!in || !temp) {
        std::cerr << "Error opening files.\n";
        return;
    }

    while (getline(in, line)) {
        std::istringstream iss(line);
        string fields[11];
        for (int i = 0; i < 11; ++i) {
            if (!getline(iss, fields[i], ',')) break;
        }

        if (fields[0] == roll) {
            found = true;
            Subject subj;
            subj.updatemarks();    // get new marks and update grades
            subj.calGPA();         // calculate GPA locally
            string subjectData = subj.serialize();

            double gpa = 0.0;
            for (int i = 0; i < 7; ++i) {
                switch (subj.grade[i]) {
                    case 'A': gpa += 4.0; break;
                    case 'B': gpa += 3.0; break;
                    case 'C': gpa += 2.0; break;
                    case 'D': gpa += 1.0; break;
                    case 'F': gpa += 0.0; break;
                }
            }
            gpa = gpa / 7.0; // average GPA over 7 subjects
            fields[9] += gpa / 7.0;
            // Rewrite full student record
            for (int i = 0; i < 8; ++i) {
                temp << fields[i] << ",";
            }
            temp << subjectData << "," << gpa << "," << fields[9] << "\n";
        } else {
            temp << line << "\n"; // copy other students unchanged
        }
    }

    in.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Subjects, grades, and GPA updated successfully.\n";
    else
        cout << "Student not found.\n";
}

int Faculty::facultyCount = 0;
