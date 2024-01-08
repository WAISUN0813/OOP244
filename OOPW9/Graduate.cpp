/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 23/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Graduate.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
    Graduate::Graduate() : Student(), thesisTitle(nullptr), supervisorName(nullptr) {}//default constructor

    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisorName)
        : Student(name, age), thesisTitle(nullptr), supervisorName(nullptr)
    {
        if (thesisTitle) // if thesisTitle is not null
        {
            this->thesisTitle = new char[strlen(thesisTitle) + 1];
            strcpy(this->thesisTitle, thesisTitle);
        }
        if (supervisorName) // if supervisorName is not null
        {
            this->supervisorName = new char[strlen(supervisorName) + 1];
            strcpy(this->supervisorName, supervisorName);
        }
    }

    Graduate::Graduate(const Graduate& other) : Student(other), thesisTitle(nullptr), supervisorName(nullptr)//copy constructor
    {
   
        if (other.thesisTitle) {
            thesisTitle = new char[strlen(other.thesisTitle) + 1];
            strcpy(thesisTitle, other.thesisTitle);
        }
        if (other.supervisorName) {
            supervisorName = new char[strlen(other.supervisorName) + 1];
            strcpy(supervisorName, other.supervisorName);
        }
    }

    Graduate& Graduate::operator=(const Graduate& other)//copy assignment
    {
        if (this != &other)
        {
            Student::operator=(other);
            delete[] thesisTitle;
            delete[] supervisorName;
            thesisTitle = supervisorName = nullptr;
            if (other.thesisTitle)
            {
                thesisTitle = new char[strlen(other.thesisTitle) + 1];
                strcpy(thesisTitle, other.thesisTitle);
            }
            if (other.supervisorName)
            {
                supervisorName = new char[strlen(other.supervisorName) + 1];
                strcpy(supervisorName, other.supervisorName);
            }
        }
        return *this;
    }

    Graduate::~Graduate()
    {
        delete[] thesisTitle;
        thesisTitle = nullptr;
        delete[] supervisorName;
        supervisorName = nullptr;
    }

    void Graduate::display() const
    {
        Student::display();

        cout << "Thesis Title: ";
        if (thesisTitle)
        {
            cout << thesisTitle;
        }
        else
        {
            cout << "N/A";
        }

        std::cout << std::endl << "Supervisor: ";
        if (supervisorName)
        {
            cout << supervisorName;
        }
        else
        {
            cout << "N/A";
        }

        cout << endl << "---------------------------------------------" << endl;
    }
    
    
    
    
    
    
 

}
