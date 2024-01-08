/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 04/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>  
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {

    // Private member functions
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const //validates the data
    {
        return name && name[0] != '\0' &&
            number > 999999999 && number < 9999999999 &&
            strlen(vCode) == 2 &&
            strlen(sNumber) == 9;
    }

    void HealthCard::setEmpty() //sets the data to empty state
    {
        delete[] m_name;
        m_name = nullptr;
    }
    
    //allocates memory for the name and copies the name into the allocated memory
    void HealthCard::allocateAndCopy(const char* name) 
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1]; 
        strcpy(m_name, name);
    }

    void HealthCard::extractChar(istream& istr, char ch) const //extracts the character from the istream
    {
        if (istr.peek() == ch) {
            istr.ignore();
        }
        else {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const //prints the ID info
    {
     
        ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
        return ostr;
    }

    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) //sets the data
    {
        delete[] m_name;
        m_name = nullptr;
        setEmpty();
        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
    }
    // Public member functions

    HealthCard::HealthCard() //default constructor
    {
        m_name = nullptr;         
        m_number = 0;            
        m_vCode[0] = '\0';       
        m_sNumber[0] = '\0';
    }

    // Constructor with parameters
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) //constructor with parameters
    {
        set(name, number, vCode, sNumber);
    }

    // Copy constructor
    HealthCard::HealthCard(const HealthCard& hc) //copy constructor
    {
        *this = hc;
    }


    HealthCard& HealthCard::operator=(const HealthCard& hc) //copy assignment operator
    {

        if (this != &hc) 
        { 
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber); 
        }
        return *this;
    }


    HealthCard::~HealthCard() //destructor
    {
        delete[] m_name;  
    }

    HealthCard::operator bool() const //returns true if the card is valid
    {
        return m_name != nullptr;  
    }

    std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const //prints the card info
    {
        if (*this) 
        { 
            if (toFile)
            {            
                ostr << m_name << ",";
                printIDInfo(ostr);
                ostr << endl;
            }
            else 
            {
                ostr << left << setw(50) << setfill('.') << m_name;
                printIDInfo(ostr);      
            }
        }
        return ostr;
    }

    std::istream& HealthCard::read(istream& istr) //reads the card info
    {
        char name[MaxNameLength]{ '\0' };
        long long number{ 0 }; 
        char vCode[3]{ 0 }; 
        char sNumber[10]{ 0 };

        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');

        if (istr) 
        {
            set(name, number, vCode, sNumber);
        }
        else
        {
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }


    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) //insertion operator
    {
        if (hc) 
        {  
            hc.print(ostr, false);  
        }
        else 
        {
            ostr << "Invalid Health Card Record";  
        }
        return ostr;  
    }

    std::istream& operator>>(std::istream& istr, HealthCard& hc) //extraction operator
    {
        return hc.read(istr);  
    }
}