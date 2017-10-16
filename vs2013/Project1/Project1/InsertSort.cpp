#include "InsertSort.h"



InsertSort::InsertSort()
{
}


InsertSort::~InsertSort()
{
}

void InsertSort::OnInit()
{

}

void InsertSort::Sort(int a[])
{
	int len = sizeof(a) / sizeof(int);
	int i, j;
	for (i = 1; i < len; i++)
		for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
			swap(a[j], a[j + 1]);
}


