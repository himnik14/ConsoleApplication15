#include "Administrator.h"

void Administrator::outputFile()
{
    inp.open(path_to_file);
    vector<string> lines;
    string line;
    while (!inp.eof())
    {
        getline(inp, line);
        if (line.size() != 0)
        {
            if (line != ";")
            {
                if (line.find("_") == -1)
                {
                    lines.push_back(line);
                }
                else
                {
                    lines.push_back(line.substr(line.find("_") + 1, line.size()));
                    continue;
                }
            }
            else
            {
                Stud.push_back(Students(lines[0], lines[1], stod(lines[2]), stoi(lines[3]), stoi(lines[4]), stoi(lines[5]), stoi(lines[6]), stoi(lines[7])));
                lines.clear();
            }
        }
        else
            break;
    }
    inp.close();
}

void Administrator::edit_info()
{
    int n;
    cout << "Какую учетную запись вы хотите изменить?\n";
    cin >> n;
    if (n <= 0 || n - 1 >= Stud.size())
        throw exception("Такой учетной записи не существует!\n");
    cin.clear();
    getchar();
    try
    {
        Stud[n - 1] = Students(1);
        inputFile();
        cout << "Запись успешно отредактирована!\n";
    }
    catch (const std::exception& error)
    {
        cout << error.what();
        cout << "Запись не была отредактирована\n";
    }
    
}

void Administrator::delete_info()
{
    cout << "Какую учетную запись студента вы хотите удалить?\n";
    int n;
    cin >> n;
    cin.clear();
    getchar();
    if (n <= 0 || n - 1 >= Stud.size())
        throw exception("Такой учетной записи не существует!\n");
    char ch;
    cout << "Вы уверены, что хотите удалить учетную запись студента: " << Stud[n - 1].get_name() << " ?\n1.Да\n2.Нажмите любую кнопку, если нет\n";
    cin >> ch;
    switch (ch)
    {
    case '1':
        Stud.erase(Stud.begin() + n - 1);
        cout << "Учетная запись успешно удалена!\n";
        inputFile();
        break;
    default:
        cout << "Вы отказались удалять учетную запись!\n";
        break;
    }
}

void Administrator::add_data()
{
    int val;
    cout << "Какое количество учетных записей студентов вы хотите создать?\n";
    cin >> val;
    if (val <= 0)
        throw exception("Введены некорректные данные!\n");
    cin.clear();
    getchar();
    for (int i = 0; i < val; i++)
    {
        try
        {
            Stud.push_back(Students(1));
        }
        catch (const std::exception& error)
        {
            cout << error.what();
            cout << "Учетная запись не сохранена!\n";
            continue;
        }
        cout << "Данные сохранены!\n";
    }
    inputFile();
}

void Administrator::inputFile()
{
    out.open(path_to_file, ios::trunc);
    out.close();
    out.open(path_to_file, ios::app);
    for (int i = 0; i < Stud.size(); i++)
    {
        out << Stud[i].get_name() << "\n" << Stud[i].get_group() << "\n" << Stud[i].get_GPA() << "\n" << "Английский язык_" << Stud[i].get_opt_disc().at("Английский язык")
            << "\n" << "Базы данных_" << Stud[i].get_opt_disc().at("Базы данных")
            << "\n" << "Математика_" << Stud[i].get_opt_disc().at("Математика")
            << "\n" << "Программирование_" << Stud[i].get_opt_disc().at("Программирование")
            << "\n" << "Физика_" << Stud[i].get_opt_disc().at("Физика") << "\n" << ";" << "\n";
    }
    out.close();
}

Administrator::Administrator()
{
    outputFile();
}

void Administrator::admin_prog()
{
    cout << "Добро пожаловать в панель управления с правами администратора!\nЧто вы хотите сделать?\n";
    bool tr = true;
    try
    {
        while (tr)
        {
            cout << "1.Посмотреть все учетные записи студентов\n2.Добавить учетную запись\n3.Удалить учетную запись\n4.Редактировать учетную запись\n5.Выход\n";
            switch (_getch())
            {
            case '1':
                system("cls");

                outToConsole();
                break;
            case '2':
                system("cls");

                add_data();
                break;
            case '4':
                system("cls");

                edit_info();
                break;
            case '3':
                system("cls");

                delete_info();
                break;
            case '5':
                tr = false;
                break;
            default:
                break;
            }
        }
    }
    catch (const std::exception& error) 
    {
        cout << error.what();
    }
    
}

void Administrator::outToConsole()
{
    cout << setw(25) << left<< "\t  ФИО студента " << setw(2) << left << " | " << " Группа студента " << setw(4) << left<< " | " << "Ср. Балл" << " | " <<
        setw(5) << left << " Англ. " << " | " << setw(5) << left << "  БД  " << " | " << setw(5) << left << " Мат. " << " | " << setw(5) << left << " Прог "
        << " | " << setw(5) << left << " Физ " << "  |\n";
    for (int i = 0; i < Stud.size(); i++)
    {
        cout << "________________________________________________________________________________________________________________\n";
        cout << setw(33) << left << Stud[i].get_name() << "|\t" <<setw(10) << left << Stud[i].get_group() << "   |     " << Stud[i].get_GPA() << "     | ";
        outputmap(Stud[i].get_opt_disc());
        cout << "\n";
    }
    cout << "________________________________________________________________________________________________________________\n";
}