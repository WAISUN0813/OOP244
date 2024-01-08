/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 10/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"

using namespace std;
namespace sdds
{
	Pack::Pack(const char* Content, int Size, int unitSize, int NumberOfUnits) // constructor
		: Container(Content, Size* unitSize, unitSize* NumberOfUnits) // call the base class constructor
	{
		this->m_Size = Size; // set the size of the pack
		this->m_unitSize = unitSize; /// set the unit size of the pack
		this->NumberOfUnits = NumberOfUnits; // set the number of units in the pack
	}


	int Pack::operator+=(int units) // add units to the pack
	{ 
		int result = Container::operator+=(units * m_unitSize) / m_unitSize; 
		this->NumberOfUnits += result;
		return result; 
	}
	
	int Pack::operator-=(int units) // remove units from the pack
	{ 
		int result = Container::operator-=(units * m_unitSize) / m_unitSize; 
		this->NumberOfUnits -= result;
		return result; 
	}



	int Pack::unit() // return the unit size of the pack
	{
	
		return m_unitSize;
	}

	int Pack::noOfUnits() // return the number of units in the pack
	{ 
		return NumberOfUnits; 
	}
	
	int Pack::size() // return the size of the pack
	{ 
		return m_Size; 
	}

	void Pack::clear(int packSize, int unitSize, const char* content) // clear the pack
	{
		Container::clear(packSize * unitSize, content);
		m_unitSize = unitSize;
		m_Size = packSize;
	}

	ostream& Pack::print(ostream& ostr) // print the pack
	{ 
		Container::print(ostr); 
		if (*this) 
		{
			ostr << ", " << NumberOfUnits << " in a pack of " << m_Size;
		}
		return ostr; 
	}

	istream& Pack::read(istream& istr) // read the pack
	{
		int units;

		if (!(*this)) // if the pack is broken, print the message and abort the adding
		{
			cout << "Broken Container, adding aborted! Press <ENTER> tocontinue....";
			istr.ignore();
		}
		else if (NumberOfUnits == m_Size) // if the pack is full, print the message and abort the adding
		{ 
			istr.ignore();
			cout << "Pack is full!, press <ENTER> to continue..." << endl;
		}
		else // if the pack is not full, add the units to the pack
		{
			bool validValue = false; 
			cout << "Add to "; 
			print(cout); 
			int flag = 0; 
			while (!validValue && flag == 0) // if the units are not valid, print the message and abort the adding
			{
				cout << endl << "> ";
				istr >> units;
				if (units > m_Size) 
				{
					cout << "Invalid Integer, retry: "; 
				}
				else if (units < 1 || units > (m_Size - NumberOfUnits)) // if the units are out of range, print the message and abort the adding
				{
					cout << "Value out of range [1<=val<=" << (m_Size - NumberOfUnits) << "]: ";
					istr >> units; 
					flag = 1;
				}
				else
					validValue = true;
			}
			units = (*this += units); // add the units to the pack
			cout << "Added " << units << endl; 
		}
		return istr;
	}

	ostream& operator<<(ostream& ostr, Pack& P) // operator overload for printing the pack
	{
		return P.print(ostr);
	}
	istream& operator>>(istream& istr, Pack& P) // operator overload for reading the pack
	{
		return P.read(istr);
	}

}