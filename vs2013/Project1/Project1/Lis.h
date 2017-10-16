#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//最长递增子序列
class Lis
{
public:
	Lis();
	~Lis();
	void OnInit();

private:
	//最长递增子序列长度
	int Lis1(const int* p, int length);
	//最长递增子序列
	int Lis2(const int* p, int length, int* pre, int &pIndex);
	void GetLis(const int* array, const int* pre, int index, vector<int>& lis);
	//nlogn时间复杂度的实现方式
	int Lis3(const int* a, int size);
	void Insert(int* a, int &size, int x);
	int Max(int left, int right);
};

