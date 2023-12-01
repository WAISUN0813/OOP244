/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 29/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
    class Train {
    private:
        char* m_name;
        int m_noOfPassengers;
        int m_departureTime;
        const int MIN_TIME = 700;
        const int MAX_TIME = 2300;
        const int MAX_NO_OF_PASSENGERS = 1000;
    public:
        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        void finalize();
        bool isInvalid() const;
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;
    };
}

#endif //SDDS_TRAIN_H
