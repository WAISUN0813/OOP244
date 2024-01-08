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
#include "Container.h"

using namespace std;

namespace sdds
{
	void Container::setEmpty() //sets the object to a safe empty state
	{
		m_description[0] = '\0';
		m_capacity = 0;
		m_volume = -1;
	}

	int Container::capacity() //returns the capacity of the container
	{
		return m_capacity;
	}

	int Container::volume() //returns the volume of the content
	{
		return m_volume;
	}

	Container::Container(const char* Content, int Capacity, int Content_volume) 

	{
		if (Content != nullptr && Capacity >= 0 && Content_volume >= 0) //if the parameters are valid
		{
			strcpy(m_description, Content);
			m_capacity = Capacity;
			m_volume = Content_volume;
		}
		else
		{
			setEmpty();
		}
	}
	
	int Container::operator+=(int value) //adds the value to the volume of the content
	{
		if (m_volume + value <= m_capacity)
		{
			m_volume += value;
		}
		else
		{
			value = m_capacity - m_volume;
			m_volume = m_capacity;
		}
		return value;
	}
	
	int Container::operator-=(int value) //subtracts the value from the volume of the content
	{
		if (m_volume - value >= 0)
		{
			m_volume -= value;
		}
		else
		{
			value = m_volume;
			m_volume = 0;
		}
		return value;
	}


	Container::operator bool() const //returns true if the object is not in a safe empty state
	{
		return m_description[0] != '\0' && m_volume <= m_capacity && m_volume >= 0;
	}

	
	void Container::clear(int Capacity, const char* Content)
	{
		if (Capacity > 0 && Content && strlen(Content) < 50) 
		{
			strcpy(m_description, Content);
			m_capacity = Capacity;
			m_volume = 0;
		}
		else {
			setEmpty();
		}
	}


	ostream& Container::print(ostream& ostr) 
	{
		if (*this)
		{
			ostr << m_description << ": (" << m_volume << "cc/" << m_capacity << ")";
		}
		else
		{
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	istream& Container::read(istream& istr)
	{
		int number;

		if (!(*this))
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
			istr.ignore();
		}
		else
		{
			bool validValue = false;
			cout << "Add to ";
			print(cout);
			while (!validValue)
			{
				cout << endl << "> ";
				istr >> number;
				if (number > m_capacity)
				{
					cout << "Invalid Integer, retry:";
				}
				else if (number < 1 || number > 999)
				{
					cout << "Value out of range [1<=val<=999]:";
				}
				else validValue = true;
			}
			number = (*this += number);
			cout << "Added " << number << " CCs" << endl;
		}
		return istr;
	}


	
	ostream& operator<<(ostream& ostr, Container& C)
	{
		return C.print(ostr);
	}

	istream& operator>>(istream& istr, Container& C)
	{
		return C.read(istr);
	}
}