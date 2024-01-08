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
#include "LblShape.h"
#include <cstring>

using namespace std;
namespace sdds 
{
    LblShape::LblShape() : m_label(nullptr) 
    {}

    LblShape::LblShape(const char* label)
    {
        
        if (label && label[0] != '\0')
        {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
        else 
        {
            m_label = nullptr;
        }
    }

    const char* LblShape::label() const 
    {
        return m_label;
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream& istr) 
    {
        delete[] m_label;
        char buffer[500];
        istr.get(buffer, 500, ',');
        if (istr)
        {
            istr.ignore();
            m_label = new char[strlen(buffer) + 1];
            strcpy(m_label, buffer);
        }
    }
}