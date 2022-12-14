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
    cout << "����� ������� ������ �� ������ ��������?\n";
    cin >> n;
    if (n <= 0 || n - 1 >= Stud.size())
        throw exception("����� ������� ������ �� ����������!\n");
    cin.clear();
    getchar();
    try
    {
        Stud[n - 1] = Students(1);
        inputFile();
        cout << "������ ������� ���������������!\n";
    }
    catch (const std::exception& error)
    {
        cout << error.what();
        cout << "������ �� ���� ���������������\n";
    }
    
}

void Administrator::delete_info()
{
    cout << "����� ������� ������ �������� �� ������ �������?\n";
    int n;
    cin >> n;
    cin.clear();
    getchar();
    if (n <= 0 || n - 1 >= Stud.size())
        throw exception("����� ������� ������ �� ����������!\n");
    char ch;
    cout << "�� �������, ��� ������ ������� ������� ������ ��������: " << Stud[n - 1].get_name() << " ?\n1.��\n2.������� ����� ������, ���� ���\n";
    cin >> ch;
    switch (ch)
    {
    case '1':
        Stud.erase(Stud.begin() + n - 1);
        cout << "������� ������ ������� �������!\n";
        inputFile();
        break;
    default:
        cout << "�� ���������� ������� ������� ������!\n";
        break;
    }
}

void Administrator::add_data()
{
    int val;
    cout << "����� ���������� ������� ������� ��������� �� ������ �������?\n";
    cin >> val;
    if (val <= 0)
        throw exception("������� ������������ ������!\n");
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
            cout << "������� ������ �� ���������!\n";
            continue;
        }
        cout << "������ ���������!\n";
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
        out << Stud[i].get_name() << "\n" << Stud[i].get_group() << "\n" << Stud[i].get_GPA() << "\n" << "���������� ����_" << Stud[i].get_opt_disc().at("���������� ����")
            << "\n" << "���� ������_" << Stud[i].get_opt_disc().at("���� ������")
            << "\n" << "����������_" << Stud[i].get_opt_disc().at("����������")
            << "\n" << "����������������_" << Stud[i].get_opt_disc().at("����������������")
            << "\n" << "������_" << Stud[i].get_opt_disc().at("������") << "\n" << ";" << "\n";
    }
    out.close();
}

Administrator::Administrator()
{
    outputFile();
}

void Administrator::admin_prog()
{
    cout << "����� ���������� � ������ ���������� � ������� ��������������!\n��� �� ������ �������?\n";
    bool tr = true;
    try
    {
        while (tr)
        {
            cout << "1.���������� ��� ������� ������ ���������\n2.�������� ������� ������\n3.������� ������� ������\n4.������������� ������� ������\n5.�����\n";
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
    cout << setw(25) << left<< "\t  ��� �������� " << setw(2) << left << " | " << " ������ �������� " << setw(4) << left<< " | " << "��. ����" << " | " <<
        setw(5) << left << " ����. " << " | " << setw(5) << left << "  ��  " << " | " << setw(5) << left << " ���. " << " | " << setw(5) << left << " ���� "
        << " | " << setw(5) << left << " ��� " << "  |\n";
    for (int i = 0; i < Stud.size(); i++)
    {
        cout << "________________________________________________________________________________________________________________\n";
        cout << setw(33) << left << Stud[i].get_name() << "|\t" <<setw(10) << left << Stud[i].get_group() << "   |     " << Stud[i].get_GPA() << "     | ";
        outputmap(Stud[i].get_opt_disc());
        cout << "\n";
    }
    cout << "________________________________________________________________________________________________________________\n";
}