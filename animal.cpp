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
animal InAnimal(ifstream &f1)
{	
	CheckFileExist(f1);	
	CheckFileEnd(f1);
	animal Animal;
	int key;
	f1 >> key;
	CheckInputValue(f1);
	if (!((key>=0)&&(key<3))) 	
	{
		cout << "Неверные данные во входном файле(Вид животного может принимать только значения от 0 до 2)!\n";// << key<<endl;
		system("pause");
		exit(1);
	}
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
	CheckFileEnd(f1);
	int age;
	f1 >> age;
	CheckInputValue(f1);
	if (age<0) 	
	{
		cout << "Неверные данные во входном файле(Возраст животного не может быть отрицательным)!\n";
		system("pause");
		exit(1);
	}
	Animal.age = age;		
	CheckFileEnd(f1);
	f1 >> Animal.name;
	return Animal;
}
void OutAnimal(animal Animal, ofstream  &f2)
{
	//cout << Animal.name;
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
	if (Animal.key == BEAST)
	{
		beast* Beast = (beast*)(Animal.object);
		OutBeast(Beast, f2);
	}
	//cout << ", возраст: " << Animal.age;
	f2 <<  ", возраст: " << Animal.age;
	//cout << ". Количество символов в имени: " << AmountSymbolsOfString(Animal) << "\n";
	f2 << ". Количество символов в имени: " << AmountSymbolsOfString(Animal) << "\n";
}
int AmountSymbolsOfString(animal Animal)
{
	string str = Animal.name;
	return str.length();
}
bool Less(animal Animal1, animal Animal2)
{
	return (AmountSymbolsOfString(Animal1) < AmountSymbolsOfString(Animal2));
}