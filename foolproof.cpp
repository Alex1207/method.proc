#include "stdafx.h"
//#include "iostream"
//#include <fstream>
#include "foolproof.h"

void CheckFileExist(ifstream &File)
{
	if (!File)
	{
		cout << "������ ������ �������� �����! ��������, ����� �� ����������.\n";
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
		cout << "������ ������ �������� �����! ���� ����.\n";
		system("pause");
		exit(1);
	}
}
void CheckFileEnd(ifstream &File)
{
	if(File.eof())
	{
		cout << "������ ������ �������� �����! ����������� ����� �����.\n";
		system("pause");
		exit(1);
	}
}
void CheckInputValue(ifstream &File)
{
	if(File.fail())
	{
		cout << "������ ������ �������� �����! ������� ������������ ��������.\n" << endl;
		system("pause");
		exit(1);
	}
}