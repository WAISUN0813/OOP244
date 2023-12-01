/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 26/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sdds
{
    int noOfPostalCode; // the number of postal codes
    PostalCode* postalcode; // the pointer to the dynamically allocated array of postal codes

    void sort()// sorts the postal codes based on the population
    {
        int i, j;
        PostalCode temp;
        for (i = noOfPostalCode - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (postalcode[j].population > postalcode[j + 1].population)

                {
                    temp = postalcode[j];
                    postalcode[j] = postalcode[j + 1];
                    postalcode[j + 1] = temp;
                }
            }
        }
    }


    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    bool getPostalCode(char* postal_code_prefix) {
        // Prompt the user to enter a postal code prefix.
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << "> ";
        cin >> postal_code_prefix;
        return strcmp(postal_code_prefix, "!") != 0;// return true if the user enters !, false otherwise.
    }

    bool load(PostalCode& postalCode)
    { // load a single postal code
        char code[7];

        if (read(code) && read(postalCode.population)) // read the postal code and the population
        {
            // allocate memory to hold the postal code
            postalCode.code = new char[strlen(code) + 1];
            strcpy(postalCode.code, code);

            return true;
        }
        else 
        {
            return false;
        }
    }
      
    bool load(const char* filename, const char* partial_postal_code_prefix) 
    {
        int i = 0;

        if (!openFile(filename)) {
            cout << "Could not open data file: " << filename << endl;
            return false;
        }

        noOfPostalCode = noOfRecords();
        postalcode = new PostalCode[noOfPostalCode]; // allocate memory to hold the postal codes

        for (int j = 0; j < noOfPostalCode; j++)
        {
            if (load(postalcode[i])) // load a single postal code
            {
                if (strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(postalcode[i].code, partial_postal_code_prefix))
                {
                    i++; // increment the number of actually loaded postal codes
                }
                else 
                {
                    delete[] postalcode[i].code; // deallocate memory if the condition is not met
                }
            }
            else 
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                return false;
            }
        }

        noOfPostalCode = i; // update the number of actual loaded postal codes
        closeFile();
        return true;
    }



    void display(const PostalCode& postalCode) // display a single postal code
    {
    	cout << postalCode.code << ":  " << postalCode.population << endl;
    }
    
    void display() // display all the postal codes and the total population
    {
        int totalPopulation = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort(); 
    
        for (int i = 0; i < noOfPostalCode; i++) 
        {
            cout << i + 1 << "- ";
            display(postalcode[i]);
            totalPopulation += postalcode[i].population;
        }
        
        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << totalPopulation << endl << endl;
    }
    
    void deallocateMemory()
    {
        for (int i = 0; i < noOfPostalCode; i++)
        {
            delete[] postalcode[i].code;
            postalcode[i].code = nullptr; 
        }
        delete[] postalcode;
        postalcode = nullptr; 
    }

  




} // namespace sdds

