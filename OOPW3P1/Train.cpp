/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 29/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS 
#include "Train.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
    void Train::initialize()
    {
        m_name = nullptr;
        m_noOfPassengers = -1;
        m_departureTime = -1;

    }

    bool Train::validTime(int value) const
    {
        return (value >= MIN_TIME && value <= MAX_TIME && (value % 100) <= 59);
    }

    bool Train::validNoOfPassengers(int value) const
    {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* name)
    {
        delete[] m_name;
        m_name = nullptr;

        if (name != nullptr && strlen(name) > 0)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
    }

    void Train::set(int noOfPassengers, int departure)
    {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure))
        {
            m_noOfPassengers = noOfPassengers;
            m_departureTime = departure;
        }
        else {
            m_noOfPassengers = -1;
            m_departureTime = -1;
        }
    }

    void Train::set(const char* name, int noOfPassengers, int departure)
    {
        set(name);
        set(noOfPassengers, departure);
    }

    void Train::finalize()
    {
        delete[] m_name;
        m_name = nullptr;


    }

    bool Train::isInvalid() const
    {
        return (m_name == nullptr || m_noOfPassengers == -1 || m_departureTime == -1);
    }

    int Train::noOfPassengers() const
    {
        return m_noOfPassengers;
    }

    const char* Train::getName() const
    {
        return m_name;
    }

    int Train::getDepartureTime() const
    {
        return m_departureTime;
    }

    void Train::display() const
    {
        if (isInvalid()) 
        {
            cout << "Train in an invalid State!" << endl;
        }
        else 
        {
            cout << "NAME OF THE TRAIN:    ";
            cout << m_name << endl;

            cout << "NUMBER OF PASSENGERS:";
            cout.width(4); 
            cout << m_noOfPassengers << endl;

            cout << "DEPARTURE TIME:";
            cout.width(11); 
            cout << m_departureTime << endl;
        }
    }
}