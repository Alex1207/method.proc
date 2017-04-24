#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;

struct fish
{
	//string name;
	int place;
};
void InFish(fish **Fish, ifstream &InFile);
void OutFish(fish* Fish, ofstream &OutFile);