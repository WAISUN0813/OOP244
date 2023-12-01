/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 26/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#include <iostream>
#include "Population.h"
using namespace sdds;
int main() {
    char code[4]{};
    while (getPostalCode(code)) {
        if (load("PCpopulations.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}
