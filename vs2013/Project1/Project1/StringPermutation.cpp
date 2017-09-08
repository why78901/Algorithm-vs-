#include "StringPermutation.h"
#include <iostream>
using namespace std;

StringPermutation::StringPermutation()
{
}


StringPermutation::~StringPermutation()
{
}

void StringPermutation::Init()
{
	int a[] = { 1, 2, 3 };
	int len = sizeof(a) / sizeof(int);
	Permutation(a, len, 0);
	cout << "\n"  << "nonRecursively";

	while (GetNextPermutation(a,len))
	{
		Print(a, len);
	}
}

void StringPermutation::Permutation(int a[], int size, int n)
{
	if (n==size-1)
	{
		Print(a, size);
		return;
	}

	for (int i = n; i < size; i++)
	{
		Swap(a, i, n);
		Permutation(a, size, n + 1);
		Swap(a, i, n);
	}
}



void StringPermutation::Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}



void StringPermutation::Print(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i];
	}
	cout << " ";
}


//nonRecursively
bool StringPermutation::GetNextPermutation(int *a, int size)
{
	//Кѓев
	int i = size - 2;
	while ((i>=0) && (a[i] >= a[i+1]))
	{
		i--;
	}
	if (i < 0)
		return false;

	int j = size - 1;
	while (a[j] <= a[i])
		j--;

	swap(a[j], a[i]);

	Reverse(a + i + 1, a + size - 1);
	return true;
}

void StringPermutation::Reverse(int *from, int *to)
{
	int t;
	while (from < to)
	{
		t = *from;
		*from = *to;
		*to = t;
		from++;
		to--;
	}
}
