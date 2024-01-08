/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 17/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds
{
    class Shape 
    {
    public:
        virtual void draw(std::ostream& ostr) const = 0;//pure virtual function
        virtual void getSpecs(std::istream& istr) = 0;//pure virtual function
        virtual ~Shape() {}//virtual destructor
    };

    std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
    std::istream& operator>>(std::istream& istr, Shape& shape);
}

#endif
