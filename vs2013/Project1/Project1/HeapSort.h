#pragma once
#include <iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
class HeapSort
{
public:
	HeapSort();
	~HeapSort();
	void OnInit();

private:
	int aLen;
	int SwapCount;
	void Pirnt(int a[],int len);
	void Swap(int a[], int s, int m);
	void Sort(int a[], int len);
	void Adjust(int a[], int len, int index);
};

