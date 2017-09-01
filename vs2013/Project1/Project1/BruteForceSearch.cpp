#include "BruteForceSearch.h"
#include <iostream>
using namespace std;

BruteForceSearch::BruteForceSearch()
{
}


BruteForceSearch::~BruteForceSearch()
{
}

void BruteForceSearch::Init()
{
	char s[] = "abababababcde";
	char p[] = "ababcde";
	int pos = ForceSearch(s, p);
	cout << pos;
}

//查找s中首次出现p的位置
int BruteForceSearch::ForceSearch(char s[], char p[])
{
	int i = 0;
	int j = 0;
	int size = strlen(p);
	int nLast = strlen(s) - size;
	while (i<=nLast && j<size)
	{
		if (s[i+j] == p[j])
		{
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}

	if (j >= size)
	{
		return i;
	}
	return -1;
}