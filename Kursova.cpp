#include <iostream>
#include <string>
#include <string>
#include <string.h>
#include <vector>
#include<fstream>
#include "dieslovo.h"
#include "prykmetnyk.h"
#include "chyslivnyk.h"
#include "imennyk.h"

using namespace std;



int main()
{

    cout<<"введіть назву файлу, якщо бажаєте вивести з нього(або 'c'): ";
    string f;
    cin>>f;
    f="file.txt";
    prykmetnyk w=prykmetnyk(f);
    cout<<"введіть назву файлу, якщо бажаєте записати в файл(або 'c'): ";
    cin>>f;
    f="file1.txt";
    w.output(f);
    string a=w.slog(w.slovocel());
    cout<<a;
    return 0;
}







/*
реализовать проверку- определение гласной
число,падеж, род - ок+кор
род+суф
пример
кот кошка


пример водохранилище 2 кор
рус == укр
проверка: сведение в нижний
апостроф дефис?
тип prykmetnyk pryimenyk imennyk chyslivnyk dieslovo
хранение тип род число ...
вывод на консоль тип: ....


проверка!

простейшее слово: перекотиполе слово
проверка 1 и 2 най-яс-кра-ві-ше
ь дз дж '
учесть также о-сінь по-дві-р'я
есть, не оговорено

ввод
циклы p r s


*/
