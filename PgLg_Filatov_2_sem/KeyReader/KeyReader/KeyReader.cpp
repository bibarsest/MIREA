#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
using namespace std;
struct line
{
    string name, key;
    line() { name = "#"; key = "#"; }
};
int HowMuchLinesInFile(const char _filename[])
{
    ifstream count_file; int count = 0; string line;
    count_file.open(_filename, ios::in);
    while (!count_file.eof()) { getline(count_file, line); count++; }
    count_file.close();
    return count;
}
int HowMuchLinesInFileWithSection()
{
    ifstream file; file.open("test.txt", ios::in);
    string buffer; int countlines = 0;
    while (!file.eof())
    {
        getline(file, buffer);
        if (buffer.find(" | ") != string::npos)
        {
            countlines++;
        }
    }
    file.close();
    return countlines;
}

void RewriteFile()
{
    ifstream file1; file1.open("test.txt", ios::in);
    ofstream file2; file2.open("test2.txt", ios::out);
    string buffer;
    while (!file1.eof())
    {
        getline(file1, buffer);
        if (buffer.find("|") != string::npos)
        {
            file2 << buffer << endl;
        }
    }
    file1.close(); file2.close();
}

void WriteFile()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    string linefile, buffer; //RewriteFile();
    const int countlines = HowMuchLinesInFile("test2.txt"); cout << countlines << endl;
    line* lines = new line[countlines]();
    //line lines[countlines];
    ifstream file,file_temp_in; file.open("test2.txt", ios::in);
    ofstream file_out; 
    int count = 0;
    while (!file.eof())
    {
        getline(file, linefile);
        file_out.open("temp.txt", ios::out);
        file_out << linefile;
        file_out.close();
        file_temp_in.open("temp.txt", ios::in);
        file_temp_in >> buffer; lines[count].name = buffer;
        while (file_temp_in >> buffer)
        {
            if (buffer == "|") break;
            lines[count].name += " ";
            lines[count].name += buffer;
        }
        file_temp_in >> lines[count].key;
        file_temp_in.close(); 
        //cout << i << "\t";
        //cout << lines[count].name << " | " << lines[count].key << endl;
        count++;
    }
    file.close();  cout << "Ключи записаны.\n";
    //cout << lines[600].name << lines[600].key;
}
void ListofGames()
{
    fstream file; file.open("list.txt");
    /*for (int i = 0; i < countlines; i++)
    {
        if (file.lines[i].name)
    }*/
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    //RewriteFile();
    WriteFile();
}