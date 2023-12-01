/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 10/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds 
{

    Label::Label() //default constructor
    { 
        strcpy(frame, "+-+|+-+|"); 
        content = nullptr;
    }

    Label::Label(const char* frameArg) //constructor with one argument
    { 
        if (frameArg) { 
            strcpy(frame, frameArg); 
        }
        else {
            strcpy(frame, "+-+|+-+|"); 
        }
        content = nullptr;
    }

    Label::Label(const char* frameArg, const char* contentArg) //constructor with two arguments
    {
        if (frameArg) 
        {
            strcpy(frame, frameArg);
        }
        else 
        {
            strcpy(frame, "+-+|+-+|");
        }
        
        content = new char[strlen(contentArg) + 1]; 
        strcpy(content, contentArg);
    }


    Label::~Label() //destructor
    {
        delete[] content;
    }

    std::istream& Label::readLabel() 
    {
        char tempContent[71]; //temporary variable to store the input
        cout << "> ";
        cin.getline(tempContent, 71); //get the input from the user
        delete[] content; 
        content = new char[strlen(tempContent) + 1]; 
        strcpy(content, tempContent);
        return cin;
    }


    std::ostream& Label::printLabel() const
    {
        if (content != nullptr)
        {
            cout << frame[0] << setfill(frame[1]) << setw(strlen(content) + 3) << frame[2] << endl;
            cout << frame[7] << setfill(' ') << setw(strlen(content) + 3) << frame[3] << endl;
            cout << frame[7] << setw(strlen(content) + 1) << content << " " << frame[3] << endl;

            cout << frame[7] << setfill(' ') << setw(strlen(content) + 3) << frame[3] << endl;

            cout << frame[6] << setfill(frame[5]) << setw(strlen(content) + 3) << frame[4];
        }
        return std::cout;
    }


    Label& Label::text(const char* content) 
    {
        if (content && strlen(content) < 71) //
        {
            delete[] this->content; //delete the old content

            this->content = new char[strlen(content) + 1]; 
            strcpy(this->content, content); 
        }
        else 
        {
            delete[] this->content; 
        }
        return *this;
    }



}
