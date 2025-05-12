#include <iostream>
#include "../include/mylibrary.hpp"
#include "../include/functions.hpp"
#include "../include/subjects.hpp"
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
User::User(std::string userID, std::string password, std::string fName, std::string lName, std::string email, std::string address, int cnicNum)
{
    this->userID = userID; //Log ID 
    this->password = password;
    this->fName = fName;
    this->lName = lName;
    this->email = email;
    this->address = address;
    this->cnicNum = cnicNum;
}

/*Naming Convention for different roles:
    Admin: 
    25A0001 -> for admin of 2025
    Moderator:
    25M0001 -> for moderator of 2025 
    Faculty:
    25F001 -> for faculty of 2025
    Student -> for student of 2025
*/

