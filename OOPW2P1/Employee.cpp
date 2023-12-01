/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
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
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() 
    {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) 
        {
            for (j = 0; j < i; j++) 
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) 
                
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& emp) 
    {
        bool ok = false;
        if (read(emp.m_empNo) && read(emp.m_salary) && read(emp.m_name)) 
        {
            ok = true;
        }
   
        return ok;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int allLoaded = true;

        if (!openFile(DATAFILE))
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        noOfEmployees = noOfRecords();// Get the number of employee records in the file
        employees = new Employee[noOfEmployees];// Dynamically allocate an array for employees

        for (int i = 0; i < noOfEmployees; i++)
        {
            if (!load(employees[i]))// if cannot load print the error message
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                allLoaded = false;
                
            }

            if (allLoaded)
            {
                ok = true;
            }
        }
        closeFile();
        
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& emp)
    {
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << int(emp.m_salary) << endl;
    }

    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }

    }
    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }

        delete[] employees;
        employees = nullptr;
    }

} // namespace sdds




