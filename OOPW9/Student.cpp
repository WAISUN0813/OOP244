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
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
    Student::Student() : name(nullptr), age(0) {}

    Student::Student(const char* name, int age) : name(nullptr), age(age)//constructor
    {
        if (name) 
        {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
    }

    Student::Student(const Student& other) : name(nullptr), age(other.age) //copy constructor
    {
        if (other.name) 
        {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
    }

    Student& Student::operator=(const Student& other) //copy assignment
    {
        if (this != &other)
        {
            delete[] name;
            name = nullptr;
            age = other.age;
            if (other.name) 
            {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
        }
        return *this;
    }

    Student::~Student() 
    {
        delete[] name;
        name = nullptr; 
    }

    void Student::display() const 
    {
        cout << "Name: ";
        if (name) 
        { 
            cout << name; 
        }
        else 
        {
            cout << "N/A"; 
        }
        cout << endl << "Age: " << age << endl; 
    }

}

