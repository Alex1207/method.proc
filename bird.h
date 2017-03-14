#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;
struct bird
{
	//string name;
	bool migration;
};
void InBird(bird **Bird, ifstream &f1);
void OutBird(bird *Bird, ofstream &f2);