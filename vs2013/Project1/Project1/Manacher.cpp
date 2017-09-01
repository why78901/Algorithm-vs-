#include "Manacher.h"
#include "string.h"
#include <iostream>
using namespace std;


Manacher::Manacher()
{
}


Manacher::~Manacher()
{
}

void Manacher::Init()
{
	char str[] = "fesabcecba";
	int p[20];
	GetManacher(str, p);
	for (int i = 0; i < 20; i++)
	{
		if (p[i] > 0)
		{
			cout << p[i];
		}	
	}
}

int Manacher::min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	return a;
}

void Manacher::GetManacher(char str[], int p[])
{
	int size = strlen(str);
	p[0] = 1;
	int id = 0;
	int mx = 1;
	for (int i = 1; i < size;i++)
	{
		if (mx > i)
		{
			p[i] = min(p[2 * id - i], mx - i);
		}
		else
		{
			p[i] = 1;
		}
		for (; str[i + p[i]] == str[i-p[i]]; p[i]++);
		
		if (mx < i+p[i])
		{
			mx = i + p[i];
			id = i;
		}
	}
}


