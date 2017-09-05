#include "HeapSort.h"

HeapSort::HeapSort():
	SwapCount(0)
{
}


HeapSort::~HeapSort()
{
}

void HeapSort::OnInit()
{
	int a[] = { 0 , 50, 10, 90, 30, 70, 40, 80, 60, 20 ,15, 25,55,85,45,75,65,16,86,56,36,46,96,26 };
	aLen = sizeof(a) / sizeof(int);
	Sort(a, aLen);
	cout << "ArrLen" << aLen << "  HeapSortSwapCount" << SwapCount << "\n";
}

void HeapSort::Sort(int a[], int len)
{
	for (int i = len/2 -1; i >= 0; i--)
	{
		Adjust(a, len, i);
	}
	for (int i = len-1; i >=1;i--)
	{
		Swap(a, 0, i);
		Adjust(a, i, 0);
	}
}

void HeapSort::Adjust(int a[], int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if (left<len && a[left] > a[maxIdx]) maxIdx = left;
	if (right<len && a[right] > a[maxIdx]) maxIdx = right;  // maxIdx是3个数中最大数的下标
	if (maxIdx != index)                 // 如果maxIdx的值有更新
	{
		Swap(a, maxIdx, index);
		Adjust(a, len, maxIdx);       // 递归调整其他不满足堆性质的部分
	}
}

void HeapSort::Swap(int a[], int s, int m)
{
	int temp = a[m];
	a[m] = a[s];
	a[s] = temp;
	SwapCount++;
	Pirnt(a, aLen);
}

void HeapSort::Pirnt(int a[], int len)
{
	return;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}