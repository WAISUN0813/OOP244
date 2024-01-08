/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 17/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds 
{
    class LblShape : public Shape 
    {
        char* m_label;
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        LblShape(const LblShape& ls) = delete;
        LblShape& operator=(const LblShape& ls) = delete;
        virtual ~LblShape();//virtual destructor
        void getSpecs(std::istream& istr);// Override the base class's getSpecs virtual function
    };
}

#endif