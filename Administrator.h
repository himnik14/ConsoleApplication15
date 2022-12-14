#pragma once
#include "Students.h"
class Administrator :
    public Students
{

    vector<Students> Stud;
    ifstream inp;
    ofstream out;
    string path_to_file = "C:\\Games\\ds1.txt";
public:
    void edit_info();
    Administrator();
    void outputFile();
    void outToConsole();
    void inputFile();
    void add_data();
    void delete_info();
    void admin_prog();
};

