#include "stdafx.h"
#include "animal.h"
#include <string>
#include "iostream"
#include <fstream>
#include "bird.h"
#include "fish.h"

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
	f1 >> Animal.name;
	return Animal;
}
void OutAnimal(animal Animal, ofstream  &f2)
{
	cout << Animal.name;
	f2 << Animal.name;
	if (Animal.key == FISH)
	{
		fish* Fish = Fish = (fish*)(Animal.object);
		OutFish(Fish, f2);
	}
	if (Animal.key == BIRD)
	{
		bird* Bird = (bird*)(Animal.object);
		OutBird(Bird, f2);
	}
}