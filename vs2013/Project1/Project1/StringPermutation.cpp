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
	Permutation(a, sizeof(a) / sizeof(int), 0);
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