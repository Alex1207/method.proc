#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string groups[4] = {"травоядный", "хищный", "всеядный"};
void InBeast(beast **Beast, ifstream &f1)
{
	beast *B = new beast;
	int q;
	f1 >> q; 
	B->Group = q + 1;
	//f1 >> F->name;
	*Beast = B;
}
void OutBeast(beast* Beast, ofstream &f2)
{
	cout << " - это " << groups[Beast->Group - 1] << " звёр\n";
	f2 << " - это " << groups[Beast->Group - 1] << " звёр\n";
}