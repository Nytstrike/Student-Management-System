#pragma once
#include <iostream>
//these are defined in functions.cpp
void loadingBar();
void ensureDataFileExists();
void clearInputBuffer();
void PrintCentered(const std::string &text);
//defined in User.cpp
struct Subject
{
    char grade[7]; // for all subjects
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;
    int elect1;
    int elect2;

    void updatemarks();
    void calGPA();
    void displaymessage(int i);
    std::string serialize() const;
    static Subject deserialize(const std::string &data);
    void displaymessage();
};
class User
{
protected:
    std::string userID; // UK0001
    std::string password;
    std::string fName;
    std::string lName;
    std::string email;
    std::string address;
    int cnicNum;

public:
    User(std::string userID, std::string password, std::string fName, std::string lName, std::string email, std::string address, int cnicNum) {}
};
//defined in admin.cpp and txt file is admins.txt
class Admin : public User
{
public:
    using User::User;
    void createModerator() {}
    void displayModerator() {}
    void deleteModerator() {}
    // CRD for faculty
    void createFaculty() {}
    void displayFaculty() {}
    void deleteFaculty() {}
};
//defined in moderators.cpp and same txt file as well 
class Moderator : public User
{
public:
    using User::User;
    void createStudent() {}
    static void displayStudent(const std::string &roll) {}
    void updateStudent(const std::string &roll) {}
    void deleteStudent() {}
};
//defined in faculty.cpp and same txt file as well 
class Faculty : public User
{
public:
    using User::User;
    void updateStudentSubjects();
};
//defined in student.cpp and same txt file as well 
class Student : public User
{
protected:
    std::string rollNum; // 24k-1004 ,24k-0548
    std::string degree;  // BS(CS), BE(EE), BBA (Fintech), MS(CS) ...
    Subject subjectList[8];
    double cgpa;

public:
    using User::User;
    Student(std::string userID, std::string password, std::string fName, std::string lName, std::string email, std::string address, int cnicNum, std::string rollNum, std::string degree, Subject subjectlist[8], double cgpa) : User(userID, password, fName, lName, email, address, cnicNum)
    {
        this->rollNum = rollNum;
        this->degree = degree;
        for (int i = 0; i < 7; i++)
            subjectList[i] = subjectlist[i];
        this->cgpa=cgpa;
    }
    static void displayFromFile(const std::string &rollNumberToFind);
};
