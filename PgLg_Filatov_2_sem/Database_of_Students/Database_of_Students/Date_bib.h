#pragma once
#include <iostream>
using namespace std;
#include "Functions_bib.h"

class Date
{
public:
    int Day, Month, Year;
    Date()
    {
        Day = 0; Month = 0; Year = 0;
    }
    Date(int _Day, int _Month, int _Year)
    {
        Day = _Day; Month = _Month; Year = _Year;
    }
    void SetDate(int _Day, int _Month, int _Year)
    {
        Day = _Day; Month = _Month; Year = _Year;
    }
    void SetDate(Date Date)
    {
        SetDate(Date.Day, Date.Month, Date.Year);
    }
    void SetDate()
    {
        cout << "День: "; cin >> Day;
        while (cin.fail() || Day > 31 || Day < 1)
        {
            cout << "Ошибка ввода. День [1-31]: "; Clear(); cin >> Day;
        }
        Clear();
        cout << "Месяц: "; cin >> Month;
        while (cin.fail() || Month > 12 || Month < 1)
        {
            cout << "Ошибка ввода. Месяц [1-12]: "; Clear(); cin >> Month;
        }
        Clear();
        cout << "Год: "; cin >> Year;
        while (cin.fail() || Year < 1900 || Year > 2023)
        {
            cout << "Ошибка ввода. Год [1900-2023]: "; Clear(); cin >> Year;
        }
        cin.clear();
    }

    friend istream& operator>>(istream& is, Date& dt)
    {
        is >> dt.Day >> dt.Month >> dt.Year;
        return is;
    }
    int GetDay() { return Day; }
    int GetMonth() { return Month; }
    int GetYear() { return Year; }
    int GetInfo(string _info)
    {
        if (_info == "Day") return Day;
        if (_info == "Month") return Month;
        if (_info == "Year") return Year;
    }

    void PrintDate()
    {
        cout << Day << " " << Month << " " << Year;
    }
    ~Date() { ; }
};