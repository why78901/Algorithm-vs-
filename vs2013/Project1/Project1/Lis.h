#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//�����������
class Lis
{
public:
	Lis();
	~Lis();
	void OnInit();

private:
	//����������г���
	int Lis1(const int* p, int length);
	//�����������
	int Lis2(const int* p, int length, int* pre, int &pIndex);
	void GetLis(const int* array, const int* pre, int index, vector<int>& lis);
	//nlognʱ�临�Ӷȵ�ʵ�ַ�ʽ
	int Lis3(const int* a, int size);
	void Insert(int* a, int &size, int x);
	int Max(int left, int right);
};

