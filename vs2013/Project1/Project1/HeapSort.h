#pragma once
#include <iostream>
using namespace std;
class HeapSort
{
public:
	HeapSort();
	~HeapSort();
	void OnInit();

private:
	int aLen;
	void Sort(int a[], int len);
	void Pirnt(int a[],int len);
	void Swap(int a[], int s, int m);
	void Adjust(int a[], int s, int m);
};

