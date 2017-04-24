#include "stdafx.h"
//#include "iostream"
//#include <fstream>
#include "foolproof.h"

void CheckFileExist(ifstream &f1)
{
	if (!f1)
	{
		cout << "Ошибка чтения входного файла! Возможно, файла не существует.\n";
		system("pause");
		exit(1);
	}
}
void CheckEmptyFile(ifstream &f1)
{
	f1.seekg (0, std::ios::end);
	int file_size = f1.tellg();
	f1.seekg (0, std::ios::beg);
	if (file_size == 0)	
	{
		cout << "Ошибка чтения входного файла! Файл пуст.\n";
		system("pause");
		exit(1);
	}
}
void CheckFileEnd(ifstream &f1)
{
	if(f1.eof())
	{
		cout << "Ошибка чтения входного файла! Неожиданный конец файла.\n";
		system("pause");
		exit(1);
	}
}
void CheckInputValue(ifstream &f1)
{
	if(f1.fail())
	{
		cout << "Ошибка чтения входного файла! Введены некорректные значения.\n" << endl;
		system("pause");
		exit(1);
	}
}