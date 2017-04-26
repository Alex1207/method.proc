#include "stdafx.h"
#include "container.h"
#include "animal.h"
#include "iostream"
#include <fstream>

using namespace std;
void Init(container &c)
{
	c.kol = 0;
	c.n = 10;
	c.mas = new node*[c.n];
	for (int i = 0; i < c.n; i++)
	{
		c.mas[i] = NULL;
	}
}
void Del(container &c)
{
	for (int i = 0; i<c.n; i++)
	{
		while (c.mas[i] != NULL)
		{
			node* vn = c.mas[i]->next;
			delete c.mas[i];
			c.mas[i] = vn;
		}
	}
}
void In(container &c, ifstream & f1)
{	
	f1 >> c.kol;
	for (int i = 0; i<c.kol; i++)
	{
		animal Animal;
		Animal = InAnimal(f1);
		int sum = 0;
		sum = SumElementsOfString(Animal, c.n);
		if (c.mas[sum] == NULL)
		{
			c.mas[sum] = new node;
			c.mas[sum]->next = NULL;
			c.mas[sum]->Animal = Animal;
		}
		else
		{
			node* vn = new node;
			vn->next = c.mas[sum];
			vn->Animal = Animal;
			c.mas[sum] = vn;
		}
	}	
}
void Out(container c, ofstream & f2)
{
	cout << "Общее количество: " << c.kol << endl;
	f2 << "Общее количество: " << c.kol << endl;
	for (int i = 0; i<c.n; i++)
	{
		//cout << "\n" << i << "\n";
		if (c.mas[i] != NULL)
		{
			node* vn = c.mas[i];
			while (vn)
			{
				OutAnimal(vn->Animal, f2);
				vn = vn->next;
			}
		}
	}
}
void MultiMethod(container c, ofstream & f2)
{
	cout << "Мультиметод: " << endl;
	f2 << "Мультиметод: " << endl;
	int k = 0;
	for (int i = 0; i<c.n; i++)
	{
		//cout << "\n" << i << "\n";
		if (c.mas[i] != NULL)
		{
			node* vn1 = c.mas[i];
			while (vn1)
			{
				for (int j = i; j<c.n; j++)
				{
					node* vn2;
					if (j==i)
						vn2 = vn1->next;
					else
						vn2 = c.mas[j];
					//cout << "\n" << i << "\n";
					if (c.mas[j] != NULL)
					{
						//vn2 = c.mas[j];
						while (vn2)
						{
							switch(vn1->Animal.key)
							{
							case BIRD:
								{
									switch(vn2->Animal.key)
									{
									case BIRD:
										{
											k++;
											cout << "\nПтичка и птичка." << endl;
											f2 << "\nПтичка и птичка." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									case FISH:
										{
											k++;
											cout << "\nПтичка и рыбка." << endl;
											f2 << "\nПтичка и рыбка." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									default:
										{
											k++;
											cout << "\nНеизвестный тип" << endl;
											f2 << "\nНеизвестный тип" << endl;
										}
									}
									break;
								}
							case FISH:
								{
									switch(vn2->Animal.key)
									{
									case BIRD:
										{
											k++;
											cout << "\nРыбка и птичка." << endl;
											f2 << "\nРыбка и птичка." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									case FISH:
										{
											k++;
											cout << "\nРыбка и рыбка." << endl;
											f2 << "\nРыбка и рыбка." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									default:
										{
											k++;
											cout << "\nНеизвестный тип" << endl;
											f2 << "\nНеизвестный тип" << endl;
										}
									}
									break;
								}
							default:
								{
									cout << "\nНеизвестный тип" << endl;
									f2 << "\nНеизвестный тип" << endl;
								}
							}
							vn2 = vn2->next;
						}
					}
				}
				vn1 = vn1->next;

			}
		}
	}
	//cout << k;
}