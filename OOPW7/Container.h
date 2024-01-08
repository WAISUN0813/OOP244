/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 10/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds 
{
	class Container
	{
	private:
		char m_description[50];
		int m_capacity;
		int m_volume;
	
	protected:
		void setEmpty();
		int capacity();
		int volume();
	
	public:
		Container(const char *Content, int Capacity, int Content_volume = 0);
		int operator+=(int value);
		int operator-=(int value);
		operator bool() const;
		void clear(int Capacity, const char *Content);
		ostream &print(ostream & ostr);
		istream &read(istream & istr);
		friend ostream& operator<<(ostream& ostr, Container& C);
		friend istream& operator>>(istream& istr, Container& C);
	
	};
}
#endif