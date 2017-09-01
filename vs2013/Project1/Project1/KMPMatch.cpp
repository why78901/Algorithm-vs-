#include "KMPMatch.h"
#include <iostream>
using namespace std;

KMPMatch::KMPMatch()
{
}


KMPMatch::~KMPMatch()
{
}

void KMPMatch::Init()
{
	char s[] = "abababbabcdefff"; 
	char t[] = "abcde";
	Index_KMP(s, t, 0);
}

void KMPMatch::GetNext(char p[], int next[])
{
	int nLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < nLen -1)
	{
		//k即next[j-1],且p[k]表示前缀，p[j]表示后缀
		if (k==-1 || p[j] == p[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMPMatch::KMP(char S[], char T[], int n)
{
	int ans = -1;
	int i = 0;
	int j = 0;
	int tlen = strlen(T);
	while (i < n)
	{
		/*if (j==-1 || S[i] == T)
		{
		}
		*/
	}
	return 0;
}

void KMPMatch::get_next(char str[], int next[])
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < strlen(str))
	{
		if (j==0 || str[i] == str[j])
		{
			++i;
			++j;
			if (str[i] != str[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}
		}
		else
		{
			j = next[j];
		}
	}
}




int KMPMatch::Index_KMP(char S[], char T[], int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	GetNext(T, next);
	while (i<=strlen(S) && j<=strlen(T))
	{
		if (j== 0 || S[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

	int posX = i - j;
	cout << posX;

	if (j > strlen(T))
	{
		return i - strlen(T);
	}
	
	return 0;
}