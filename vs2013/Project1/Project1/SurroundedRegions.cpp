#include "SurroundedRegions.h"



SurroundedRegions::SurroundedRegions()
{
}


SurroundedRegions::~SurroundedRegions()
{
}

void SurroundedRegions::OnInit()
{
	vector<vector<int> > land(M, vector<int>(N));
	int i, j;
	for (i = 0; i < M; i++)
	{
		for ( j = 0; j < N; j++)
		{
			land[i][j] == ((rand() % 3) == 0) ? WATER : SOIL;
		}
	}
	Print(land, M, N);
	FillLake(land, M, N);
	Print(land, M, N);
}

void SurroundedRegions::Ocean(vector<vector<int> >& land, int M, int N, int i, int j)
{
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	int iDirect[] = { -1, 1, 0, 0 };
	int jDirect[] = { 0, 0, -1, 1 };
	int iCur, jCur;
	int k;
	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		for ( k = 0; k < 4; k++)
		{
			iCur = i + iDirect[k];
			jCur = j + jDirect[k];
			if (IsOcean(land,M,N,iCur,jCur))
			{
				q.push(make_pair(iCur, jCur));
				land[iCur][jCur] = OCEAN;
			}
		}
	}
}

void SurroundedRegions::FillLake(vector<vector<int> >& land, int M, int N)
{
	int i, j;

	//从边缘开始,获得海洋区域
	for ( i = 0; i < M; i++)
	{
		if (land[i][0] == WATER)
		{
			Ocean(land, M, N, i, 0);
		}
		if (land[i][N-1] == WATER)
		{
			Ocean(land, M, N, i, N-1);
		}
	}
	for ( j = 0; j < N-1; j++)
	{
		if (land[0][j] == WATER)
		{
			Ocean(land, M, N, 0, j);
		}
		if (land[M-1][j] == WATER)
		{
			Ocean(land, M, N, M-1, j);
		}
	}

	for (i = 0; i < M; i++)
	{
		for ( j = 0; j < N; j++)
		{
			if (land[i][j] == OCEAN)
			{
				land[i][j] = WATER;
			}
			else if (land[i][j] == WATER)
			{
				land[i][j] = SOIL;
			}
		}
	}

}


void SurroundedRegions::Print(vector<vector<int> >& land, int M, int N)
{

}