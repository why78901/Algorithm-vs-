#include "Lis.h"



Lis::Lis()
{
}


Lis::~Lis()
{
}

void Lis::OnInit()
{

}

int Lis::Lis1(const int* p, int length)
{
	int *longest = new int[length];
	int i, j;

	for ( i = 0; i < length; i++)
	{
		longest[i] = 1;
	}

	int nLis = 1;
	for ( i = 1; i < length; i++)
	{
		for ( j = 0; j < i; j++)
		{
			if (p[j] <= p[i])
			{
				longest[i] = Max(longest[i], longest[j] + 1);
			}
		}
		nLis = Max(nLis, longest[i]);
	}
	return nLis;
}

int Lis::Lis2(const int* p, int length, int* pre, int &pIndex)
{
	int *longest = new int[length];
	int i, j;

	for (i = 0; i < length; i++)
	{
		longest[i] = 1;
		pre[i] = -1;
	}

	int nLis = 1;
	for (i = 1; i < length; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (p[j] <= p[i])
			{
				if (longest[i] <= longest[j] + 1)
				{
					longest[i] = longest[j] + 1;
					pre[i] = j;
				}
			}
		}

		if (nLis < longest[i])
		{
			nLis = longest[i];
			pIndex = i;
		}
	}
	return nLis;
}

void Lis::GetLis(const int* array, const int* pre, int index, vector<int>& lis)
{
	while (index >= 0)
	{
		lis.push_back(array[index]);
		index = pre[index];
	}
	reverse(lis.begin(), lis.end());
}

int Lis::Lis3(const int* a, int size)
{
	int* b = new int[size];
	int s = 0;
	int i;
	for ( i = 0; i < size; i++)
	{
		Insert(b, s, a[i]);
	}
	return s;
}

void Lis::Insert(int* a, int &size, int x)
{
	if (size <= 0)
	{
		a[0] = x;
		size++;
		return;
	}

	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < a[mid])
			high = mid - 1;
		else if (x >= a[mid])
			low = mid + 1;
	}

	if (low >= size)
	{
		a[size] = x;
		size++;
	}
	else
	{
		if (a[low] < x)
			a[low + 1] = x;
		else
			a[low] = x;
	}
}


int Lis::Max(int left, int right)
{
	return left > right ? left : right;
}
