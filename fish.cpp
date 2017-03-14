#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string places[6]={"река", "озеро", "море", "океан", "пруд", "аквариум"};
void InFish(fish **Fish, ifstream &f1)
{
	fish *F = new fish;
	f1 >> F->Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//f1 >> F->name;
	*Fish = F;
}
void OutFish(fish* Fish, ofstream &f2)
{
	cout << " - это рыбка" << ", место ее обитания: " << places[Fish->Place] << "\n";
	f2 << " - это рыбка" <<  ", место ее обитания: " << places[Fish->Place] << "\n";
}