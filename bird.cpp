#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;

void InBird(bird **Bird, ifstream &f1)
{
	bird* B = new bird;
	int M = 0;
	f1 >> B->migration;
	//f1 >> B->name;
	*Bird = B;
}
void OutBird(bird *Bird, ofstream &f2)
{
	cout << " - это птичка, которая ";  
	f2 << " - это птичка, которая "; 
	if(Bird->migration)
	{
		cout << "мигрирует\n";
		f2 << "мигрирует\n";
	}
	else 
	{
		cout << "не мигрирует\n";
		f2 << "не мигрирует\n";
	}
}