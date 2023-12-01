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
#include "LabelMaker.h"

using namespace std;
namespace sdds 
{

    LabelMaker::LabelMaker(int noOfLabelsArg) //constructor
    {
        noOfLabels = noOfLabelsArg;
        labels = new Label[noOfLabels];
    }

    LabelMaker::~LabelMaker() //destructor
    {
        delete[] labels;  
    }

    void LabelMaker::readLabels() //read labels
    {
        if (noOfLabels > 0) //if no of labels is greater than 0
        {
            cout << "Enter " << noOfLabels << " labels:" << endl; //print the number of labels

            for (int i = 0; i < noOfLabels; i++)  //loop to read labels
            {
                cout << "Enter label number " << i + 1 << endl; //print label number
                labels[i].readLabel(); //read label
            }
        }
    }

    void LabelMaker::printLabels() //print labels
    {
        for (int i = 0; i < noOfLabels; i++) //loop to print labels
        {
            labels[i].printLabel(); //print label
            cout << endl; //print new line
        }
    }
}