/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 10/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>

namespace sdds 
{

    class Label 
    {
        char frame[9]; // 8 characters for the frame + 1 for the null terminator
        char* content; // dynamically allocated array of characters

    public:
        Label(); 
        Label(const char* frameArg);
        Label(const char* frameArg, const char* contentArg);
        ~Label(); 

        std::istream& readLabel();
        std::ostream& printLabel()const;
        Label& text(const char* content);
    };

}

#endif //SDDS_LABEL_H

