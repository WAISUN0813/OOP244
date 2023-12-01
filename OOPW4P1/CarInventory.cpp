/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 06/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds {

    CarInventory::CarInventory() // default constructor
    {
        resetInfo();
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) // constructor
    {
        resetInfo();
        setInfo(type, brand, model, year, code, price);
    }

    CarInventory::~CarInventory() // destructor
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    void CarInventory::resetInfo() // reset the car information
    {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }


    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) // set the car information
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        m_type = new char[strlen(type) + 1]; 
        strcpy(m_type, type);
        m_brand = new char[strlen(brand) + 1]; 
        strcpy(m_brand, brand);
        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        m_year = year;
        m_code = code;
        m_price = price;

        return *this;
    }

    void CarInventory::printInfo() const { // print the car information
        cout << "| " << left << setw(11) << m_type;
        cout << "| " << left << setw(17) << m_brand;
        cout << "| " << left << setw(17) << m_model;
        cout << "| " << m_year;
        cout << " | " << right << setw(4) << m_code;
        cout << " | " << right << setw(9) << fixed << setprecision(2) << m_price << " |" << endl;
    }



    bool CarInventory::isValid() const // check if the car is valid
    {
        return m_type != nullptr &&
            m_brand != nullptr &&
            m_model != nullptr &&
            m_year >= 1990 &&
            m_code >= 100 &&
            m_code <= 999 &&
            m_price >= 0;
    }
    
    
    bool CarInventory::isSimilarTo(const CarInventory& car) const // check if the car is similar to the car in the array
    {
        return m_type != nullptr &&
            m_brand != nullptr &&
            m_model != nullptr &&
            strcmp(m_type, car.m_type) == 0 &&
            strcmp(m_brand, car.m_brand) == 0 &&
            strcmp(m_model, car.m_model) == 0 &&
            m_year == car.m_year;
    }

    int find_similar(CarInventory car[], const int num_cars) // find the similar car in the array
    {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1;
    }
}