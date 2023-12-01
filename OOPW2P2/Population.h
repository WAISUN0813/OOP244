/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/#ifndef SDDS_POPULATION_H_
/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 26/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#define SDDS_POPULATION_H_

namespace sdds {
	struct PostalCode // structure to hold a postal code and its population
	{
		char* code; 
		int population; 
	};
	// returns true of the cstring starts with subString
	void sort();
	bool startsWith(const char* cString, const char* subString);
	bool getPostalCode(char* postal_code_prefix);
	bool load(PostalCode& postalCode);
	bool load(const char* filename, const char* partial_postal_code_prefix);
	void display(const PostalCode& code);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_