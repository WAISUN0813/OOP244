/*
**********************************************************************************************************************************
Full Name  : WAI SUN LAM
Student ID#: 146691225
Email      : wslam4@myseneca.ca
Date       : 06/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************************************************************************************
*/
#ifndef SDDS_CARINVENTORY_H_
#define SDDS_CARINVENTORY_H_
namespace sdds {
    class CarInventory {
    private:
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();
    public:
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
        ~CarInventory();
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };
    int find_similar(CarInventory car[], const int num_cars);
}
#endif // !SDDS_CARINVENTORY_H_