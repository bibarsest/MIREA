#pragma once
#include <iostream>
#include "clDate_bib.h"
#include "template_list_bib.h"
using namespace std;
class clSession
{
    string Name;
    clDate Date;
    string Mark;
    string Teacher;
    //clSession() { Mark = "#"; }
};

class Semester
{
public:
    int number;
    clList<clSession> Session;

};