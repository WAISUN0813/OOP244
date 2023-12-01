/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 22/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    //TODO: read functions go here
    
    bool read(char*& name) 
    {
        char temp[128];
        if (fscanf(fptr, "%127[^\n]", temp) == 1) {
            name = new char[strlen(temp) + 1];// Allocate dynamic memory to store the read string
            if (name) {// If the memory allocation is successful copy the string from temp to name.
                strcpy(name, temp);
                return true;
            }
        }
        return false;
    }
    bool read(int &number) 
    {
        return fscanf(fptr, "%d,", &number) == 1;
    }
    bool read(double &salary) 
    {
        return fscanf(fptr, "%lf,", &salary) == 1;
    }
    
}

