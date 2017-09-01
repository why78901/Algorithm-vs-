#pragma once
#include "string.h"
using namespace std;
class KMPMatch
{
public:
	KMPMatch();
	~KMPMatch();
	void Init();
	void GetNext(char p[], int next[]);
	int KMP(char S[], char T[], int n);
	void get_next(char str[], int next[]);
	int Index_KMP(char S[], char T[], int pos);
};

