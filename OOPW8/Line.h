/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 17/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds 
{
    class Line : public LblShape 
    {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        virtual ~Line() {};//virtual destructor
        void getSpecs(std::istream& istr);// Override the base class's getSpecs virtual function
        void draw(std::ostream& ostr) const;// Override the base class's getSpecs virtual function
    };
}

#endif