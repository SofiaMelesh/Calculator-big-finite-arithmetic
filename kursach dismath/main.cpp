#include <iostream>
#include "Arithmetic.h"
#include "func.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Start();
	Arithmetic a1;
    while (true) {
        Menu(); // Вывод меню
        int operation = OperationsMenu(); // Получение выбранной операции

        if (operation == 0) { // Если введён 0, завершаем программу
            Bye(); // Прощальное сообщение
            break; // Выход из цикла
        }

        a1.ChooseOperationsMenu(operation); // Выполняем операцию
    }

}

