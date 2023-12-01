/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 19/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"
using namespace std;
namespace sdds {

    void phoneDir(const char* programTitle, const char* fileName) 
    {
        char partialName[51];
        char name[51], areaCode[4], prefix[4], number[5];
        char lowerName[51], lowerPartial[51];
        bool found = false;
       
        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* f = fopen(fileName, "r");// Open the file 
        if (f != NULL)// Checks is it the file open successfully 
        {
            do// Start loop 
            {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
                cout << "> ";
                cin >> partialName;        

                toLowerCaseAndCopy(lowerPartial, partialName);// Change 'partialName' to lowercase copy it to 'lowerPartial'

                rewind(f);// Move the file pointer back to the beginning of the file

                while (fscanf(f, "%[^\t]\t%s\t%s\t%s\n", name, areaCode, prefix, number) == 4)// Keep reading lines from the file until read all require fields 
                {
                    toLowerCaseAndCopy(lowerName, name);// Change the read 'name' to lowercase and copy it to 'lowerName' for case-insensitive search
                    
                    if (strStr(lowerName, lowerPartial) != nullptr) // If the 'lowerPartial' string is match in the 'lowerName' print the phone details
                    {
                        cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
                        found = true;
                    }
                }

                if (!found) //If no match input 'partialName' print the error message
                {
                    cout << "No match found for " << partialName << endl;
                }
            
            } while (partialName[0] != '!');// Keep loop until '!' is input from the user
        
        }
        
        else // If the file cannot open print an error message
        {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

    fclose(f);// close file
    cout << "Thank you for using " << programTitle << " directory." << endl;
    }
}




