#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include "foolproof.h"
#include <fstream>

using namespace std;
void InBird(bird **Bird, ifstream &InFile)
{	
	CheckFileExist(InFile);
	CheckFileEnd(InFile);
	bird* B = new bird;
	int Migration = 0;
	InFile >> Migration;
	CheckInputValue(InFile);
	if ((Migration == 0) || (Migration == 1))	
		B->migration = Migration;
	else 	
	{
		cout << "Неверные данные во входном файле(миграция птиц может принимать только значения 1 или 0)!\n";
		system("pause");
		exit(1);
	}
	//f1 >> B->name;
	*Bird = B;
}
void OutBird(bird *Bird, ofstream &OutFile)
{
	//cout << " - это птичка, которая ";  
	OutFile << " - это птичка, которая "; 
	if(Bird->migration)
	{
		//cout << "мигрирует";
		OutFile << "мигрирует";
	}
	else 
	{
		//cout << "не мигрирует";
		OutFile << "не мигрирует";
	}
}