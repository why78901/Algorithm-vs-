#include "HalfFind.h"

HalfFind::HalfFind()
{
}


HalfFind::~HalfFind()
{
}

void HalfFind::OnInit()
{
	int sequence[] = { 10,20,30,40,54,60,80,90 };
	Find(sequence, sizeof(sequence) / sizeof(int), sequence[2]);
}

int HalfFind::Find(int a[], int len, int goal)
{
	int from = 0;
	int to = len - 1;
	int index;
	bool isFind = false;
	while (from <= to)
	{
		index = (from + to) / 2;
		if (a[index] == goal)
		{
			isFind = true;
			break;
		}

		if (a[index] > goal)
		{
			to = --index;
		}
		else
		{
			from = ++index;
		}
	}
	if (isFind)
	{
		std::cout << index;
		return index;
	}
	return -1;
}

void HalfFind::Pirnt(int a[])
{

}

