#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string groups[4] = {"����������", "������", "��������"};
void InBeast(beast **Beast, ifstream &f1)
{
	beast *B = new beast;
	int q;
	f1 >> q; 
	B->Group = q;
	//f1 >> F->name;
	*Beast = B;
}
void OutBeast(beast* Beast, ofstream &f2)
{
	//cout << " - ��� " << groups[Beast->Group] << " ���";
	f2 << " - ��� " << groups[Beast->Group] << " ���";
}