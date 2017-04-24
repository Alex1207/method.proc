#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string places[6]={"����", "�����", "����", "�����", "����", "��������"};
void InFish(fish **Fish, ifstream &InFile)
{	
	CheckFileExist(InFile);
	CheckFileEnd(InFile);
	fish *F = new fish;
	int Place = 6;
	InFile >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//f1 >> F->name;
	CheckInputValue(InFile);
	if ((Place>=0)&&(Place<6))
		F->place = Place;
	else
	{
		cout << "�������� ������ �� ������� �����(����� �������� ����� ����� ��������� ������ �������� �� 0 �� 5)!\n";
		system("pause");
		exit(1);
	}
	*Fish = F;
}
void OutFish(fish* Fish, ofstream &OutFile)
{
	//cout << " - ��� �����" << ", ����� �� ��������: " << places[Fish->Place];
	OutFile << " - ��� �����" <<  ", ����� �� ��������: " << places[Fish->place];
}