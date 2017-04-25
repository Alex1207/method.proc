#include "stdafx.h"
#include "animal.h"
#include "iostream"
#include <fstream>

using namespace std;
struct node//узел
{
	animal nAnimal;
	node* next;
};
struct container
{
	int kol;
	int n;
	node** mas;
};
void Init(container &Cont);
void Del(container &Cont);
void In(container &Cont, ifstream &InFile);
void Out(container Cont, ofstream &OutFile);
void Sort(container &Cont);
void OutOnlyFish(container Cont, ofstream &OutFile);
int SumElementsOfString(animal Animal, int N);
void MultiMethod(container Cont, ofstream &OutFile);