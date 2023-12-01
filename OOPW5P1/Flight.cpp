/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 13/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const // true if the flight is ready
    {   
        return m_passengers > 0 && m_fuel >= m_passengers * 600; 
    }

    Flight::operator int() const // cast to int returns the number of passengers
    {
        return m_passengers;
    }

    Flight::operator double() const // cast to double returns the fuel
    {
        return m_fuel;
    }

    Flight::operator const char* () const // cast to const char* returns the title of the flight
    {
        return m_title;
    }

    bool Flight::operator ~() const // true if the flight is empty
    {
        return m_passengers == 0;
    }

    Flight& Flight::operator=(Flight& right) // copy assignment
    {

        if (this != &right) 
        {
            m_passengers = right.m_passengers;
            m_fuel = right.m_fuel;
            strcpy(m_title, right.m_title);

            right.emptyPlane();
        }
        return *this;  
    }

    Flight& Flight::operator=(int passengers) // sets the number of passengers
    {
        if (passengers >= 0 && passengers <= Boen747Capacity) 
        {
            m_passengers = passengers;
        }
        return *this;
    }

    Flight& Flight::operator=(double fuel) // sets the fuel quantity
    {
        if (fuel >= 0 && fuel <= FuelTankCapacity) 
        {
            m_fuel = fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(double fuel) // adds fuel
    {
        if (fuel >= 0) {
            m_fuel += fuel;
            if (m_fuel > FuelTankCapacity) 
            {
                m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }
    
    Flight& Flight::operator+=(int passengers) // adds passengers
    {
        if (passengers >= 0 && m_passengers + passengers <= Boen747Capacity) 
        {
            m_passengers += passengers;
        }
        return *this;
    }

    Flight& Flight::operator-=(double fuel) // reduces fuel
    {
        if (fuel >= 0) 
        {
            m_fuel -= fuel;
            if (m_fuel < 0) 
            {
                m_fuel = 0.0;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(int passengers) // removes passengers
    {
        if (passengers >= 0 && m_passengers - passengers >= 0) 
        {
            m_passengers -= passengers;
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& left) // moves passengers from left to the current object
    {
        if (this != &left && *this && left)
        {
            m_passengers += left.m_passengers;
            if (m_passengers > Boen747Capacity)
            {
                left.m_passengers = m_passengers - Boen747Capacity;
                m_passengers = Boen747Capacity;
            }
            else
            {
                left.m_passengers = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& right) // moves passengers from the current object to the right operand
    {
        if (this != &right && *this && right)
        {
            right.m_passengers += m_passengers;
            if (right.m_passengers > Boen747Capacity)
            {
                m_passengers = right.m_passengers - Boen747Capacity;
                right.m_passengers = Boen747Capacity;
            }
            else
            {
                m_passengers = 0;
            }
        }
        return *this;
    }

    int Flight::operator+(const Flight& both) const // returns the total number of passengers
    {
        if (*this && both) 
        {
            return m_passengers + both.m_passengers;
        }
        return 0;
    }

    int operator+=(int& left, const Flight& right) // adds the number of passengers to the left operand
    {
        left += right.m_passengers;
        return left;
    }

}