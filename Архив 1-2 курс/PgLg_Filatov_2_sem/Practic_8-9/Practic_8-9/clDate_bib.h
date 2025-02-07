#pragma once
#include <iostream>
using namespace std;

void Clear() { cin.clear(); cin.ignore(INT_MAX, '\n'); }

class clDate
{
    int Day;
    int Month;
    int Year;
public:
    clDate()
    {
        Day = 0; Month = 0; Year = 0;
    }
    clDate(int day, int month, int year)
    {
        Day = day; Month = month; Year = year;
    }

    void printDate()
    {
        cout << Day << "." << Month << "." << Year << endl;
    }
    bool setDate(int day, int month, int year)
    {
        if (day > 0 && day < 32 && month>0 && month < 13) { Day = day; Month = month; Year = year; return true; }
        else return false;
    }

    void setDate()
    {
        bool day_input_is_true = true, month_input_is_true = true, year_input_is_true = true;
        while (day_input_is_true)
        {
            cout << "День: "; cin >> Day;
            if (cin.fail() || Day > 31 || Day < 1)
            {
                cout << "Ошибка ввода. Область допустимого значения [1-31].\n"; Clear();
            }
            else day_input_is_true = false;
        }
        Clear();
        while (month_input_is_true)
        {
            cout << "Месяц: "; cin >> Month;
            if (cin.fail() || Month > 12 || Month < 1)
            {
                cout << "Ошибка ввода. Область допустимого значения [1-12].\n"; Clear();
            }
            else month_input_is_true = false;
        }
        Clear();
        while (year_input_is_true)
        {
            cout << "Год: "; cin >> Year;
            if (cin.fail() || Year > 3000 || Year < 0)
            {
                cout << "Ошибка ввода. Область допустимого значения [1-3000].\n"; Clear();
            }
            else year_input_is_true = false;
        }
        Clear();
    }

    void operator = (const clDate& dt) { Day = dt.Day; Month = dt.Month; Year = dt.Year; }
    bool operator == (clDate& dt) { return (Day == dt.Day && Month == dt.Month && Year == dt.Year); }
    bool operator < (clDate& dt)
    {
        if (Year < dt.Year) return true;
        if (Year == dt.Year && Month < dt.Month) return true;
        if (Year == dt.Year && Month == dt.Month && Day < dt.Day) return true;
        return false;
    }
    bool operator > (clDate& dt)
    {
        if (Year > dt.Year) return true;
        if (Year == dt.Year && Month > dt.Month) return true;
        if (Year == dt.Year && Month == dt.Month && Day > dt.Day) return true;
        return false;
    }
    friend ostream& operator<<(ostream& os, clDate& dt)
    {
        os << dt.Day << "." << dt.Month << "." << dt.Year;
        return os;
    }
    friend istream& operator>>(istream& is, clDate& dt)
    {
        bool day_input_is_true = true, month_input_is_true = true, year_input_is_true = true;
        while (day_input_is_true)
        {
            cout << "День: "; is >> dt.Day;
            if (cin.fail() || dt.Day > 31 || dt.Day < 1)
            {
                cout << "Ошибка ввода. Область допустимого значения [1-31].\n"; Clear();
            }
            else day_input_is_true = false;
        }
        Clear();
        while (month_input_is_true)
        {
            cout << "Месяц: "; is >> dt.Month;
            if (cin.fail() || dt.Month > 12 || dt.Month < 1)
            {
                cout << "Ошибка ввода. Область допустимого значения [1-12].\n"; Clear();
            }
            else month_input_is_true = false;
        }
        Clear();
        while (year_input_is_true)
        {
            cout << "Год: "; is >> dt.Year;
            if (cin.fail() || dt.Year > 3000 || dt.Year < 0)
            {
                cout << "Ошибка ввода. Область допустимого значения [1-3000].\n"; Clear();
            }
            else year_input_is_true = false;
        }
        Clear();
        return is;
    }
};
