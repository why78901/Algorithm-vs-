#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//��С·��
class MinPath
{
public:
	MinPath();
	~MinPath();
	int CMinPath(vector<vector<int> >& chess, int M, int N);
};

