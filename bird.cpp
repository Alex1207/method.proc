#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include "foolproof.h"
#include <fstream>

using namespace std;
void InBird(bird **Bird, ifstream &InFile)
{	
	CheckFileExist(InFile);
	CheckFileEnd(InFile);
	bird* B = new bird;
	int Migration = 0;
	InFile >> Migration;
	CheckInputValue(InFile);
	if ((Migration == 0) || (Migration == 1))	
		B->migration = Migration;
	else 	
	{
		cout << "�������� ������ �� ������� �����(�������� ���� ����� ��������� ������ �������� 1 ��� 0)!\n";
		system("pause");
		exit(1);
	}
	//f1 >> B->name;
	*Bird = B;
}
void OutBird(bird *Bird, ofstream &OutFile)
{
	//cout << " - ��� ������, ������� ";  
	OutFile << " - ��� ������, ������� "; 
	if(Bird->migration)
	{
		//cout << "���������";
		OutFile << "���������";
	}
	else 
	{
		//cout << "�� ���������";
		OutFile << "�� ���������";
	}
}