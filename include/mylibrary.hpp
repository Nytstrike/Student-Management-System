#pragma once
#include <iostream>
#include "include/mylibrary.hpp"
#include "include/functions.hpp"
#include "include/subjects.hpp"

// defined in User.cpp
class User
{
protected:
    std::string userID;
    std::string password;
    std::string fName;
    std::string lName;
    std::string email;
    std::string address;
    int cnicNum;

public:
    User(std::string userID, std::string password, std::string fName, std::string lName, std::string email, std::string address, int cnicNum) {}
};
// defined in admin.cpp and txt file is admins.txt
class Admin : public User
{
    static int adminCount;

public:
    Admin(std::string id, std::string pass, std::string first, std::string last, std::string e, std::string add, int no) : User(id, pass, first, last, e, add, no)
    {
        adminCount++;
    }
    void createModerator() {}
    void displayModerator() {}
    void deleteModerator() {}
    // CRD for faculty
    void createFaculty() {}
    void displayFaculty() {}
    void deleteFaculty() {}
    friend int totalUserCount();
};
// defined in moderators.cpp and same txt file as well
class Moderator : public User
{
    static int modCount;

public:
    Moderator(std::string id, std::string pass, std::string first, std::string last, std::string e, std::string add, int no) : User(id, pass, first, last, e, add, no)
    {
        modCount++;
    }
    void createStudent() {}
    static void displayStudent(const std::string &roll) {}
    void updateStudent(const std::string &roll) {}
    void deleteStudent() {}
     friend int totalUserCount();
};
// defined in faculty.cpp and same txt file as well
class Faculty : public User
{   static int facultyCount;
public:
    Faculty(std::string id, std::string pass, std::string first, std::string last, std::string e, std::string add, int no) : User(id, pass, first, last, e, add, no) {
        facultyCount++;
        }
    void updateStudentSubjects();
    friend int totalUserCount ();
};
// defined in student.cpp and same txt file as well
class Student : public User
{
private:
    std::string rollNum; // 24k-1004 ,24k-0548
    std::string degree;  // BS(CS), BE(EE), BBA (Fintech), MS(CS) ...
    Subject subjectList[8];
    double cgpa;
    static int studentCount;

public:
    using User::User;
    Student(std::string userID, std::string password, std::string fName, std::string lName, std::string email, std::string address, int cnicNum, std::string rollNum, std::string degree, Subject subjectlist[8], double cgpa) : User(userID, password, fName, lName, email, address, cnicNum)
    {
        this->rollNum = rollNum;
        this->degree = degree;
        for (int i = 0; i < 7; i++)
            subjectList[i] = subjectlist[i];
        this->cgpa = cgpa;
        studentCount++;
    }
    friend int totalUserCount ();
    friend class Moderator;
    static void displayFromFile(const std::string &rollNumberToFind);
};
