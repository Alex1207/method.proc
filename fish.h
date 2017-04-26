#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;

struct fish
{
	//string name;
	int Place;
	//Enumerated type would be clearer here.
};
void InFish(fish **Fish, ifstream &f1);
void OutFish(fish* Fish, ofstream &f2);