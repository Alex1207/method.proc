#include "stdafx.h"
#include "container.h"
#include "animal.h"
#include "iostream"
#include "foolproof.h"
#include <fstream>

using namespace std;
void Init(container &Cont)
{
	Cont.kol = 0;
	Cont.n = 10;
	Cont.mas = new node*[Cont.n];
	for (int i = 0; i < Cont.n; i++)
	{
		Cont.mas[i] = NULL;
	}
}
void Del(container &Cont)
{
	for (int i = 0; i < Cont.n; i++)
	{
		while (Cont.mas[i] != NULL)
		{
			node* Node = Cont.mas[i]->next;
			delete Cont.mas[i];
			Cont.mas[i] = Node;
		}
	}
	Cont.kol = 0;
}
void In(container &Cont, ifstream & InFile)
{	
	CheckFileExist(InFile);
	CheckEmptyFile(InFile);
	int Kol;
	InFile >> Kol;
	CheckInputValue(InFile);	
	if (Kol<0) 	
	{
		cout << "Неверные данные во входном файле(Количество животных не может быть отрицательным)!\n";
		system("pause");
		exit(1);
	}
	Cont.kol = Kol;
	for (int i = 0; i < Cont.kol; i++)
	{
		animal Animal;
		//int a = InAnimal(Animal, f1);
		Animal = InAnimal(InFile);//InAnimal(Animal, f1);
		int Sum = 0;
		Sum = SumElementsOfString(Animal, Cont.n);
		if (Cont.mas[Sum] == NULL)
		{
			Cont.mas[Sum] = new node;
			Cont.mas[Sum]->next = NULL;
			Cont.mas[Sum]->nAnimal = Animal;
		}
		else
		{
			node* Node = new node;
			Node->next = Cont.mas[Sum];
			Node->nAnimal = Animal;
			Cont.mas[Sum] = Node;
		}
	}	
	if(!InFile.eof())
	{
		cout << "После считанных данных в файле есть что-то еще. Эта информация обрабатываться не будет\n";
	}
}
void Out(container Cont, ofstream &OutFile)
{
	//cout << "Общее количество: " << c.kol << "\n";
	OutFile << "Общее количество: " << Cont.kol << "\n";
	for (int i = 0; i < Cont.n; i++)
	{
		//cout << "\n" << i << "\n";
		OutFile << "\n" << i << "\n";
		if (Cont.mas[i] != NULL)
		{
			node* Node = Cont.mas[i];
			while (Node)
			{
				OutAnimal(Node->nAnimal, OutFile);
				Node = Node->next;
			}
		}
	}
}
void Sort(container &Cont)
{
	for (int k = 0; k < Cont.n; k++)
	{
		int Koli = 0;
		node* Prev;
		node* Node = Cont.mas[k];
		while(Node)
		{
			Node = Node->next;
			Koli++;
		}
		for(int i = 0; i < Koli - 1; i++) 
		{
			node* Prev;
			Node = Cont.mas[k];
			for(int j = i + 1; j < Koli; j++) 
			{
				if(Less(Node->nAnimal, Node->next->nAnimal))
				{
					node* Next = Node->next;
					Node->next = Node->next->next;
					Next->next = Node;
					if(Node == Cont.mas[k])
					{
						Cont.mas[k] = Next;
						Prev = Next;
					}
					else
					{
						Prev->next = Next;
						Prev = Next;
					}
				}
				else 
				{
					Prev = Node;
					Node = Node->next;
				}
			}
		}
	}
}
void OutOnlyFish(container Cont, ofstream & OutFile)
{
	//cout << "\nТолько рыбки:\n";
	OutFile << "\nТолько рыбки:\n";
	for (int i = 0; i < Cont.n; i++)
	{
		//cout << "\n" << i << "\n";
		if (Cont.mas[i] != NULL)
		{
			node* Node = Cont.mas[i];
			while (Node)
			{
				if (Node->nAnimal.key == FISH)
					OutAnimal(Node->nAnimal, OutFile);
				else
				{
					//cout << endl;
					OutFile << endl;
				}
				Node = Node->next;
			}
		}
	}
}
int SumElementsOfString(animal Animal, int N)
{
	string Str = Animal.name;
	int Sum = 0;
	for (int i = 0; i < Str.length(); i++)
	{
		Sum = (Sum + (unsigned char)Str[i])%N;
	}
	return Sum;
}
void MultiMethod(container Cont, ofstream &OutFile)
{
	//cout << "Мультиметод: " << endl;
	OutFile << "Мультиметод: " << endl;
	int k = 0;
	for (int i = 0; i<Cont.n; i++)
	{
		//cout << "\n" << i << "\n";
		if (Cont.mas[i] != NULL)
		{
			node* Node1 = Cont.mas[i];
			while (Node1)
			{
				for (int j = i; j<Cont.n; j++)
				{
					node* Node2;
					if (j==i)
						Node2 = Node1->next;
					else
						Node2 = Cont.mas[j];
					//cout << "\n" << i << "\n";
					if (Cont.mas[j] != NULL)
					{
						//vn2 = c.mas[j];
						while (Node2)
						{
							switch(Node1->nAnimal.key)
							{
							case BIRD:
								{
									switch(Node2->nAnimal.key)
									{
									case BIRD:
										{
											k++;
											//cout << "\nПтичка и птичка." << endl;
											OutFile << "\nПтичка и птичка." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									case FISH:
										{
											k++;
											//cout << "\nПтичка и рыбка." << endl;
											OutFile << "\nПтичка и рыбка." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									case BEAST:
										{
											k++;
											//cout << "\nПтичка и звёр." << endl;
											OutFile << "\nПтичка и звёр." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									default:
										{
											k++;
											//cout << "\nНеизвестный тип" << endl;
											OutFile << "\nНеизвестный тип" << endl;
										}
									}
									break;
								}
							case FISH:
								{
									switch(Node2->nAnimal.key)
									{
									case BIRD:
										{
											k++;
											//cout << "\nРыбка и птичка." << endl;
											OutFile << "\nРыбка и птичка." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									case FISH:
										{
											k++;
											//cout << "\nРыбка и рыбка." << endl;
											OutFile << "\nРыбка и рыбка." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									case  BEAST:
										{
											k++;
											//cout << "\nРыбка и звёр." << endl;
											OutFile << "\nРыбка и звёр." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									default:
										{
											k++;
											//cout << "\nНеизвестный тип" << endl;
											OutFile << "\nНеизвестный тип" << endl;
										}
									}
									break;
								}
							case BEAST:
								{
									switch(Node2->nAnimal.key)
									{
									case BIRD:
										{
											k++;
											//cout << "\nЗвёр и птичка." << endl;
											OutFile << "\nЗвёр и птичка." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									case FISH:
										{
											k++;
											//cout << "\nЗвёр и рыбка." << endl;
											OutFile << "\nЗвёр и рыбка." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									case  BEAST:
										{
											k++;
											//cout << "\nЗвёр и звёр." << endl;
											OutFile << "\nЗвёр и звёр." << endl;
											OutAnimal(Node1->nAnimal, OutFile);
											OutAnimal(Node2->nAnimal, OutFile);
											break;
										}
									default:
										{
											k++;
											//cout << "\nНеизвестный тип" << endl;
											OutFile << "\nНеизвестный тип" << endl;
										}
									}
									break;
								}
							default:
								{
									//cout << "\nНеизвестный тип" << endl;
									OutFile << "\nНеизвестный тип" << endl;
								}
							}
							Node2 = Node2->next;
						}
					}
				}
				Node1 = Node1->next;
			}
		}
	}
	//cout << k;
}