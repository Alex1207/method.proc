#include "stdafx.h"
#include "gtest/gtest.h"
#include "animal.h"
#include <string>
#include "iostream"
#include <fstream>
#include "bird.h"
#include "beast.h"
#include "fish.h"
#include "container.h"
#include <Windows.h>
#include <clocale>

using namespace std;
//const n = 10
bool FileCompare(ifstream &f1, ifstream &f2)
{
	string s1;
	string s2;
	bool flag = true;
	while ((!f1.eof())||(!f2.eof())) 
	{ 
		getline(f1,s1); 
		getline(f2,s2); 
		if (s1 != s2)
			return false;
	}
	return true;
}
class CBirdTest : public ::testing::Test 
{
};
TEST_F(CBirdTest, CheckBirdIn) //
{
	ifstream f1("InBird.txt");
	bird *Bird;
	InBird(&Bird, f1);
	f1.close();
	ASSERT_TRUE(Bird->migration == 1) << "Bird input test was failed!!";
}
TEST_F(CBirdTest, CheckBirdOut) //
{
	bird *Bird;
	Bird = new bird;
	Bird->migration = 1;
	ofstream f2("aOutBird.txt");
	OutBird(Bird, f2);
	f2.close();
	ifstream actual("aOutBird.txt");
	ifstream expect("eOutBird.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Bird output test was failed!!";
	actual.close();
	expect.close();
}

class CFishTest : public ::testing::Test 
{
};
TEST_F(CFishTest, CheckFishIn) //
{	
	ifstream f1("InFish.txt");
	fish *Fish;
	InFish(&Fish, f1);
	f1.close();
	ASSERT_TRUE(Fish->Place == 2) << "Fish input test was failed!!";
}
TEST_F(CFishTest, CheckFishOut) //
{
	fish *Fish;
	Fish = new fish;
	Fish->Place = 1;
	ofstream f2("aOutFish.txt");
	OutFish(Fish, f2);
	f2.close();
	ifstream actual("aOutFish.txt");
	ifstream expect("eOutFish.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Fish output test was failed!!";
	actual.close();
	expect.close();
}

class CBeastTest : public ::testing::Test 
{
};
TEST_F(CBeastTest, CheckBeastIn) //
{	
	ifstream f1("InBeast.txt");
	beast *Beast;
	InBeast(&Beast, f1);
	f1.close();
	ASSERT_TRUE(Beast->Group == 3) << "Beast input test was failed!!";
}
TEST_F(CBeastTest, CheckBeastOut) //
{
	beast *Beast;
	Beast = new beast;
	Beast->Group = 1;
	ofstream f2("aOutBeast.txt");
	OutBeast(Beast, f2);
	f2.close();
	ifstream actual("aOutBeast.txt");
	ifstream expect("eOutBeast.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Beast output test was failed!!";
	actual.close();
	expect.close();
}

bool AnimalCompare(animal a1, animal a2)
{
	if (a1.key == BIRD)
		return((a1.key == a2.key)&&(a1.age == a2.age)&&(a1.name == a2.name)&&(((bird*)a1.object)->migration == ((bird*)a2.object)->migration));
	if (a1.key == FISH)
		return((a1.key == a2.key)&&(a1.age == a2.age)&&(a1.name == a2.name)&&(((fish*)a1.object)->Place == ((fish*)a2.object)->Place));
	if (a1.key == BEAST)
		return((a1.key == a2.key)&&(a1.age == a2.age)&&(a1.name == a2.name)&&(((beast*)a1.object)->Group == ((beast*)a2.object)->Group));
}

void NewInAnimal(animal &Animal, type key, int age, string name, int param)
{
	if (key == BIRD)
	{		
		bird *Bird;
		Bird = new bird; Bird->migration = param;
		Animal.key = BIRD; 
		Animal.age = age; 
		Animal.name = name; 
		Animal.object = (void*)Bird;
	}
	if (key == FISH)
	{		
		fish *Fish;
		Fish = new fish; Fish->Place = param;
		Animal.key = FISH; 
		Animal.age = age; 
		Animal.name = name; 
		Animal.object = (void*)Fish;
	}
	if (key == BEAST)
	{		
		beast *Beast;
		Beast = new beast; Beast->Group = param;
		Animal.key = BEAST; 
		Animal.age = age; 
		Animal.name = name; 
		Animal.object = (void*)Beast;
	}
}
class CAnimalTest : public ::testing::Test 
{
};
TEST_F(CAnimalTest, CheckAnimalIn) //
{
	animal actual;
	animal expect;
	ifstream f1("InAnimalBird.txt");
	InAnimal(actual, f1);
	f1.close();
	NewInAnimal(expect, BIRD, 5, "клест", 1);
	EXPECT_TRUE(AnimalCompare(actual, expect)) << "Animal(Bird) input test was failed!!";

	ifstream f2("InAnimalFish.txt");
	InAnimal(actual, f2);
	f2.close();
	NewInAnimal(expect, FISH, 13, "лещ", 3);
	EXPECT_TRUE(AnimalCompare(actual, expect)) << "Animal(Fish) input test was failed!!";

	ifstream f3("InAnimalBeast.txt");
	InAnimal(actual, f3);
	f3.close();
	NewInAnimal(expect, BEAST, 21, "человек", 2);
	EXPECT_TRUE(AnimalCompare(actual, expect)) << "Animal(Beast) input test was failed!!";
}
TEST_F(CAnimalTest, CheckAnimalOut) //
{
	animal Animal;
	NewInAnimal(Animal, BIRD, 5, "клест", 1);
	ofstream f1("aOutAnimalBird.txt");
	OutAnimal(Animal, f1);
	f1.close();
	ifstream actual1("aOutAnimalBird.txt");
	ifstream expect1("eOutAnimalBird.txt");
	EXPECT_TRUE(FileCompare(actual1, expect1)) << "Animal(Bird) output test was failed!!";
	actual1.close();
	expect1.close();

	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	ofstream f2("aOutAnimalFish.txt");
	OutAnimal(Animal, f2);
	f2.close();
	ifstream actual2("aOutAnimalBird.txt");
	ifstream expect2("eOutAnimalBird.txt");
	EXPECT_TRUE(FileCompare(actual2, expect2)) << "Animal(Fish) output test was failed!!";
	actual2.close();
	expect2.close();

	NewInAnimal(Animal, BEAST, 21, "человек", 2);
	ofstream f3("aOutAnimalBeast.txt");
	OutAnimal(Animal, f3);
	f3.close();
	ifstream actual3("aOutAnimalBeast.txt");
	ifstream expect3("eOutAnimalBeast.txt");
	EXPECT_TRUE(FileCompare(actual3, expect3)) << "Animal(Beast) output test was failed!!";
}
TEST_F(CAnimalTest, CheckAnimalAmountSymbolsOfString) //
{
	animal Animal;
	Animal.name = "";
	EXPECT_TRUE(AmountSymbolsOfString(Animal) == 0) << "Animal amount symbols of string (empty string) test was failed!!";
	Animal.name = "лосось";
	EXPECT_TRUE(AmountSymbolsOfString(Animal) == 6) << "Animal amount symbols of string test was failed!!";
}
TEST_F(CAnimalTest, CheckAnimalLess) //
{
	animal Animal1;
	Animal1.name = "лось";
	EXPECT_TRUE(Less(Animal1,Animal1) == false) << "Animal compare(a=b) test was failed!!";	
	animal Animal2;
	Animal2.name = "лебедь";
	EXPECT_TRUE(Less(Animal1,Animal2) == true) << "Animal compare(a<b) test was failed!!";
	EXPECT_TRUE(Less(Animal2,Animal1) == false) << "Animal compare(a>b) test was failed!!";
}

class CContainerTest : public ::testing::Test 
{
};
void EmptyContainer(container &c)
{
	c.kol = 0;
	c.n = 10;
	c.mas = new node*[c.n];
	for (int i = 0; i < c.n; i++)
		c.mas[i] = NULL;
}
bool ContainerCompare(container c1, container c2)
{
	if (c1.n != c2.n)
	{
		cout << "N\n\n\n";
		return false;
	}
	if (c1.kol != c2.kol)
	{
		cout << "KOL\n\n\n";
		return false;
	}
	for (int i = 0; i < c1.n; i++)
	{
		if ((c1.mas[i] != NULL)^(c2.mas[i] != NULL))
		{
			cout << "NULL\n"<<i<<"\n\n";
			return false;
		}
		if ((c1.mas[i] != NULL)||(c2.mas[i] != NULL))
		{
			node* vn1 = c1.mas[i];
			node* vn2 = c2.mas[i];
			while (vn1 || vn2)
			{
				if ((vn1 != NULL)^(vn2 != NULL))
					return false;
				if (!(AnimalCompare(vn1->Animal, vn2->Animal)))
				{
					cout << "ANI\n\n\n";
					return false;
				}
				vn1 = vn1->next;
				vn2 = vn2->next;
			}
		}
	}
	return true;
}
void ExpectContainer1(container &c)
{
	c.kol = 10;
	animal Animal;
	node* vn;

	c.mas[0] = new node;
	NewInAnimal(Animal, BIRD, 2, "голубь", 0);	
	c.mas[0]->Animal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, FISH, 3, "осетр", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "кукушка", 0); vn->Animal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	NewInAnimal(Animal, BIRD, 5, "клест", 1);
	c.mas[1]->Animal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 1, "слон", 0); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 9, "тигр", 1); vn->Animal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	c.mas[3]->Animal = Animal; c.mas[3]->next = NULL;

	//c.mas[4] = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	NewInAnimal(Animal, BEAST, 21, "человек", 2);
	c.mas[8]->Animal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 4, "язь", 3); vn->Animal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 6, "форель", 1); vn->Animal = Animal; c.mas[8] = vn;

	//c.mas[9] = NULL;
}
void ExpectContainer2(container &c)
{
	c.kol = 15;
	animal Animal;
	node* vn;

	c.mas[0] = new node;
	NewInAnimal(Animal, BIRD, 2, "голубь", 0);	
	c.mas[0]->Animal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, FISH, 3, "осетр", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "кукушка", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "журавль", 1); vn->Animal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	NewInAnimal(Animal, BIRD, 5, "клест", 1);
	c.mas[1]->Animal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 1, "слон", 0); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 9, "тигр", 1); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 8, "змея", 1); vn->Animal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	c.mas[3]->Animal = Animal; c.mas[3]->next = NULL;

	c.mas[4] = new node;
	NewInAnimal(Animal, BEAST, 5, "кот", 1);
	c.mas[4]->Animal = Animal; c.mas[4]->next = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	NewInAnimal(Animal, BEAST, 21, "человек", 2);
	c.mas[8]->Animal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 4, "язь", 3); vn->Animal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 6, "форель", 1); vn->Animal = Animal; c.mas[8] = vn;

	c.mas[9] = new node;
	NewInAnimal(Animal, FISH, 10, "пескарь", 4);
	c.mas[9]->Animal = Animal; c.mas[9]->next = NULL;
	vn = new node;
	vn->next = c.mas[9]; NewInAnimal(Animal, BIRD, 2, "дятел", 1); vn->Animal = Animal; c.mas[9] = vn;
}
void ExpectContainer1Sort(container &c)
{
	c.kol = 10;
	animal Animal;
	node* vn;

	c.mas[0] = new node;
	 NewInAnimal(Animal, FISH, 3, "осетр", 0);	
	c.mas[0]->Animal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 2, "голубь", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "кукушка", 0); vn->Animal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	NewInAnimal(Animal, BEAST, 1, "слон", 0);
	c.mas[1]->Animal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 9, "тигр", 1); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1];NewInAnimal(Animal, BIRD, 5, "клест", 1); vn->Animal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	c.mas[3]->Animal = Animal; c.mas[3]->next = NULL;

	//c.mas[4] = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	NewInAnimal(Animal, FISH, 4, "язь", 3);
	c.mas[8]->Animal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 6, "форель", 1); vn->Animal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, BEAST, 21, "человек", 2); vn->Animal = Animal; c.mas[8] = vn;

	//c.mas[9] = NULL;
}
void ExpectContainer2Sort(container &c)
{
	c.kol = 15;
	animal Animal;
	node* vn;

	c.mas[0] = new node;
	NewInAnimal(Animal, FISH, 3, "осетр", 0);	
	c.mas[0]->Animal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 2, "голубь", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "кукушка", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "журавль", 1); vn->Animal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	NewInAnimal(Animal, BEAST, 1, "слон", 0);
	c.mas[1]->Animal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 9, "тигр", 1); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 8, "змея", 1); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BIRD, 5, "клест", 1); vn->Animal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	c.mas[3]->Animal = Animal; c.mas[3]->next = NULL;

	c.mas[4] = new node;
	NewInAnimal(Animal, BEAST, 5, "кот", 1);
	c.mas[4]->Animal = Animal; c.mas[4]->next = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	NewInAnimal(Animal, FISH, 4, "язь", 3);
	c.mas[8]->Animal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 6, "форель", 1); vn->Animal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, BEAST, 21, "человек", 2); vn->Animal = Animal; c.mas[8] = vn;

	c.mas[9] = new node;
	NewInAnimal(Animal, BIRD, 2, "дятел", 1);
	c.mas[9]->Animal = Animal; c.mas[9]->next = NULL;
	vn = new node;
	vn->next = c.mas[9]; NewInAnimal(Animal, FISH, 10, "пескарь", 4); vn->Animal = Animal; c.mas[9] = vn;
}
void ExpectContainer2Desort(container &c)
{
	c.kol = 15;
	animal Animal;
	node* vn;

	c.mas[0] = new node;
	NewInAnimal(Animal, BIRD, 7, "кукушка", 0);	
	c.mas[0]->Animal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 7, "журавль", 1); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, BIRD, 2, "голубь", 0); vn->Animal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; NewInAnimal(Animal, FISH, 3, "осетр", 0); vn->Animal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	NewInAnimal(Animal, BIRD, 5, "клест", 1);
	c.mas[1]->Animal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 1, "слон", 0); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 9, "тигр", 1); vn->Animal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; NewInAnimal(Animal, BEAST, 8, "змея", 1); vn->Animal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	c.mas[3]->Animal = Animal; c.mas[3]->next = NULL;

	c.mas[4] = new node;
	NewInAnimal(Animal, BEAST, 5, "кот", 1);
	c.mas[4]->Animal = Animal; c.mas[4]->next = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	NewInAnimal(Animal, BEAST, 21, "человек", 2);
	c.mas[8]->Animal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 6, "форель", 1); vn->Animal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; NewInAnimal(Animal, FISH, 4, "язь", 3); vn->Animal = Animal; c.mas[8] = vn;

	c.mas[9] = new node;
	NewInAnimal(Animal, FISH, 10, "пескарь", 4);
	c.mas[9]->Animal = Animal; c.mas[9]->next = NULL;
	vn = new node;
	vn->next = c.mas[9]; NewInAnimal(Animal, BIRD, 2, "дятел", 1); vn->Animal = Animal; c.mas[9] = vn;
}
void ExpectContainerOneBird(container &c)
{
	c.kol = 1;
	animal Animal;

	c.mas[0] = new node;
	NewInAnimal(Animal, BIRD, 2, "голубь", 0);	
	c.mas[0]->Animal = Animal; c.mas[0]->next = NULL;
}
void ExpectContainerOneFish(container &c)
{
	c.kol = 1;
	animal Animal;

	c.mas[3] = new node;
	NewInAnimal(Animal, FISH, 13, "лещ", 3);
	c.mas[3]->Animal = Animal; c.mas[3]->next = NULL;
}
void ExpectContainerOneBeast(container &c)
{
	c.kol = 1;
	animal Animal;

	c.mas[8] = new node;
	NewInAnimal(Animal, BEAST, 21, "человек", 2);
	c.mas[8]->Animal = Animal; c.mas[8]->next = NULL;
}
TEST_F(CContainerTest, CheckInit)
{
	container actual;
	Init(actual);
	container expect;
	EmptyContainer(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container init test was failed!!";
}
TEST_F(CContainerTest, CheckDel)
{
	container actual;
	Init(actual);
	ExpectContainer1(actual);
	Del(actual);
	container expect;
	EmptyContainer(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container(full) delete test was failed!!";
	Del(actual);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container(empty) delete test was failed!!";
}
TEST_F(CContainerTest, CheckIn) //
{
	ifstream f("In1.txt");
	container actual;
	Init(actual);
	In(actual, f);
	f.close();
	container expect;
	Init(expect);
	ExpectContainer1(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(10 elements) test was failed!!";
	Del(actual);
	Del(expect);
	
	ifstream f1("In2.txt");
	In(actual, f1);
	f1.close();
	ExpectContainer2(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(15 elements) test was failed!!";
	Del(actual);
	Del(expect);

	ifstream f2("InCBird.txt");
	In(actual, f2);
	f2.close();
	ExpectContainerOneBird(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(1 element: bird) test was failed!!";
	Del(actual);
	Del(expect);

	ifstream f3("InCFish.txt");
	In(actual, f3);
	f3.close();
	ExpectContainerOneFish(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(1 element: fish) test was failed!!";
	Del(actual);
	Del(expect);

	ifstream f4("InCBeast.txt");
	In(actual, f4);
	f4.close();
	ExpectContainerOneBeast(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(1 element: beast) test was failed!!";
	Del(actual);
	Del(expect);
}
TEST_F(CContainerTest, CheckOut) //
{
	container c;
	Init(c);
	ExpectContainer1(c);
	ofstream f("aOut1.txt");
	Out(c, f);
	Del(c);
	f.close();
	ifstream actual("aOut1.txt");
	ifstream expect("eOut1.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Container output(10 elements) test was failed!!";
	actual.close();
	expect.close();

	ExpectContainer2(c);
	ofstream f0("aOut2.txt");
	Out(c, f0);
	Del(c);
	f0.close();
	ifstream actual0("aOut2.txt");
	ifstream expect0("eOut2.txt");
	EXPECT_TRUE(FileCompare(actual0, expect0)) << "Container output(15 elements) test was failed!!";
	actual0.close();
	expect0.close();

	ExpectContainerOneBird(c);
	ofstream f1("aOutCBird.txt");
	Out(c, f1);
	f1.close();
	Del(c);
	ifstream actual1("aOutCBird.txt");
	ifstream expect1("eOutCBird.txt");
	EXPECT_TRUE(FileCompare(actual1, expect1)) << "Container output(1 element: Bird) test was failed!!";
	actual1.close();
	expect1.close();
	
	ExpectContainerOneFish(c);
	ofstream f2("aOutCFish.txt");
	Out(c, f2);
	f2.close();
	Del(c);
	ifstream actual2("aOutCFish.txt");
	ifstream expect2("eOutCFish.txt");
	EXPECT_TRUE(FileCompare(actual2, expect2)) << "Container output(1 element: Fish) test was failed!!";
	actual2.close();
	expect2.close();
	
	ExpectContainerOneBeast(c);
	ofstream f3("aOutCBeast.txt");
	Out(c, f3);
	f3.close();
	Del(c);
	ifstream actual3("aOutCBeast.txt");
	ifstream expect3("eOutCBeast.txt");
	EXPECT_TRUE(FileCompare(actual3, expect3)) << "Container output(1 element: Beast) test was failed!!";
	actual3.close();
	expect3.close();
}
TEST_F(CContainerTest, CheckSort) //
{
	container actual;
	container expect;
	Init(actual);
	ExpectContainer1(actual);
	Sort(actual);
	Init(expect);
	ExpectContainer1Sort(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(10 elements) test was failed!!";
	Sort(actual);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(10 elements, sorted) test was failed!!";
	Del(actual);
	Del(expect);

	ExpectContainer2(actual);
	Sort(actual);
	ExpectContainer2Sort(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(15 elements) test was failed!!";
	Sort(actual);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(15 elements, sorted) test was failed!!";
	Del(actual);
	Del(expect);

	ExpectContainer2Desort(actual);
	Sort(actual);
	ExpectContainer2Sort(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(15 elements, desorted) test was failed!!";
	Del(actual);
	Del(expect);

	ExpectContainerOneBird(actual);
	Sort(actual);
	ExpectContainerOneBird(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(1 element: Bird) test was failed!!";
	Del(actual);
	Del(expect);

	ExpectContainerOneFish(actual);
	Sort(actual);
	ExpectContainerOneFish(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(1 element: Fish) test was failed!!";
	Del(actual);
	Del(expect);

	ExpectContainerOneBeast(actual);
	Sort(actual);
	ExpectContainerOneBeast(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(1 element: Beast) test was failed!!";
	Del(actual);
	Del(expect);
}
TEST_F(CContainerTest, CheckOutOnlyFish) //
{	
	container c;
	Init(c);
	ExpectContainer1(c);
	ofstream f1("aOutOnlyFish1.txt");
	OutOnlyFish(c, f1);
	Del(c);
	f1.close();
	ifstream actual1("aOutOnlyFish1.txt");
	ifstream expect1("eOutOnlyFish1.txt");
	EXPECT_TRUE(FileCompare(actual1, expect1)) << "Container output(10 elements) test was failed!!";
	actual1.close();
	expect1.close();
		
	ExpectContainer2(c);
	ofstream f2("aOutOnlyFish2.txt");
	OutOnlyFish(c, f2);
	Del(c);
	f2.close();
	ifstream actual2("aOutOnlyFish2.txt");
	ifstream expect2("eOutOnlyFish2.txt");
	EXPECT_TRUE(FileCompare(actual2, expect2)) << "Container output(15 elements) test was failed!!";
	actual2.close();
	expect2.close();
}
TEST_F(CContainerTest, CheckSumElementsOfString) //
{
	container c;
	Init(c);
	animal Animal;
	Animal.name = "";
	EXPECT_TRUE(SumElementsOfString(Animal, c.n) == 0);
	Animal.name = "лещ";
	EXPECT_TRUE(SumElementsOfString(Animal, c.n) == 3);
	Animal.name = "клест";
	EXPECT_TRUE(SumElementsOfString(Animal, c.n) == 1);
	Animal.name = "человек";
	EXPECT_TRUE(SumElementsOfString(Animal, c.n) == 8);
	Animal.name = "кукушка";
	EXPECT_TRUE(SumElementsOfString(Animal, c.n) == 0);
	Animal.name = "тигр";
	EXPECT_TRUE(SumElementsOfString(Animal, c.n) == 1);
}
int main(int argc, char **argv) {
	setlocale(LC_ALL,"rus");
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}