/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 17/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds 
{
    class Rectangle : public LblShape//Rectangle is a LblShape
    {
        int m_width;
        int m_height;
    public:
        Rectangle();//default constructor
        Rectangle(const char* label, int width, int height);//constructor with 3 arguments
        virtual ~Rectangle() {};//virtual destructor
        void getSpecs(std::istream& istr);// Override the base class's getSpecs virtual function
        void draw(std::ostream& ostr) const;// Override the base class's getSpecs virtual function
    };
}

#endif
