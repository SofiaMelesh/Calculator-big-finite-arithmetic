#include "func.h"
#include <iostream>

using namespace std;

void Start() {
    cout << endl << "**************************************************************"<<endl
               <<   "* ����� ���������� � ����������� ������� �������� ���������� *" << endl << 
                    "**************************************************************" << endl << endl  <<
        "������� 33:  a->b->e->h->c->d->g->f" << endl <<
        "             a - ����������� ������� �� ��������" << endl <<
        "             b - ����������� ������� �� ���������";

};

string Input1() {
    cout << endl << "************************" << endl
        << "* ������� ������ ����� *" << endl
        << "************************" << endl << endl;

    string input;
    while (true) {
        cin >> input;
        if ((input.size() > 8 && input[0] != '-') || (input.size() > 9 && input[0] == '-' )) {
            cout << "������ �����! ����� ������ �������� �� 8 �������� � ������! "<<endl;
            continue;
        }
        bool valid = true;
        for (size_t i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (string("abehcdgf").find(c) == string::npos) {
                if (c == '-' && i == 0 && input.size() > 1) continue;
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "������ �����! ��������� ������ ������� -, a, b, e, h, c, d, g, f � - ����� ���� ������ ������! ��������� ����! " << endl;
            continue;
        }
        break;
    }

    return input;
}

string Input2() {
    cout << endl << "************************" << endl
        << "* ������� ������ ����� *" << endl
        << "************************" << endl << endl;

    string input;
    while (true) {
        cin >> input;
        if ((input.size() > 8 && input[0] != '-') || (input.size() > 9 && input[0] == '-')) {
            cout << "������ �����! ����� ������ �������� �� 8 �������� � ������! " << endl;
            continue;
        }
        bool valid = true;
        for (size_t i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (string("abehcdgf").find(c) == string::npos) {
                if (c == '-' && i == 0 && input.size() > 1) continue;
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "������ �����! ��������� ������ ������� -, a, b, e, h, c, d, g, f � - ����� ���� ������ ������! ��������� ����! " << endl;
            continue;
        }
        break;
    }

    return input;
}


void Menu() {
    cout << endl << endl << endl << "***************************" << endl
        << "* ���� ��������� �������� *" << endl <<
           "***************************";
}

int OperationsMenu() { 
    cout << endl << endl<< "* ���� *" << endl << endl;
    cout << "1) ��������" << endl
        << "2) ���������" << endl
        << "3) ���������" << endl
        << "4) �������" << endl
        << "                     ��� ������ �� ���������� ������� 0"<<endl<<endl;
    cout << "������� ����� ������ �������� (�� 1 �� 4 ������������)" << endl << endl;

    int op;
    bool validInput = false;
    while (!validInput) {
        cout << "����: ";
        cin >> op;
        if (cin.fail() || op < 0 || op > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����! ������� ����� �� 0 �� 4 ������������!" << endl;
        }
        else return op;
    }
}
void Bye() {
    cout << endl << "********************" << endl
        << "* �� ����� ������! *" << endl <<
        "********************" << endl << endl;
}
