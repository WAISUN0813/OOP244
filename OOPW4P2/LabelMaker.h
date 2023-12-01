/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 10/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

#include "Label.h"

namespace sdds 
{

    class LabelMaker 
    {
        Label* labels; // pointer to dynamic array of Labels
        int noOfLabels; // number of labels

    public:
        LabelMaker(int noOfLabelsArg);
        ~LabelMaker();

        void readLabels();
        void printLabels();
    };

}

#endif //SDDS_LABELMAKER_H
