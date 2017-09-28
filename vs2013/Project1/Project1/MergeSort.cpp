#include "MergeSort.h"



MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::CMergeSort(int *a, int low, int high)
{
	if (low >= high )
	{
		return;
	}

	int mid = (low + high) / 2;
	CMergeSort(a, low, mid);
	CMergeSort(a, mid + 1, high);
	Merge(a, low, mid, high);
}

void MergeSort::Merge(int *a, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int size = 0;
	for ( ;(i <= mid) && (j <= high); size++)
	{
		if (a[i] < a[j])
		{
			temp[size] = a[i++];
		}
		else
		{
			temp[size] = a[j++];
		}
	}

	while (i <= mid)
	{
		temp[size++] = a[i++];
	}

	while (j <= high)
	{
		temp[size++] = a[j++];
	}

	for ( i = 0; i < size; i++)
	{
		a[low + i] = temp[i];
	}
}