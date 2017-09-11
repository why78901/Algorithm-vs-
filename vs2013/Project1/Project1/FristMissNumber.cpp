#include "FristMissNumber.h"



FristMissNumber::FristMissNumber()
{
}


FristMissNumber::~FristMissNumber()
{
}

void FristMissNumber::OnInit()
{

}

int FristMissNumber::FindNumber(int a[],int length)
{
	a--;
	int i = 1;
	while (i<=length)
	{
		if (a[i] == i)
		{
			i++;
		}
		else if ((a[i] < i) || (a[i] > length) || (a[i] == a[a[i]]))
		{
			a[i] = a[length];
			length--;
		}
		else
		{
			//swap(a[a[i]], a[i]);
		}
	}
	return i;
}