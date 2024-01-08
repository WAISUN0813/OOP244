/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 23/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

namespace sdds
{
    class Graduate : public Student 
    {
        char* thesisTitle; // Dynamically allocated thesis title
        char* supervisorName; // Dynamically allocated supervisor name
    public:
        Graduate(); // Default constructor
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisorName); // Parameterized constructor
        Graduate(const Graduate& other); // Copy constructor
        Graduate& operator=(const Graduate& other); // Copy assignment operator
        ~Graduate(); // Destructor
        void display() const override; // Display function
    };
}

#endif //SDDS_GRADUATE_H