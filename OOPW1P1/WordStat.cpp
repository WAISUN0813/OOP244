/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 14/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}
