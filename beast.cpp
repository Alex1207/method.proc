#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string groups[4] = {"травоядный", "хищный", "всеядный"};
void InBeast(beast **Beast, ifstream &InFile)
{	
	CheckFileExist(InFile);	
	CheckFileEnd(InFile);
	beast *B = new beast;
	int Group = 3;
	InFile >> Group; 
	CheckInputValue(InFile);
	if ((Group>=0)&&(Group<3))
		B->group = Group;
	else 	
	{
		cout << "Неверные данные во входном файле(Группа зверя может принимать только значения от 0 до 2)!\n";
		system("pause");
		exit(1);
	}
	*Beast = B;
}
void OutBeast(beast* Beast, ofstream &OutFile)
{
	//cout << " - это " << groups[Beast->Group] << " звёр";
	OutFile << " - это " << groups[Beast->group] << " звёр";
}