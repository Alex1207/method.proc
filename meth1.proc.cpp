// —читывает из файла данные и переписывает их в другой файл в более читаемом виде(процедурный стиль)
//+добавлен новый класс "зверь"

#include "stdafx.h"
#include <Windows.h>
#include "iostream"
#include <fstream>
#include <string>
#include <clocale>
#include "container.h"
using namespace std;

enum place {river, lake, sea, ocean, pond, aquarium};

int _tmain(int argc, _TCHAR* argv[])
{	
	int n = 10;
	setlocale(LC_ALL,"rus");
	if (argc!=3) 
	{
		cout << "¬ведено неправильное количество аргументов!!!\n¬ведите в формате: <им€_запускаемого_файла> <им€_входного файла> <им€_выходного_файла>";
		return 0;
	}
	ifstream f1(argv[1]);
	container mas;
	Init(mas);
	In(mas, f1);
	
	ofstream f2(argv[2]);
	Out(mas, f2);
	Del(mas);
	system("pause");
	return 0;
}

