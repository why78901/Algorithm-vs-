#include "MinPath.h"



MinPath::MinPath()
{
}


MinPath::~MinPath()
{
}

int MinPath::CMinPath(vector<vector<int> >& chess, int M, int N)
{
	vector<int> pathLength(N);
	int i, j;

	//初始化
	pathLength[0] = chess[0][0];
	for (j = 0; j < N; j++)
	{
		pathLength[j] = pathLength[j - 1] + chess[0][j];
	}

	//依次计算每行
	for ( i = 0; i < M; i++)
	{
		pathLength[0] += chess[i][0];
		for ( j = 0; j < N; j++)
		{
			if (pathLength[j-1] < pathLength[j])
			{
				pathLength[j] = pathLength[j - 1] + chess[i][j];
			}
			else
			{
				pathLength[j] += chess[i][j];
			}
		}
	}
	return pathLength[N - 1];
}
