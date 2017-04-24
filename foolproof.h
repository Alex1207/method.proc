#include "stdafx.h"
#include "iostream"
#include <fstream>
using namespace std;
#ifndef __foolproof__ 
#define __foolproof__
void CheckFileExist(ifstream &File);
void CheckEmptyFile(ifstream &File);
void CheckFileEnd(ifstream &File);
void CheckInputValue(ifstream &File);
#endif
