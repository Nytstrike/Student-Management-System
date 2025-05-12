#pragma once
#include <iostream>
#include "subjects.hpp"
using std::string;
// defined in User.cpp
class User
{
protected:
    string userID;
    string password;
    string fName;
    string lName;
    string email;
    string address;
    int cnicNum;

public:
    User(){}
    User(string userID, string password, string fName, string lName, string email, string address, int cnicNum);
};
// defined in admin.cpp and txt file is admins.txt
class Admin : public User
{
    static int adminCount;

public:
    Admin(){}
    Admin(string id, string pass, string first, string last, string e, string add, int no) : User(id, pass, first, last, e, add, no)
    {
        adminCount++;
    }
    void createModerator();
    void displayModerator(const string userIDPointer);
    void deleteModerator();
    // CRD for faculty
    void createFaculty();
    void displayFaculty(const string userIDPointer);
    void deleteFaculty();
    friend void saveAdmin(Admin *a);
    friend int totalUserCount();
};
// defined in moderators.cpp and same txt file as well
class Moderator : public User
{
    static int modCount;

public:
    Moderator(){}
    Moderator(string id, string pass, string first, string last, string e, string add, int no) : User(id, pass, first, last, e, add, no)
    {
        modCount++;
    }
    void createStudent();
    static void displayStudent(const string &roll);
    void updateStudent(const string &roll);
    void deleteStudent();
     friend int totalUserCount();
};
// defined in faculty.cpp and same txt file as well
class Faculty : public User
{   static int facultyCount;
public:
    Faculty(){}
    Faculty(string id, string pass, string first, string last, string e, string add, int no) : User(id, pass, first, last, e, add, no) {
        facultyCount++;
        }
    void updateStudentSubjects();
    friend int totalUserCount ();
};
// defined in student.cpp and same txt file as well
class Student : public User
{
private:
    string rollNum; // 24k-1004 ,24k-0548
    string degree;  // BS(CS), BE(EE), BBA (Fintech), MS(CS) ...
    Subject subjectList[8];
    double cgpa;
    static int studentCount;

public:
    Student(){}
    Student(string userID, string password, string fName, string lName, string email, string address, int cnicNum, string rollNum, string degree, Subject subjectlist[8], double cgpa) : User(userID, password, fName, lName, email, address, cnicNum)
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
    static void displayFromFile(const string &rollNumberToFind);
};
