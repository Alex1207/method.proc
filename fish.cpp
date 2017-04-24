#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string places[6]={"река", "озеро", "море", "океан", "пруд", "аквариум"};
void InFish(fish **Fish, ifstream &f1)
{	
	CheckFileExist(f1);
	CheckFileEnd(f1);
	fish *F = new fish;
	int Place = 6;
	f1 >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//f1 >> F->name;
	CheckInputValue(f1);
	if ((Place>=0)&&(Place<6))
		F->Place = Place;
	else
	{
		cout << "Неверные данные во входном файле(место обитания рыбок может принимать только значения от 0 до 5)!\n";
		system("pause");
		exit(1);
	}
	*Fish = F;
}
void OutFish(fish* Fish, ofstream &f2)
{
	//cout << " - это рыбка" << ", место ее обитания: " << places[Fish->Place];
	f2 << " - это рыбка" <<  ", место ее обитания: " << places[Fish->Place];
}