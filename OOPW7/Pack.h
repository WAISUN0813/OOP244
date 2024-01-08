/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 10/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef PACK_H
#define PACK_H
#include "Container.h"
using namespace sdds;
namespace sdds {
	class Pack : public Container 
	{
	private:
		int m_unitSize; 
		int m_Size; 
		int NumberOfUnits;
	public:
		Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits = 0); 
		int operator+=(int units); 
		int operator-=(int units); 
		int unit(); 
		int noOfUnits(); 
		int size(); 
		void clear(int packSize, int unitSize, const char* content);
		ostream& print(ostream& ostr);
		istream& read(istream& istr);
		friend ostream& operator << (ostream& ostr, Pack& P);
		friend istream& operator >> (istream& istr, Pack& P);
	
	};
}
#endif // !PACK_H