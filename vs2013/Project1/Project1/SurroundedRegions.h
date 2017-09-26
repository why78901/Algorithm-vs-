#pragma once
//XXXXX
//XXXOX
//XOOXX
//XXXOX
//将完全被X包围的O替换为X
//周围区域问题
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int M = 10;
const int N = 10;
#define WATER 1
#define OCEAN 2
#define SOIL 3
class SurroundedRegions
{
public:
	SurroundedRegions();
	~SurroundedRegions();
	void OnInit();

private:
	void Ocean(vector<vector<int> >&land, int M, int N, int i, int j);
	inline bool IsOcean(vector<vector<int> >& land, int M, int N, int i, int j)
	{
		if ((i<0) || (i>=M) || (j<0) || (j>=N))
		{
			return false;
		}
		return land[i][j] = WATER;
	}
	void FillLake(vector<vector<int> >& land, int M, int N);

	void Print(vector<vector<int> >& land, int M, int N);
};

