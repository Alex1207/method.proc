#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "qwe.h"

using namespace std;
struct beast
{
	//string name;
	int group;//млекопитающие, траво€дные, хищники, все€дные
};
void InBeast(beast **Beast, ifstream &InFile);
void OutBeast(beast *Beast, ofstream &OutFile);