#include "func.h"
#include <iostream>

using namespace std;

void Start() {
    cout << endl << "**************************************************************"<<endl
               <<   "* ÄÎÁÐÎ ÏÎÆÀËÎÂÀÒÜ Â ÊÀËÜÊÓËßÒÎÐ ÁÎËÜØÎÉ ÊÎÍÅ×ÍÎÉ ÀÐÈÔÌÅÒÈÊÈ *" << endl << 
                    "**************************************************************" << endl << endl  <<
        "Âàðèàíò 33:  a->b->e->h->c->d->g->f" << endl <<
        "             a - íåéòðàëüíûé ýëåìåíò ïî ñëîæåíèþ" << endl <<
        "             b - íåéòðàëüíûé ýëåìåíò ïî óìíîæåíèþ";

};

string Input1() {
    cout << endl << "************************" << endl
        << "* ÂÂÅÄÈÒÅ ÏÅÐÂÎÅ ×ÈÑËÎ *" << endl
        << "************************" << endl << endl;

    string input;
    while (true) {
        cin >> input;
        if ((input.size() > 8 && input[0] != '-') || (input.size() > 9 && input[0] == '-' )) {
            cout << "Îøèáêà ââîäà! ×èñëî äîëæíî ñîñòîÿòü èç 8 ðàçðÿäîâ è ìåíüøå! "<<endl;
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
            cout << "Îøèáêà ââîäà! Äîïóñòèìû òîëüêî ñèìâîëû -, a, b, e, h, c, d, g, f è - ìîæåò áûòü òîëüêî ïåðâûì! Ïîâòîðèòå ââîä! " << endl;
            continue;
        }
        break;
    }

    return input;
}

string Input2() {
    cout << endl << "************************" << endl
        << "* ÂÂÅÄÈÒÅ ÂÒÎÐÎÅ ×ÈÑËÎ *" << endl
        << "************************" << endl << endl;

    string input;
    while (true) {
        cin >> input;
        if ((input.size() > 8 && input[0] != '-') || (input.size() > 9 && input[0] == '-')) {
            cout << "Îøèáêà ââîäà! ×èñëî äîëæíî ñîñòîÿòü èç 8 ðàçðÿäîâ è ìåíüøå! " << endl;
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
            cout << "Îøèáêà ââîäà! Äîïóñòèìû òîëüêî ñèìâîëû -, a, b, e, h, c, d, g, f è - ìîæåò áûòü òîëüêî ïåðâûì! Ïîâòîðèòå ââîä! " << endl;
            continue;
        }
        break;
    }

    return input;
}


void Menu() {
    cout << endl << endl << endl << "***************************" << endl
        << "* ÌÅÍÞ ÄÎÑÒÓÏÍÛÕ ÎÏÅÐÀÖÈÉ *" << endl <<
           "***************************";
}

int OperationsMenu() { 
    cout << endl << endl<< "* ÌÅÍÞ *" << endl << endl;
    cout << "1) Ñëîæåíèå" << endl
        << "2) Âû÷èòàíèå" << endl
        << "3) Óìíîæåíèå" << endl
        << "4) Äåëåíèå" << endl
        << "                     ÄËß ÂÛÕÎÄÀ ÈÇ ÏÐÈËÎÆÅÍÈß ÂÂÅÄÈÒÅ 0"<<endl<<endl;
    cout << "Ââåäèòå íîìåð íóæíîé îïåðàöèè (îò 1 äî 4 âêëþ÷èòåëüíî)" << endl << endl;

    int op;
    bool validInput = false;
    while (!validInput) {
        cout << "Ââîä: ";
        cin >> op;
        if (cin.fail() || op < 0 || op > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Îøèáêà ââîäà! Ââåäèòå ÷èñëî îò 0 äî 4 âêëþ÷èòåëüíî!" << endl;
        }
        else return op;
    }
}
void Bye() {
    cout << endl << "********************" << endl
        << "* ÄÎ ÍÎÂÛÕ ÂÑÒÐÅ×! *" << endl <<
        "********************" << endl << endl;
}
