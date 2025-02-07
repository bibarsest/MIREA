// Кузнецов, БАСО-04-22. Вариант 4
// Сортировка: Простая вставка (сортировка колоды карт). Ключ: Дата зачисления. По возрастанию.

#include <iostream>
#include <windows.h>
#include "template_list_bib.h"
//#include "clDate_bib.h"
//#include "clSession_bib.h"
using namespace std;

//void Clear() { cin.clear(); cin.ignore(INT_MAX, '\n'); }

//class clDate
//{
//    int Day;
//    int Month;
//    int Year;
//public:
//    clDate() 
//    {
//        Day = 0; Month = 0; Year = 0;
//    }
//    clDate(int day, int month, int year) 
//    {
//        Day = day; Month = month; Year = year;
//    }
//    
//    void printDate() 
//    {
//        cout << Day << "." << Month << "." << Year << endl;
//    }
//    bool setDate(int day, int month, int year)
//    {
//        if (day > 0 && day < 32 && month>0 && month < 13) { Day = day; Month = month; Year = year; return true; }
//        else return false;
//    }
//    
//    void setDate() 
//    {
//        bool day_input_is_true = true, month_input_is_true = true, year_input_is_true = true;
//        while (day_input_is_true)
//        {
//            cout << "День: "; cin >> Day;
//            if (cin.fail() || Day > 31 || Day < 1)
//            {
//                cout << "Ошибка ввода. Область допустимого значения [1-31].\n"; Clear(); 
//            }
//            else day_input_is_true = false;
//        }
//        Clear(); 
//        while (month_input_is_true)
//        {
//            cout << "Месяц: "; cin >> Month;
//            if (cin.fail() || Month > 12 || Month < 1)
//            {
//                cout << "Ошибка ввода. Область допустимого значения [1-12].\n"; Clear(); 
//            }
//            else month_input_is_true = false;
//        }
//        Clear(); 
//        while (year_input_is_true)
//        {
//            cout << "Год: "; cin >> Year;
//            if (cin.fail() || Year > 3000 || Year < 0)
//            {
//                cout << "Ошибка ввода. Область допустимого значения [1-3000].\n"; Clear();
//            }
//            else year_input_is_true = false;
//        }
//        Clear(); 
//    }
//
//    void operator = (const clDate& dt) { Day = dt.Day; Month = dt.Month; Year = dt.Year; }
//    bool operator == (clDate& dt) { return (Day == dt.Day && Month == dt.Month && Year == dt.Year); }
//    bool operator < (clDate& dt) 
//    { 
//        if (Year < dt.Year) return true;
//        if (Year == dt.Year && Month < dt.Month) return true;
//        if (Year == dt.Year && Month == dt.Month && Day < dt.Day) return true;
//        return false; 
//    }
//    bool operator > (clDate& dt) 
//    {
//        if (Year > dt.Year) return true;
//        if (Year == dt.Year && Month > dt.Month) return true;
//        if (Year == dt.Year && Month == dt.Month && Day > dt.Day) return true;
//        return false; 
//    }
//    friend ostream& operator<<(ostream& os, clDate& dt)
//    {
//        os << dt.Day << "." << dt.Month << "." << dt.Year;
//        return os;
//    }
//    friend istream& operator>>(istream& is, clDate& dt)
//    {
//        bool day_input_is_true = true, month_input_is_true = true, year_input_is_true = true;
//        while (day_input_is_true)
//        {
//            cout << "День: "; is >> dt.Day; 
//            if (cin.fail() || dt.Day > 31 || dt.Day < 1)
//            {
//                cout << "Ошибка ввода. Область допустимого значения [1-31].\n"; Clear();
//            }
//            else day_input_is_true = false;
//        }
//        Clear();
//        while (month_input_is_true)
//        {
//            cout << "Месяц: "; is >> dt.Month; 
//            if (cin.fail() || dt.Month > 12 || dt.Month < 1)
//            {
//                cout << "Ошибка ввода. Область допустимого значения [1-12].\n"; Clear();
//            }
//            else month_input_is_true = false;
//        }
//        Clear();
//        while (year_input_is_true)
//        {
//            cout << "Год: "; is >> dt.Year; 
//            if (cin.fail() || dt.Year > 3000 || dt.Year < 0)
//            {
//                cout << "Ошибка ввода. Область допустимого значения [1-3000].\n"; Clear();
//            }
//            else year_input_is_true = false;
//        }
//        Clear();
//        return is;
//    }
//};

class clSession
{
    string Name;
    clDate Date;
    string Mark;
    string Teacher;
public:
    clSession(string _Name, clDate _Date, string _Mark, string _Teacher) { Name = _Name; Date = _Date; Mark = _Mark; Teacher = _Teacher; }
    clSession() { Name = "#"; Mark = "#"; Teacher = "#"; }
    friend ostream& operator<<(ostream& os, clSession& obj)
    {
        os << obj.Name << " " << obj.Mark << " | " << obj.Date << " | " << obj.Teacher << endl;
        return os;
    }
    friend istream& operator>>(istream& is, clSession& obj)
    {
        cout << "Наименование предмета: "; is >> obj.Name; Clear();
        obj.Mark = "#";
        while (obj.Mark != "1" && obj.Mark != "2" && obj.Mark != "3" && obj.Mark != "4" && obj.Mark != "5" && obj.Mark != "з" && obj.Mark != "н")
        {
            cout << "Оценка [1-5, з - зачет, н - незачет]: "; is >> obj.Mark; cin.ignore(INT_MAX, '\n');
        }
        cin.clear();
        cout << "Дата сдачи: "; is >> obj.Date;
        cout << "Принимающий преподаватель: "; is >> obj.Teacher; Clear();
        return is;
    }
    void print()
    {
        cout << Name << " " << Mark << " | " << Date << " | " << Teacher << endl;
    }
};
class Semester
{
public:
    int number_of_semester, number_of_sessions; clSession ses;//
    clList<clSession> Session;
    Semester(int _number_of_semester, int _number_of_sessions, clSession _Session) { number_of_semester = _number_of_semester; number_of_sessions = _number_of_sessions; ses = _Session; }//Session.addNode(_Session); } // проблема в addNode
    Semester() { number_of_semester = 0; number_of_sessions = 0; }
    friend ostream& operator<<(ostream& os, Semester& obj)
    {
        os << "Семестр: " << obj.number_of_semester << " | Предметов: " << obj.number_of_sessions << endl;
        obj.Session.printList();
        return os;
    }
    friend istream& operator>>(istream& is, Semester& obj)
    {
        obj.number_of_semester = 0; obj.number_of_sessions = 0;

        //while (cin.fail() || obj.number_of_semester < 1 || obj.number_of_semester > 9)
        //{
        //    cout << "Номер семестра [1-9]: "; is >> obj.number_of_semester; Clear();//cin.ignore(INT_MAX, '\n');
        //}
        //cin.clear();

        while (cin.fail() || obj.number_of_sessions < 1 || obj.number_of_sessions > 10)
        {
            cout << "Количество предметов [1-10]: "; is >> obj.number_of_sessions; Clear();//cin.ignore(INT_MAX, '\n');
        }
        cin.clear();
        for (int i = 0; i < obj.number_of_sessions; i++)
        {
            cout << "Предмет №"<< i+1 << endl; is >> obj.ses;
            obj.Session.addNode(obj.ses);
        }
        return is;
    }
    void print()
    {
        cout << "В №" << number_of_semester << " семестре " << number_of_sessions << " предметов. " << endl; Session.printList();
    }
};

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
    clList<Semester> Semesters;
    int number_of_semesters; Semester sem[9];
    clStudent() { LastName = "LN"; FirstName = "FN"; SurName = "SN"; Sex = "S"; Scholarship = 0; number_of_semesters = 0; }
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
            << st.Scholarship << endl << "Информация о сессиях | Количество семестров: " << st.number_of_semesters << endl; st.Semesters.printList();
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
        st.number_of_semesters = 0;
        while (cin.fail() || st.number_of_semesters < 1 || st.number_of_semesters > 9)
        {
            cout << "Количество семестров [1-9]: "; is >> st.number_of_semesters; Clear();
        }
        cin.clear();
        for (int i = 0; i < st.number_of_semesters; i++)
        {
            cout << "Семестр №" << i + 1 << endl; is >> st.sem[i]; st.sem[i].number_of_semester = i + 1;
            cout << "!!!!!!! 1" << endl;
            st.Semesters.addNode(st.sem[i]); //тут ошибка с указателем 0xFFFFFFFF (удаляется список предметов)
            cout << "!!!!!!! 2" << endl;
        }
        //cout << "Количество семестров [1-9]: "; is >> st.number_of_semesters;
        return is;
    }
    void getsubj(int _sem_num, int _subjnum)
    {
        Semesters[_sem_num];
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

    //clSession* ses = new clSession;
    clSession ses("rus", {10,10,2020}, "5", "petrov");
    clList<clSession> Session; Session.addNode(ses);
    Session.addNode({"math", { 11,11,2020 }, "5", "vegera"});
    Session.addNode({ "linal", { 12,12,2020 }, "4", "rusakov" });
    //Session.printList();
    cout << ses;
    //cin >> ses; cout << ses;
    cout << "0000\n";
    Session.printList();
    //Semester sem(2, 2, { "rus", {10,10,2020}, "5", "petrov" });
    Semester sem(1, 1, ses); 
    cout << "1111\n";
    clList<Semester> Semesters; Semesters.addNode(sem);
    Semesters.addNode({ 2, 2, { "math", {10,10,2020}, "5", "kuzn" } }); 
    Semesters.addNode({ 3, 1, { "pl", {10,10,2020}, "5", "fil" } });
    Semesters.addNode(sem); 
    cout << "2222\n";
    Semesters.printList();
    cout << "333\n";
    cout << sem;
    //cin >> sem; cout << sem;

    cout << "test []\n";
    Session[1];

    //clStudent h("kuzn", "alex", "alexandrovich", { 10,25,2004 }, "м", { 1,1,2022 }, 3800);
    //cout << h;

    clStudent hum;
    cin >> hum; cout << hum;
    cout << "test hum[]\n";
    cout << "hum.getsubj: "; hum.getsubj(1, 1); //возвращает весь семестр
    cout << "\nhum.Semesters: "; hum.Semesters[1]; //возвращает весь семестр
    
    clGroup group;
    cin >> group; system("cls"); cout << endl << "Введенные данные: " << endl << group;
    
    group.sortStudent();
    cout << endl << "Отсортированные данные: " << endl << group;
    system("pause");
}
