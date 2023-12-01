/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 1/10/2023
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

            cout << "NUMBER OF PASSENGERS: ";
            cout << m_noOfPassengers << endl;

            cout << "DEPARTURE TIME:";
            cout.width(11);
            cout << m_departureTime << endl;
        }
    }
    
    bool Train::load(int& unborad) 
    {
        int numOfPassengers;
        cout << "Enter number of passengers boarding:" << endl;
        cout << "> ";
        cin >> numOfPassengers;

        if ((numOfPassengers + m_noOfPassengers) <= MAX_NO_OF_PASSENGERS)//if the total number of passengers is <= the MAX_NO_OF_PASSENGERS
        {
            m_noOfPassengers += numOfPassengers;//add the number of passengers to the current number of passengers
            unborad = 0;// unboard passengers to 0
            return true;
        }
        else
        {
            unborad = (m_noOfPassengers + numOfPassengers) - MAX_NO_OF_PASSENGERS;//set the unboard passengers to the total number of passengers - the MAX_NO_OF_PASSENGERS
            m_noOfPassengers = MAX_NO_OF_PASSENGERS;//set the number of passengers to the max number of passengers
            return false;
        }
    }
        
    bool Train::updateDepartureTime()
    {
        int newDepartureTime;
        cout << "Enter new departure time:" << endl;
        cout << "> ";
        cin >> newDepartureTime;

        if (validTime(newDepartureTime)) {//if the newDepartureTime is valid
            m_departureTime = newDepartureTime;//set the newDepartureTime
            return true;
        }
        else
        {
            m_departureTime = -1;//set the m_departureTime to -1
            return false;
        }
    }

    bool Train::transfer(const Train& from) 
    {
        char* combinedName;
        
        if (isInvalid() || from.isInvalid())//if either train is invalid
        {
            return false;
        }
        
        if ((m_noOfPassengers + from.m_noOfPassengers) > MAX_NO_OF_PASSENGERS) //if the total number of passengers is > the MAX_NO_OF_PASSENGERS
        {
     
            cout << "Train is full; " << (m_noOfPassengers + from.m_noOfPassengers) - MAX_NO_OF_PASSENGERS << " passengers of " << from.m_name << " could not be boarded!" << endl;
            m_noOfPassengers = MAX_NO_OF_PASSENGERS;
        }
        else 
        {
            m_noOfPassengers = (m_noOfPassengers + from.m_noOfPassengers);//add the number of passengers from the train that is being transfered to the current train
        }
        //combine the name of the current train and the train that is being transfered
        combinedName = new char[strlen(m_name) + strlen(from.m_name) + 3]; 
        strcpy(combinedName, m_name);//copy the name of the current train to the combined name
        strcat(combinedName, ", ");//add the ", " to the combined name
        strcat(combinedName, from.m_name);//add the name of the train that is being transfered to the combined name

        delete[] m_name;
        m_name = combinedName;

        return true;
    }

 }
 

