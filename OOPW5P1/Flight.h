/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 13/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~() const;
        Flight& operator=(Flight& right);
        Flight& operator=(int passengers);
        Flight& operator=(double fuel);
        Flight& operator+=(double fuel);
        Flight& operator+=(int passengers);
        Flight& operator-=(double fuel);
        Flight& operator-=(int passengers);
        Flight& operator<<(Flight& left);
        Flight& operator>>(Flight& right);
        int operator+(const Flight& both) const;
        friend int operator+=(int& left, const Flight& right);
    };

}
#endif // SDDS_FLIGHT_H