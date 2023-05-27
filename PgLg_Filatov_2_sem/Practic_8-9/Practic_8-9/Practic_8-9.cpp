// Кузнецов, БАСО-04-22. Вариант 4
// Сортировка: Простая вставка (сортировка колоды карт). Ключ: Дата зачисления. По возрастанию.

#include <iostream>
#include <windows.h>
#include "template_list_bib.h"
//#include "clDate_bib.h"
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

//template <class infoT> // перенести в заголовочный файл
//class clList
//{
//    struct Node
//    {
//        infoT info;
//        Node* next;
//    };
//    Node* head;
//public:
//    clList();
//    ~clList();
//};

//class clSession
//{
//    string Name;
//    clDate Date;
//    string Mark;
//    string Teacher;
//    clSession() { Mark = "#"; }
//};

class clStudent
{
    /*struct Node
    {
        clSession* Session;
        Node* next;
    };
    Node* head;*/
protected:
    string LastName;
    string FirstName;
    string SurName;
    clDate BirthDate;
    string Sex;
    clDate EnrollmentDate;
    int Scholarship;
public:
    clStudent() { LastName = "LN"; FirstName = "FN"; SurName = "SN"; Sex = "S"; Scholarship = 0; }
    clStudent(string _LastName, string _FirstName, string _SurName, clDate _BirthDate, string _Sex, clDate _EnrollmentDate, int _Scholarship)
    {
        LastName = _LastName; FirstName = _FirstName; SurName = _SurName; BirthDate = _BirthDate; Sex = _Sex; EnrollmentDate = _EnrollmentDate; Scholarship = _Scholarship;
    }
    void operator = (const clStudent& st) { LastName = st.LastName; FirstName = st.FirstName; SurName = st.SurName; Sex = st.Sex; Scholarship = st.Scholarship; BirthDate = st.BirthDate; EnrollmentDate = st.EnrollmentDate; }
    bool operator == (clStudent& st) { return (EnrollmentDate == st.EnrollmentDate); }
    bool operator < (clStudent& st) { return (EnrollmentDate < st.EnrollmentDate); }
    bool operator > (clStudent& st) { return (EnrollmentDate > st.EnrollmentDate); }
    friend ostream& operator<<(ostream& os, clStudent& st)
    {
        os << st.LastName << " " << st.FirstName << " " << st.SurName;
        if (st.Sex == "м") os << ", мужчина";
        if (st.Sex == "ж") os << ", женщина";
        if (st.Sex != "м" && st.Sex != "ж") os << ", пол не определен" << endl;
        os << " | Дата рождения: " << st.BirthDate << " | Дата поступления: " << st.EnrollmentDate << " | Размер стипендии: "
            << st.Scholarship;
        return os;
    }
    friend istream& operator>>(istream& is, clStudent& st)
    {
        bool sex_input = true, scholarship_input = true;
        cout << "Фамилия: "; is >> st.LastName; Clear();
        cout << "Имя: "; is >> st.FirstName; Clear();
        cout << "Отчество: "; is >> st.SurName; Clear();
        cout << "Дата рождения: "; is >> st.BirthDate;
        while (sex_input)
        {
            cout << "Пол [м/ж]: "; is >> st.Sex; 
            if (cin.fail() || (st.Sex != "м" && st.Sex != "ж")) { cout << "Ошибка ввода." << endl; Clear(); }
            else { sex_input = false; }
        }
        Clear();
        cout << "Дата поступления: "; is >> st.EnrollmentDate;
        while (scholarship_input)
        {
            cout << "Размер стипендии [0-50000]: "; is >> st.Scholarship; 
            if (cin.fail() || st.Scholarship < 0 || st.Scholarship > 50000) { cout << "Ошибка ввода." << endl; Clear(); }
            else { scholarship_input = false; }
        }
        return is;
    }
    
};
class clGroup
{
protected:
    string GroupName;
    string Institute;
    string Department;
    string Curator;
    int Size;
    clStudent* Student;
public:
    ~clGroup() { delete[] Student; };
    void Swap(clStudent& A, clStudent& B)
    {
        clStudent temp = A; A = B; B = temp;
    }
    int ifSwap(clStudent& A, clStudent& B)
    {
        if (A > B)
        {
            Swap(A, B); return 1;
        }
        else return 0;
    }
    void sort(clStudent* a, int L, int R)
    {
        for (int i = L + 1; i <= R; i++)
            for (int j = i; j > L; j--)
                ifSwap(a[j - 1], a[j]);
    }
    void sortStudent() { sort(Student, 0, Size - 1); }
    friend istream& operator>>(istream& is, clGroup& gp)
    {
        bool size_input = true;
        cout << "Название группы: "; is >> gp.GroupName; Clear();
        cout << "Институт: "; is >> gp.Institute; Clear();
        cout << "Кафедра: "; is >> gp.Department; Clear();
        cout << "ФамилияИО куратора: "; is >> gp.Curator; Clear();
        while (size_input)
        {
            cout << "Численность группы [0-40]: "; is >> gp.Size;
            if (cin.fail() || gp.Size < 0 || gp.Size > 40) { cout << "Ошибка ввода." << endl; Clear(); }
            else { size_input = false; }
        }
        gp.Student = new clStudent[gp.Size]();
        for (int i = 0; i < gp.Size; i++) 
        {
            cout << "Введите данные студента №" << i+1 << " : ";
            cin >> gp.Student[i];
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, clGroup& gp)
    {
        os << "Группа " << gp.GroupName << " | Институт " << gp.Institute << " | Кафедра " << gp.Department << endl
            << "Куратор: " << gp.Curator << " | Размер группы: " << gp.Size << endl;
        for (int i = 0; i < gp.Size; i++) { os << i+1<< ". " << gp.Student[i] << endl; }
        return os;
    }
    
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    clGroup group;
    cin >> group; cout << endl << "Введенные данные: " << endl << group;
    
    group.sortStudent();
    cout << endl << "Отсортированные данные: " << endl << group;
}
