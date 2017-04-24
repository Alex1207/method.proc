#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string groups[4] = {"����������", "������", "��������"};
void InBeast(beast **Beast, ifstream &f1)
{	
	CheckFileExist(f1);	
	CheckFileEnd(f1);
	beast *B = new beast;
	int G = 3;
	f1 >> G; 
	CheckInputValue(f1);
	if ((G>=0)&&(G<3))
		B->Group = G;
	else 	
	{
		cout << "�������� ������ �� ������� �����(������ ����� ����� ��������� ������ �������� �� 0 �� 2)!\n";
		system("pause");
		exit(1);
	}
	*Beast = B;
}
void OutBeast(beast* Beast, ofstream &f2)
{
	//cout << " - ��� " << groups[Beast->Group] << " ���";
	f2 << " - ��� " << groups[Beast->Group] << " ���";
}