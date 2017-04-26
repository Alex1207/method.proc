#include "stdafx.h"
#include "animal.h"
#include <string>
#include "iostream"
#include <fstream>
#include "bird.h"
#include "fish.h"
#include "beast.h"
using namespace std;
int SumElementsOfString(animal Animal, int n)
{
	string str = Animal.name;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum = (sum + (unsigned char)str[i])%n;
	}
	return sum;
}
animal InAnimal( ifstream &f1)
{
	animal Animal;
	int key;
	f1 >> key;
	//switch(key) may be more convinient for adding new case and default case.
	if (key == 1)//1-fish
	{
		fish*Fish = NULL;
		InFish(&Fish, f1);
		Animal.key = FISH;
		Animal.object = (void*)Fish;
	}
	if (key == 0)//0-bird
	{
		bird* Bird = NULL;
		InBird(&Bird, f1);
		Animal.key = BIRD;
		Animal.object = (void*)Bird;
	}
	if (key == 2)//2-beast
	{
		beast* Beast = NULL;
		InBeast(&Beast, f1);
		Animal.key = BEAST;
		Animal.object = (void*)Beast;
	}
	f1 >> Animal.age;
	f1 >> Animal.name;
	return Animal;
}
void OutAnimal(animal Animal, ofstream  &f2)
{
	cout << Animal.name;
	f2 << Animal.name;
	//switch(key)
	if (Animal.key == FISH)
	{
		fish* Fish = Fish = (fish*)(Animal.object); //fish* Fish = (fish*)(Animal.object);
		OutFish(Fish, f2);
	}
	if (Animal.key == BIRD)
	{
		bird* Bird = (bird*)(Animal.object);
		OutBird(Bird, f2);
	}
	if (Animal.key == BEAST)
	{
		beast* Beast = (beast*)(Animal.object);
		OutBeast(Beast, f2);
	}
	cout << ", возраст: " << Animal.age;
	f2 <<  ", возраст: " << Animal.age;
	cout << ". Количество символов в имени: " << AmountSymbolsOfString(Animal) << "\n";
	f2 << ". Количество символов в имени: " << AmountSymbolsOfString(Animal) << "\n";
}
int AmountSymbolsOfString(animal Animal)
{
	string str = Animal.name;
	return str.length();
}
bool Less(animal Animal1, animal Animal2)
{
	return (AmountSymbolsOfString(Animal1) > AmountSymbolsOfString(Animal2));
}