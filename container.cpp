#include "stdafx.h"
#include "container.h"
#include "animal.h"
#include "iostream"
#include "foolproof.h"
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
	for (int i = 0; i < c.n; i++)
	{
		while (c.mas[i] != NULL)
		{
			node* vn = c.mas[i]->next;
			delete c.mas[i];
			c.mas[i] = vn;
		}
	}
	c.kol = 0;
}
void In(container &c, ifstream & f1)
{	
	CheckFileExist(f1);
	CheckEmptyFile(f1);
	int kol;
	f1 >> kol;
	CheckInputValue(f1);	
	if (kol<0) 	
	{
		cout << "�������� ������ �� ������� �����(���������� �������� �� ����� ���� �������������)!\n";
		system("pause");
		exit(1);
	}
	c.kol = kol;
	for (int i = 0; i < c.kol; i++)
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
	if(!f1.eof())
	{
		cout << "����� ��������� ������ � ����� ���� ���-�� ���. ��� ���������� �������������� �� �����\n";
	}
}
void Out(container c, ofstream & f2)
{
	//cout << "����� ����������: " << c.kol << "\n";
	f2 << "����� ����������: " << c.kol << "\n";
	for (int i = 0; i < c.n; i++)
	{
		//cout << "\n" << i << "\n";
		f2 << "\n" << i << "\n";
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
void Sort(container &c)
{
	for (int k = 0; k < c.n; k++)
	{
		int koli = 0;
		node* prev;
		node* Node = c.mas[k];
		while(Node)
		{
			Node = Node->next;
			koli++;
		}
		for(int i = 0; i < koli - 1; i++) 
		{
			node* prev;
			Node = c.mas[k];
			for(int j = i + 1; j < koli; j++) 
			{
				if(Less(Node->Animal, Node->next->Animal))
				{
					node* next = Node->next;
					Node->next = Node->next->next;
					next->next = Node;
					if(Node == c.mas[k])
					{
						c.mas[k] = next;
						prev = next;
					}
					else
					{
						prev->next = next;
						prev = next;
					}
				}
				else 
				{
					prev = Node;
					Node = Node->next;
				}
			}
		}
	}
}
void OutOnlyFish(container c, ofstream & f2)
{
	//cout << "\n������ �����:\n";
	f2 << "\n������ �����:\n";
	for (int i = 0; i < c.n; i++)
	{
		//cout << "\n" << i << "\n";
		if (c.mas[i] != NULL)
		{
			node* vn = c.mas[i];
			while (vn)
			{
				if (vn->Animal.key == FISH)
					OutAnimal(vn->Animal, f2);
				else
				{
					//cout << endl;
					f2 << endl;
				}
				vn = vn->next;
			}
		}
	}
}
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