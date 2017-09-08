#pragma once
#include<cstring>
#include<algorithm>
#include<cstdio>
class StringPermutation
{
public:
	StringPermutation();
	~StringPermutation();
	void Init();

private:
	//Recursively
	void Permutation(int a[], int size, int n);
	void Print(int a[], int size);
	void Swap(int a[], int i, int j);


	//NonRecursively
	void Reverse(int *from, int *to);
	bool GetNextPermutation(int *a, int size);
};

