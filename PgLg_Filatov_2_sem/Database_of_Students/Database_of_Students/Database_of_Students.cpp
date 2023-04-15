// Кузнецов Алексей, БАСО-04-22. Курсовая работа. Вариант 34.
// 11.04.2023 22:40
// 15.04.2023 18:45

#include <iostream>
using namespace std;
#include <windows.h>
//#include <stdio.h>
#include <fstream>
#include <string>

bool Check(string _word) // проверка, есть ли в слове цифры
{
    string int_alphabet = "0123456789";
    for (int i = 0; i < _word.length(); i++)
    {
        for (int j = 0; j < int_alphabet.length(); j++)
            if (_word[i] == int_alphabet[j]) { return false; }
    }
    return true;
}
void Clear() // очистка буфера
{
    cin.clear(); cin.ignore(40000, '\n'); 
}
class Date
{
    //int Day, Month, Year;
public:
    int Day, Month, Year;
    Date() // конструктор по умолчанию
    {
        Day = 0; Month = 0; Year = 0;
    }
    Date(int _Day, int _Month, int _Year)
    {
        Day = _Day; Month = _Month; Year = _Year;
    }
    void SetDate(int _Day, int _Month, int _Year) // ввод
    {
        Day = _Day; Month = _Month; Year = _Year;
    }
    void SetDate(Date Date) // ввод
    {
        SetDate(Date.Day, Date.Month, Date.Year);
    }
    void SetDate() // ввод с клавиатуры
    {
    vvod_d:cout << "День: "; cin >> Day;
        if (Day > 31 or Day < 1)
        {
            cout << "Ошибка ввода.\n"; Clear(); goto vvod_d; // очистка буфера в случае неправильного ввода
        }
        Clear(); // очистка буфера
    vvod_m:cout << "Месяц: "; cin >> Month;
        if (Month > 12 or Month < 1)
        {
            cout << "Ошибка ввода.\n"; Clear(); goto vvod_m; // очистка буфера в случае неправильного ввода
        }
        Clear(); // очистка буфера
    vvod_y:cout << "Год: "; cin >> Year;
        if (Year < 1900 or Year > 2023)
        {
            cout << "Ошибка ввода.\n"; Clear(); goto vvod_y; // очистка буфера в случае неправильного ввода
        }
        Clear(); // очистка буфера
    }
    void SetDateFromFile()
    {
        ifstream file;
        file.open("DB.txt", ios::out);
        file >> Day >> Month >> Year; 
        file.close();
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
    
    void InputInFile(const char _filename[])
    {
        FILE* file;
        fopen_s(&file, _filename, "a");
        fprintf(file, "%d %d %d ", Day, Month, Year);
        fclose(file);
    }
    void InputInFile()
    {
        FILE* file;
        fopen_s(&file, "DB.txt", "a");
        fprintf(file, "%d %d %d ", Day, Month, Year);
        fclose(file);
    }
    //int GetDate()
    //{
    //    //Date GD; GD.Day = Day; GD.Month = Month; GD.Year = Year;
    //    return Day, Month, Year;
    //}
    void PrintDate() // вывод значений
    {
        cout << Day << " " << Month << " " << Year;
    }
    ~Date() { ; } // деструктор
}; 

class Student
{
    string LastName, FirstName, SurName; // ФИО
    Date BirthDate; // Дата рождения
    int EnrollmentYear; // Год поступления
    string Institute, Department, Group, RecordBook; // Институт, кафедра, группа, номер зачетной книжки (шифр)
    string Sex; // Пол. м = мужчина, ж = женщина

public:
    Student() // конструктор по умолчанию
    {
        LastName = "undefined"; FirstName = "undefined"; SurName = "undefined";
        BirthDate.SetDate(0, 0, 0); EnrollmentYear = 0;
        Institute = "undefined"; Department = "undefined"; Group = "undefined"; RecordBook = "undefined";
        Sex = 'u';
    }
    Student(string _LastName, string _FirstName, string _SurName, Date _BirthDate, int _EnrollmentYear,
        string _Institute, string _Department, string _Group, string _RecordBook, string _Sex)
    {
        LastName = _LastName; FirstName = _FirstName; SurName = _SurName;
        BirthDate.SetDate(_BirthDate); EnrollmentYear = _EnrollmentYear;
        Institute = _Institute; Department = _Department; Group = _Group; RecordBook = _RecordBook;
        Sex = _Sex;
    }
    void SetStudent(string _LastName, string _FirstName, string _SurName, Date _BirthDate, int _EnrollmentYear,
        string _Institute, string _Department, string _Group, string _RecordBook, string _Sex)
    {
        LastName = _LastName; FirstName = _FirstName; SurName = _SurName;
        BirthDate.SetDate(_BirthDate); EnrollmentYear = _EnrollmentYear;
        Institute = _Institute; Department = _Department; Group = _Group; RecordBook = _RecordBook; 
        Sex = _Sex;
    }

    void SetStudent() // ввод с клавиатуры
    {
    INPUT_LASTNAME:cout << "Фамилия: "; cin >> LastName;
        if (!(Check(LastName))) { cout << "Ошибка ввода. Фамилия не должна содержать цифр. "; goto INPUT_LASTNAME; }
        Clear(); // очистка буфера
    INPUT_FIRSTNAME:cout << "Имя: "; cin >> FirstName;
        if (!(Check(FirstName))) { cout << "Ошибка ввода. Имя не должно содержать цифр. "; goto INPUT_FIRSTNAME; }
        Clear(); // очистка буфера
    INPUT_SURNAME:cout << "Отчество: "; cin >> SurName;
        if (!(Check(SurName))) { cout << "Ошибка ввода. Отчество не должно содержать цифр. "; goto INPUT_SURNAME; }
        Clear(); // очистка буфера
        cout << "Дата рождения: "; BirthDate.SetDate();
    INPUT_ENROLLMENT:cout << "Год поступления: "; cin >> EnrollmentYear;
        if (EnrollmentYear < 1900) { cout << "Ошибка ввода. "; Clear(); goto INPUT_ENROLLMENT; }
        Clear(); // test 3
        cout << "Институт: "; cin >> Institute;
        cout << "Кафедра: "; cin >> Department;
        cout << "Группа: "; cin >> Group;
        cout << "Номер зачетной книжки: "; cin >> RecordBook;
    INPUT_SEX:cout << "Пол (м-мужчина, ж-женщина): "; cin >> Sex;
        if ((Sex != "м") && (Sex != "ж")) { cout << "Ошибка ввода. "; goto INPUT_SEX; }
        Clear();
    }

    //void InputInFile()
    //{

    //    FILE* file;
    //    //ofstream wf("DB.txt", ios::out | ios::app);
    //    /*wf.write((char*)&LastName(sizeof(Student));
    //    wf.close();*/
    //    //"DB.txt" << LastName;
    //    fopen_s(&file, "DB.txt", "a");
    //    fprintf_s(file, "%s %s %s ", LastName, FirstName, SurName);
    //    //BirthDate.InputInFile();
    //    fprintf(file, "%d %s %s %s %s %s \n", EnrollmentYear, Institute, Department, Group, RecordBook, Sex);
    //    fclose(file);
    //}

    void InputInFile()
    {

        ofstream file;
        file.open("DB.txt", ios::app);
        file << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " " 
            << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " " 
            << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
        file.close();
    }

    void InputInFile(const char _filename[])
    {
        string choice;
        input_choice:cout << "Введенные данные: " << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
            << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
            << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
        cout << "Хотите записать данные в файл?\n 1 - Да.\n 0 - Нет." << endl;
        cin >> choice;
        if (choice == "1")
        {
            ofstream file;
            file.open(_filename, ios::app);
            file << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
            file.close();
        }
        if (choice == "0") { cout << "Данные не записаны. " << endl; }
        if (choice != "1" && choice != "0") { cout << "Ошибка ввода. " << endl; goto input_choice; }
    }
    void OutputFromFile(const char _filename[])
    {
        ifstream file;
        string line, searchline;
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline; 
        file.open(_filename, ios::out);
        while (getline(file, line)) 
        {
            if (line.find(searchline) != string::npos)
            {
                cout << line << endl;
            }
        }
        file.close();
    }
    void OutputFromFile(const char _filename[], int i)
    {
        ifstream file;
        string line, searchline;
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex)
        {
            if (RecordBook.find(searchline) != string::npos)
            {
                PrintStudent();
            }
        }
        file.close();
    }
    void DeleteInfo(const char _filename[])
    {
        ifstream file;
        string line, searchline;
        int deleting_choice = 0;
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex)
        {
            if (RecordBook.find(searchline) != string::npos)
            {
                cout << "Выбранные для удаления данные: " << endl; PrintStudent();
            DELETING_CHOICE_INPUT:cout << "Вы уверены, что хотите удалить данные?\n 1. Удалить.\n 0. Отмена." << endl;
                cin >> deleting_choice;
                if (!(deleting_choice >= 0 && deleting_choice <= 1))
                {
                    cout << "Ошибка ввода.\n"; Clear(); goto DELETING_CHOICE_INPUT;
                }
            }
        }
        switch(deleting_choice)
        {
        case 0:
            file.close();
            cout << "Данные не удалены." << endl;
            break;
        case 1:
            file.close();
            file.open(_filename, ios::in);
            while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
                EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex)
            {
                if (!(RecordBook.find(searchline) != string::npos))
                {
                    ofstream file_out;
                    file_out.open("DBtemp.txt", ios::app);
                    file_out << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                        << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                        << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
                    file_out.close();
                }
            }
            file.close();
            remove(_filename);
            rename("DBtemp.txt", _filename);
            cout << "Данные удалены." << endl;
        }
        
        
    }
    void ChangeInfo()
    {
        //
    }
    void PrintStudent() // вывод значений
    {
        cout << LastName << " " << FirstName << " " << SurName << " "; 
        BirthDate.PrintDate(); cout << " " << EnrollmentYear << " " << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
    }
    ~Student() { ; } // деструктор
};

int main()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    //FILE* file;
    /*fopen_s(&file, "DB.txt", "w");
    fclose(file);*/
    int choice;
start:cout << "Выберите операцию из нижеперечисленных. \n 1. Добавить запись о студенте в файл.\n 2. Отобразить данные о выбранном студенте.\n 3. Изменить данные студента.\n";
    cout << " 4. Удалить данные студента.\n 5. Выполнить ...задание...\n 6. Выход из программы" << endl;
choice_input:cout << "Выберите операцию: ";
    cin >> choice;
    if (!(choice>0 && choice<7)) // проверка на допустимость значения
    {
        cout << "Ошибка ввода.\n"; Clear(); goto choice_input; // очистка буфера в случае неправильного ввода и возврат к началу ввода
    }
    //cout << endl << choice;
    Student A1; A1.SetStudent("zhemerikin", "max", "alexeevich", { 25,10,2004 }, 2022, "Кибербезопасности", "КБ-1", "БАСО-04-22", "22Б034", "м");
    //A1.PrintStudent();
    //A1.InputInFile("DB.txt");
    //fopen_s(&file, "DB.txt", "a");
    //fprintf(file, "%d ", 1478);
    //Date SALAM(25, 10, 2004);
    //SALAM.InputInFile("АРТЕМ ЭМ АЛЕКСАНДРОВИЧ.txt");
    //A1.InputInFile(); 
    //fclose(file);
    
    //Date B; B.SetDate(); B.PrintDate();
    //int C;
    //Student A2; A2.SetStudent(); A2.PrintStudent();
    //cout << "get date B: "; C = B.GetInfo("Day"); cout << C; C = B.GetInfo("Month"); cout << C;
    Student InputStudent;
    Student OutputStudent;
    switch (choice) 
    {
    case 1:
        cout << "Добавить запись о студенте: " << endl;
        InputStudent.SetStudent(); InputStudent.InputInFile("DB.txt");
        system("pause");
        system("cls");
        goto start;
        break;
    case 2:
        OutputStudent.OutputFromFile("DB.txt",2);
        system("pause");
        system("cls");
        goto start;
        break;
    case 3:
        goto start;
        break;
    case 4:
        OutputStudent.DeleteInfo("DB.txt");
        system("pause");
        system("cls");
        goto start;
        break;
    case 5:
        goto start;
        break;
    case 6:
        //goto start;
        return 0;
        break;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
