// ��������� �� ����� ������ � ������������ �� � ������ ���� � ����� �������� ����(����������� �����)
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
		cout << "������� ������������ ���������� ����������!!!\n������� � �������: <���_������������_�����> <���_��������_�����> <���_���������_�����>";
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