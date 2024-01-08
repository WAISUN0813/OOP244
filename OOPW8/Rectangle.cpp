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
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds 
{
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0)
    {
    }

    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_width(width), m_height(height)//
    {
        if (m_height < 3 || m_width < (int)strlen(label) + 2)//if height is less than 3 or width is less than the length of the label plus 2
        {
            m_width = 0;
            m_height = 0;
        }
    }

    void Rectangle::draw(std::ostream& ostr) const
    {
        if (m_width > 0 && m_height >> 0) 
        {
            // Draw first line
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+' << endl;
            // Draw second line
            ostr << '|';
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr << left << LblShape::label() << '|' << endl;
            // Draw middle lines
            for (int i = 0; i < (m_height - 3); i++) 
            {
                ostr << '|';
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << ' ' << '|' << endl;
            }
            // Draw last line
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+';
        }
    }

    void Rectangle::getSpecs(std::istream& istr) 
    {
        LblShape::getSpecs(istr);
        istr >> m_width;
        istr.ignore();
        istr >> m_height;
        istr.ignore(32767, '\n');
    }
}