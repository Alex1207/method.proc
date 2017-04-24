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
	int age;
	string name;
};
#endif
void OutAnimal(animal Animal, ofstream  &OutFile);
int AmountSymbolsOfString(animal Animal);
bool Less(animal Animal1, animal Animal2);