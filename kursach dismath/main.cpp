#include <iostream>
#include "Arithmetic.h"
#include "func.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Start();
	Arithmetic a1;
    while (true) {
        Menu(); // ����� ����
        int operation = OperationsMenu(); // ��������� ��������� ��������

        if (operation == 0) { // ���� ����� 0, ��������� ���������
            Bye(); // ���������� ���������
            break; // ����� �� �����
        }

        a1.ChooseOperationsMenu(operation); // ��������� ��������
    }

}

