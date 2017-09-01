#pragma once
class StringPermutation
{
public:
	StringPermutation();
	~StringPermutation();
	void Init();

private:
	void Permutation(int a[], int size, int n);
	void Print(int a[], int size);
	void Swap(int a[], int i, int j);
};

