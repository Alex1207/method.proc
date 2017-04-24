#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include "foolproof.h"
#include <fstream>

using namespace std;
void InBird(bird **Bird, ifstream &f1)
{	
	CheckFileExist(f1);
	CheckFileEnd(f1);
	bird* B = new bird;
	int M = 0;
	f1 >> M;
	CheckInputValue(f1);
	if ((M == 0) || (M == 1))	
		B->migration = M;
	else 	
	{
		cout << "�������� ������ �� ������� �����(�������� ���� ����� ��������� ������ �������� 1 ��� 0)!\n";
		system("pause");
		exit(1);
	}
	//f1 >> B->name;
	*Bird = B;
}
void OutBird(bird *Bird, ofstream &f2)
{
	//cout << " - ��� ������, ������� ";  
	f2 << " - ��� ������, ������� "; 
	if(Bird->migration)
	{
		//cout << "���������";
		f2 << "���������";
	}
	else 
	{
		//cout << "�� ���������";
		f2 << "�� ���������";
	}
}