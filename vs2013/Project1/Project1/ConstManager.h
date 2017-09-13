#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
class ConstManager
{
public:
	ConstManager();
	~ConstManager();
	static int arr[];
	int a[10] = { 0 , 50, 10, 90, 30, 70, 40, 80, 60, 20 };
};

