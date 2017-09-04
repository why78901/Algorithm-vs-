#pragma once
#include <iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
class QuickSort
{
public:
	QuickSort();
	~QuickSort();
	void OnInit();
	int Partition(int a[], int low, int high);
	void quickSort(int a[], int low, int high);
	void Swap(int a[], int s, int m);
	void Pirnt(int a[], int len);

private:
	int aLen;
	int SwapCount;
};

