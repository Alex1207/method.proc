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
	cout << "����� ����������: " << c.kol << endl;
	f2 << "����� ����������: " << c.kol << endl;
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
	cout << "�����������: " << endl;
	f2 << "�����������: " << endl;
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
											cout << "\n������ � ������." << endl;
											f2 << "\n������ � ������." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									case FISH:
										{
											k++;
											cout << "\n������ � �����." << endl;
											f2 << "\n������ � �����." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									default:
										{
											k++;
											cout << "\n����������� ���" << endl;
											f2 << "\n����������� ���" << endl;
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
											cout << "\n����� � ������." << endl;
											f2 << "\n����� � ������." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									case FISH:
										{
											k++;
											cout << "\n����� � �����." << endl;
											f2 << "\n����� � �����." << endl;
											OutAnimal(vn1->Animal, f2);
											OutAnimal(vn2->Animal, f2);
											break;
										}
									default:
										{
											k++;
											cout << "\n����������� ���" << endl;
											f2 << "\n����������� ���" << endl;
										}
									}
									break;
								}
							default:
								{
									cout << "\n����������� ���" << endl;
									f2 << "\n����������� ���" << endl;
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