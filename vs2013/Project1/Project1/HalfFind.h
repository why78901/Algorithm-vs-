#pragma once
#include <iostream>
class HalfFind
{
public:
	HalfFind();
	~HalfFind();
	void OnInit();
private:
	int Find(int a[],int len, int goal);
	void Pirnt(int a[]);
};

