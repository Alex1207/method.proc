#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string groups[4] = {"травоядный", "хищный", "всеядный"};
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
		cout << "Неверные данные во входном файле(Группа зверя может принимать только значения от 0 до 2)!\n";
		system("pause");
		exit(1);
	}
	*Beast = B;
}
void OutBeast(beast* Beast, ofstream &f2)
{
	//cout << " - это " << groups[Beast->Group] << " звёр";
	f2 << " - это " << groups[Beast->Group] << " звёр";
}