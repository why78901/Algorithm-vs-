#include "AbsoluteMode.h"

AbsoluteMode::AbsoluteMode()
{
}


AbsoluteMode::~AbsoluteMode()
{
}

void AbsoluteMode::OnInit()
{
	int a[] = { 1,2,1,3,1,4,1 };
	ModeNTwo(a, sizeof(a) / sizeof(int));
}

int AbsoluteMode::ModeNTwo(int a[], int size)
{
	int count = 0;
	int m = a[0];
	for (int i = 0; i < size; i++)
	{
		if (count == 0)
		{
			m = a[i];
			count = 1;
		}
		else if(m != a[i])
		{
			count--;
		}
		else
		{
			count++;
		}
	}
	cout << m;
	return m;
}

void AbsoluteMode::ModeNThree(int a[], int length)
{
	int m, n;
	int cm = 0, cn = 0;
	int i;
	//选出出现最多的m,n
	for (i = 0; i < length; i++)
	{
		if (cm == 0)
		{
			m = a[i]; cm = 1;
		}
		else if(cn == 0)
		{
			n = a[i]; cn = 1;
		}
		else if (a[i] == m)
		{
			cm++;
		}
		else if(a[i] == n)
		{
			cn++;
		}
		else
		{
			cm--;
			cn--;
		}
	}

	cm = cn = 0;
	for (i = 0; i < length; i++)
	{
		if (a[i] == m)
			cm++;
		else if(a[i] == n)
		{
			cn++;
		}
	}

	if (cm > length/3)
	{
		cout << cm;
	}

	if (cn > length / 3)
	{
		cout << cn;
	}

}
