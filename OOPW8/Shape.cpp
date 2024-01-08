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
#include "Shape.h"

using namespace std;
namespace sdds
{
    std::ostream& operator<<(std::ostream& ostr, const Shape& shape) 
    {
        shape.draw(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Shape& shape) 
    {
        shape.getSpecs(istr);
        return istr;
    }
}
