#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

struct EXPGOODS
{
	char prodname[25];
	char expcountr[25];
	int quantiti;
};

void inputfile(FILE*);
void addtofile(FILE*);
void prodnamch(FILE*);
void countrnamch(FILE*);
void quanttch(FILE*);
void editfile(FILE*);
void outputfile(FILE*);
void prodstat(FILE*);