#pragma once

#include <map>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;
class Students
{
	string name, group;
	double GPA;
	map<string, int> opt_disc;
public:
	void outputmap(map<string, int> mp);
	Students();
	map<string, int> get_opt_disc();
	Students(string name, string group, double GPA, int math, int eng, int phis, int BD, int prog);
	Students(int i);
	string get_name();
	string get_group();
	double get_GPA();
	void set_name();
	void set_group();
	void set_GPA();
	void set_optional_disciplines();
};

