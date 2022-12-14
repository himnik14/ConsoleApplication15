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
	cout << "Введите средний балл для студента: " << name << endl;
	cin >> GPA;
	cin.clear();
	getchar();
	if (GPA < 1 || GPA > 5)
		throw exception("Средний балл студента не может быть больше 5 и меньше 1!\n");
	this->GPA = GPA;
}
Students::Students()
{

}

void Students::set_group()
{
	cout << "Введите группу, в которой учится студент " << name << endl;
	getline(cin, group);
	const regex r("[А-Яа-я\\-0-9]*");
	if (group.empty())
		throw exception("Вы ввели пустую строку!\n");
	else if (!regex_match(group, r))
		throw exception("Некорректный ввод данных!\n");
	this->group = group;
}

void Students::set_name()
{
	cout << "Введите имя студента\n";
	getline(cin, name);
	const regex r("[А-яа-я\\s]*");
	if (name.empty())
		throw exception("Вы ввели пустую строку!\n");
	else if (!regex_match(name, r))
		throw exception("Некорректный ввод данных!\n");
	else if (name.size() > 50)
		throw exception("Слишком длиинное ФИО\n");
	this->name = name;
}

void Students::set_optional_disciplines()
{
	cout << "Выберите факультатинвые дисциплины, на которые ходит студент\n1.Математика\n2.Физика\n3.Программирование\n4.Английский язык\n5.Базы данных\n6.Закончить отмечать факультативы\n";
	map<string, int>::iterator iter;
	bool tr = true;
	while (tr)
	{
		switch (_getch())
		{
		case '1':
			iter = opt_disc.find("Математика");
			iter->second = 1;
			break;
		case '2':
			iter = opt_disc.find("Физика");
			iter->second = 1;
			break;
		case '3':
			iter = opt_disc.find("Программирование");
			iter->second = 1;
			break;
		case '4':
			iter = opt_disc.find("Английский язык");
			iter->second = 1;
			break;
		case '5':
			iter = opt_disc.find("Базы данных");
			iter->second = 1;
			break;
		case '6':
			tr = false;
			break;
		default:
			cout << "Неверный ввод с клавиатуры!\n";
			break;
		}
	}
}

Students::Students(string name, string group, double GPA, int eng, int BD, int math, int prog, int phis)
{
	this->name = name;
	this->GPA = GPA;
	this->group = group;
	opt_disc["Математика"] = math;
	opt_disc["Программирование"] = prog;
	opt_disc["Физика"] = phis;
	opt_disc["Английский язык"] = eng;
	opt_disc["Базы данных"] = BD;
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
	opt_disc["Математика"] = 0;
	opt_disc["Программирование"] = 0;
	opt_disc["Физика"] = 0;
	opt_disc["Английский язык"] = 0;
	opt_disc["Базы данных"] = 0;
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
		throw exception("Данные не сохранены!\n");
	}
}
