/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 17/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"
#include <cstring>

using namespace std;
namespace sdds 
{
    Line::Line() : LblShape(), m_length(0)
    {
    }

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) 
    {
    }

    void Line::draw(std::ostream& ostr) const 
    {
        if (m_length > 0 && LblShape::label()) 
        {
            ostr << LblShape::label() << endl;
            ostr.width(m_length);
            ostr.fill('=');
            ostr << '=';
        }
    }

    void Line::getSpecs(std::istream& istr) 
    {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(10000, '\n');
    }
}
