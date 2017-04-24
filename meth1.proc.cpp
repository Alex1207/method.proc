// —читывает из файла данные и переписывает их в другой файл в более читаемом виде(процедурный стиль)
//
#include "stdafx.h"
#include <Windows.h>
#include "iostream"
#include <fstream>
#include <string>
#include <clocale>
#include "container.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	int n = 10;
	setlocale(LC_ALL,"rus");
	if (argc!=3) 
	{
		cout << "¬ведено неправильное количество аргументов!!!\n¬ведите в формате: <им€_запускаемого_файла> <им€_входного_файла> <им€_выходного_файла>";
		return 0;
	}
	ifstream InFile(argv[1]);
	container Cont;
	Init(Cont);
	In(Cont, InFile);
	Sort(Cont);
	ofstream OutFile(argv[2]);
	Out(Cont, OutFile);
	OutOnlyFish(Cont, OutFile);
	Del(Cont);
	system("pause");
	return 0;
}