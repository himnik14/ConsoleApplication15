#include "Students.h"

double Students::get_GPA()
{
	return GPA;
}

string Students::get_group()
{
	return group;
}

string Students::get_name()
{
	return name;
}

map<string, int> Students::get_opt_disc()
{
	return opt_disc;
}

void Students::set_GPA()
{
	cout << "������� ������� ���� ��� ��������: " << name << endl;
	cin >> GPA;
	cin.clear();
	getchar();
	if (GPA < 1 || GPA > 5)
		throw exception("������� ���� �������� �� ����� ���� ������ 5 � ������ 1!\n");
	this->GPA = GPA;
}
Students::Students()
{

}

void Students::set_group()
{
	cout << "������� ������, � ������� ������ ������� " << name << endl;
	getline(cin, group);
	const regex r("[�-��-�\\-0-9]*");
	if (group.empty())
		throw exception("�� ����� ������ ������!\n");
	else if (!regex_match(group, r))
		throw exception("������������ ���� ������!\n");
	this->group = group;
}

void Students::set_name()
{
	cout << "������� ��� ��������\n";
	getline(cin, name);
	const regex r("[�-��-�\\s]*");
	if (name.empty())
		throw exception("�� ����� ������ ������!\n");
	else if (!regex_match(name, r))
		throw exception("������������ ���� ������!\n");
	else if (name.size() > 50)
		throw exception("������� �������� ���\n");
	this->name = name;
}

void Students::set_optional_disciplines()
{
	cout << "�������� �������������� ����������, �� ������� ����� �������\n1.����������\n2.������\n3.����������������\n4.���������� ����\n5.���� ������\n6.��������� �������� ������������\n";
	map<string, int>::iterator iter;
	bool tr = true;
	while (tr)
	{
		switch (_getch())
		{
		case '1':
			iter = opt_disc.find("����������");
			iter->second = 1;
			break;
		case '2':
			iter = opt_disc.find("������");
			iter->second = 1;
			break;
		case '3':
			iter = opt_disc.find("����������������");
			iter->second = 1;
			break;
		case '4':
			iter = opt_disc.find("���������� ����");
			iter->second = 1;
			break;
		case '5':
			iter = opt_disc.find("���� ������");
			iter->second = 1;
			break;
		case '6':
			tr = false;
			break;
		default:
			cout << "�������� ���� � ����������!\n";
			break;
		}
	}
}

Students::Students(string name, string group, double GPA, int eng, int BD, int math, int prog, int phis)
{
	this->name = name;
	this->GPA = GPA;
	this->group = group;
	opt_disc["����������"] = math;
	opt_disc["����������������"] = prog;
	opt_disc["������"] = phis;
	opt_disc["���������� ����"] = eng;
	opt_disc["���� ������"] = BD;
}

void Students::outputmap(map<string, int> mp)
{
	map<string, int>::iterator it = mp.begin();
	for (int i = 0; it != mp.end(); i++, it++)
	{
		cout <<setw(3) << left << " " << to_string(it->second) << setw(1) << left << "    |";
	}
}

Students::Students(int i)
{
	opt_disc["����������"] = 0;
	opt_disc["����������������"] = 0;
	opt_disc["������"] = 0;
	opt_disc["���������� ����"] = 0;
	opt_disc["���� ������"] = 0;
	try
	{
		set_name();
		set_group();
		set_GPA();
		set_optional_disciplines();
	}
	catch (const std::exception& error)
	{
		cout << error.what();
		throw exception("������ �� ���������!\n");
	}
}
