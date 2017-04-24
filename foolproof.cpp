#include "stdafx.h"
//#include "iostream"
//#include <fstream>
#include "foolproof.h"

void CheckFileExist(ifstream &File)
{
	if (!File)
	{
		cout << "Ошибка чтения входного файла! Возможно, файла не существует.\n";
		system("pause");
		exit(1);
	}
}
void CheckEmptyFile(ifstream &File)
{
	File.seekg (0, std::ios::end);
	int file_size = File.tellg();
	File.seekg (0, std::ios::beg);
	if (file_size == 0)	
	{
		cout << "Ошибка чтения входного файла! Файл пуст.\n";
		system("pause");
		exit(1);
	}
}
void CheckFileEnd(ifstream &File)
{
	if(File.eof())
	{
		cout << "Ошибка чтения входного файла! Неожиданный конец файла.\n";
		system("pause");
		exit(1);
	}
}
void CheckInputValue(ifstream &File)
{
	if(File.fail())
	{
		cout << "Ошибка чтения входного файла! Введены некорректные значения.\n" << endl;
		system("pause");
		exit(1);
	}
}