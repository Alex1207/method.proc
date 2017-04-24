#include "stdafx.h"
//#include "iostream"
//#include <fstream>
#include "foolproof.h"

void CheckFileExist(ifstream &f1)
{
	if (!f1)
	{
		cout << "������ ������ �������� �����! ��������, ����� �� ����������.\n";
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
		cout << "������ ������ �������� �����! ���� ����.\n";
		system("pause");
		exit(1);
	}
}
void CheckFileEnd(ifstream &f1)
{
	if(f1.eof())
	{
		cout << "������ ������ �������� �����! ����������� ����� �����.\n";
		system("pause");
		exit(1);
	}
}
void CheckInputValue(ifstream &f1)
{
	if(f1.fail())
	{
		cout << "������ ������ �������� �����! ������� ������������ ��������.\n" << endl;
		system("pause");
		exit(1);
	}
}