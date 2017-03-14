#include "stdafx.h"
#include "animal.h"
#include "iostream"
#include <fstream>

using namespace std;
struct node//узел
{
	animal Animal;
	node* next;
};
struct container
{
	int kol;
	int n;
	node** mas;
};
void Init(container &c);
void Del(container &c);
void In(container &c, ifstream & f1);
void Out(container c, ofstream & f2);