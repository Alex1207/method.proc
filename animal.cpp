#include "stdafx.h"
#include <string>
#include "iostream"
#include <fstream>
#include "bird.h"
#include "fish.h"
#include "beast.h"
#include "foolproof.h"
#include "animal.h"

using namespace std;
animal InAnimal(ifstream &InFile)
{	
	CheckFileExist(InFile);	
	CheckFileEnd(InFile);
	animal Animal;
	int Key;
	InFile >> Key;
	CheckInputValue(InFile);
	if (!((Key>=0)&&(Key<3))) 	
	{
		cout << "Неверные данные во входном файле(Вид животного может принимать только значения от 0 до 2)!\n";// << key<<endl;
		system("pause");
		exit(1);
	}
	if (Key == 1)//1-fish
	{
		fish*Fish = NULL;
		InFish(&Fish, InFile);
		Animal.key = FISH;
		Animal.object = (void*)Fish;
	}
	if (Key == 0)//0-bird
	{
		bird* Bird = NULL;
		InBird(&Bird, InFile);
		Animal.key = BIRD;
		Animal.object = (void*)Bird;
	}
	if (Key == 2)//2-beast
	{
		beast* Beast = NULL;
		InBeast(&Beast, InFile);
		Animal.key = BEAST;
		Animal.object = (void*)Beast;
	}	
	CheckFileEnd(InFile);
	int Age;
	InFile >> Age;
	CheckInputValue(InFile);
	if (Age<0) 	
	{
		cout << "Неверные данные во входном файле(Возраст животного не может быть отрицательным)!\n";
		system("pause");
		exit(1);
	}
	Animal.age = Age;		
	CheckFileEnd(InFile);
	InFile >> Animal.name;
	return Animal;
}
void OutAnimal(animal Animal, ofstream  &OutFile)
{
	//cout << Animal.name;
	OutFile << Animal.name;
	if (Animal.key == FISH)
	{
		fish* Fish = Fish = (fish*)(Animal.object);
		OutFish(Fish, OutFile);
	}
	if (Animal.key == BIRD)
	{
		bird* Bird = (bird*)(Animal.object);
		OutBird(Bird, OutFile);
	}
	if (Animal.key == BEAST)
	{
		beast* Beast = (beast*)(Animal.object);
		OutBeast(Beast, OutFile);
	}
	//cout << ", возраст: " << Animal.age;
	OutFile <<  ", возраст: " << Animal.age;
	//cout << ". Количество символов в имени: " << AmountSymbolsOfString(Animal) << "\n";
	OutFile << ". Количество символов в имени: " << AmountSymbolsOfString(Animal) << "\n";
}
int AmountSymbolsOfString(animal Animal)
{
	string Str = Animal.name;
	return Str.length();
}
bool Less(animal Animal1, animal Animal2)
{
	return (AmountSymbolsOfString(Animal1) < AmountSymbolsOfString(Animal2));
}