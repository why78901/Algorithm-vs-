#include "LocalMaximum.h"



LocalMaximum::LocalMaximum()
{
}


LocalMaximum::~LocalMaximum()
{
}

void LocalMaximum::OnInit()
{

}

int LocalMaximum::Maximum(int a[], int length)
{
	int left = 0;
	int right = length - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		std::cout << mid;
		if (a[mid] > a[mid + 1])
			right = mid;
		else
		{
			left = mid + 1;
		}
	}
	return a[left];
}