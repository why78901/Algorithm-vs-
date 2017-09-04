#include "HeapSort.h"

HeapSort::HeapSort()
{
}


HeapSort::~HeapSort()
{
}

void HeapSort::OnInit()
{
	int a[] = {0 , 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	aLen = sizeof(a) / sizeof(int);
	Sort(a,aLen);
}

void HeapSort::Sort(int a[],int len)
{
	int i;
	for (i = len / 2; i > 0;i--)
	{
		Adjust(a, i, len);
	}

	for (i = len; i > 1;i--)
	{
		Swap(a, 0, i-1);
		Adjust(a, 1, i - 1);
	}
}

void HeapSort::Swap(int a[], int s, int m)
{
	int temp = a[m];
	a[m] = a[s];
	a[s] = temp;
}

void HeapSort::Adjust(int a[], int s, int m)
{
	int temp;
	int j;
	temp = a[s];
	for (j = 2 * s; j < m;j*=2)
	{
		if (j<m && a[j] < a[j + 1])
		{
			++j;
		}
		if (temp >= a[j])
		{
			break;
		}
		a[s] = a[j];
		s = j;
	}
	a[s] = temp;
	Pirnt(a, aLen);
}

void HeapSort::Pirnt(int a[], int len)
{
	for (int i = 0; i < len;i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}