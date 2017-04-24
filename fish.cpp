#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string places[6]={"река", "озеро", "море", "океан", "пруд", "аквариум"};
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
		cout << "Неверные данные во входном файле(место обитания рыбок может принимать только значения от 0 до 5)!\n";
		system("pause");
		exit(1);
	}
	*Fish = F;
}
void OutFish(fish* Fish, ofstream &OutFile)
{
	//cout << " - это рыбка" << ", место ее обитания: " << places[Fish->Place];
	OutFile << " - это рыбка" <<  ", место ее обитания: " << places[Fish->place];
}