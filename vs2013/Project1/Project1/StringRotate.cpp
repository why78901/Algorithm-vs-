#include "StringRotate.h"
#include <string>
#include <iostream>
using namespace std;

StringRotate::StringRotate()
{
}


StringRotate::~StringRotate()
{
}

void StringRotate::Init()
{
	char s[] = "abcdef";
	LeftRotateString(s, strlen(s), 2);
}


void StringRotate::LeftRotateString(char s[], int n, int m)
{
	ReverseString(s, 0, m-1);
	ReverseString(s, m, n-1);
	ReverseString(s, 0, n-1);
	cout << s;
}

void StringRotate::ReverseString(char s[], int form, int to)
{
	while (form < to)
	{
		char t = s[form];
		s[form++] = s[to];
		s[to--] = t;
	}
}