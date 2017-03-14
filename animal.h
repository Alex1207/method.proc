#include <string>
#include "stdafx.h"
#include "qwe.h"
#include "iostream"
#include <fstream>

using namespace std;
#ifndef __animal__ 
#define __animal__
struct animal
{
	type key;
	void* object;
	string name;
};
#endif
animal InAnimal( ifstream &f1);
void OutAnimal(animal Animal, ofstream  &f2);
int SumElementsOfString(animal Animal, int n);