/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 23/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds
{
    class Student
    {
        char* name; // Dynamically allocated name
        int age;
    public:
        Student(); // Default constructor
        Student(const char* name, int age); // Parameterized constructor
        Student(const Student& other); // Copy constructor
        Student& operator=(const Student& other); // Copy assignment operator
        virtual ~Student(); // Destructor
        virtual void display() const; // Display function
    };
}

#endif //SDDS_STUDENT_H