#pragma once
#include <iostream>
using namespace std;

struct Session
{
    string subject = "#";
    string mark = "#";
    Session(){}
    Session(string subj, string m) : subject(subj), mark(m) {}
};